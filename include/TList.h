#pragma once
#include "TListNode.h"

template<class T>
class TList {
	protected:
		TListNode<T>* begin;
		TListNode<T>* end;
		int count;	
	public:
		TList();
		TList(const TList<T>& p);
		TList(TList<T>&& p);
		~TList();
		void PushBegin(TListNode<T>* a);
		void PushEnd(TListNode<T>* a);
		void DeleteBegin();
		void DeleteEnd();
		TListNode<T>* GetBegin();
		TListNode<T>* GetEnd();
		TList<T>& operator=(const TList<T>& p);
};

template<class T>
TList<T>::TList<T>::TList(){
	begin = nullptr;
	end = nullptr;
	count = 0;
}

template <class T>
TList<T>::TList(const TList<T>& p) {
	count = p.count;
	if (p.begin != nullptr) {
		begin = new TListNode<T>(*p.begin);
		TListNode<T>* temp = begin;
		TListNode<T>* temp2 = p.begin->GetNext();

		while (temp2 != p.begin) {
			TListNode<T>* newNode = new TListNode<T>();
			newNode->SetPrev(temp);
			newNode->SetData(new T(*temp2->GetData()));
			temp->SetNext(newNode);
			temp = temp->GetNext();
			temp2 = temp2->GetNext();

			if (temp2 == p.begin) {
				break; 
			}
		}

		end = temp;
	}
	else {
		begin = nullptr;
		end = nullptr;
	}
}

template<class T>
TList<T>::TList<T>::TList(TList<T>&& p) {
	data = std::move(p.data);
	begin = p.begin;
	end = p.end;
	count - p.count;
	p.begin = nullptr;
	p.end = nullptr;
	count = 0;
}

template<class T>
TList<T>::void TList<T>::PushBegin(TListNode<T>* q) {
	TListNode<T>* a = new TListNode(begin, end, q)
	begin = c;
}

template<class T>
TList<T>::TList<T>::~TList() {
	begin = nullptr;
	end = nullptr;
	count = 0;
}

template<class T>
TList<T>::void TList<T>::PushEnd(TListNode<T>* q) {
	TListNode<T>* a = new TListNode(begin, end, q)
	end = a;
}

template<class T>
TList<T>::void TList<T>::DeleteBegin() {
	TListNode<T>* a = begin;
	end->SetNext(begin->GetNext());
	begin = begin->GetNext();
	begin->SetPrev(end);
	delete a;
}

template<class T>
TList<T>::void TList<T>::DeleteEnd() {
	TListNode<T>* a = end;
	begin->SetPrev(end->GetPrev());
	end = end->GetPrev();
	end->SetNext(begin);
	delete a;
}

template<class T>
TList<T>::TListNode<T>* TList<T>::GetBegin() {
	return begin;
}

template<class T>
TList<T>::TListNode<T>* TList<T>::GetEnd() {
	return end;
}

template<class T>
TList<T>::TList<T>& TList<T>::operator=(const TList<T>& p) {
	return TList<T>::TList(p);
}

