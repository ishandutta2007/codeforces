#include <iostream>
#include <cmath>
using namespace std;
/*
void msort(int l,int r){
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid);
	msort(mid, r);
	int p1,p2;
	p1 = l;
	p2 = mid;
	for (int i=l; i<r; i++){
		if (p2>=r || (a[p1]<a[p2] and p1<mid)){
			b[i] = a[p1];
			p1++;
		}
		else{
			b[i] = a[p2];
			p2++;
			if (a[p1]>a[p2]){
				tt++;
				cout<<a[p1]<<a[p2]<<endl;
		}
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}*/
int LCD (int a,int b){
	if (b>a){
		swap(a,b);
	}
	if (b == 0){
		return a;
	}
	else{
		return LCD(b,a%b);
	}
}
struct node{
	char val;
	node* p;
};
struct stack{
	node* top=NULL;
	int s=0;
	char topp(){
		if (s>0)
		return top->val;
		else
		return NULL;
	}
	void push(char x){
		node* a=new node;
		a->val=x;
		a->p=top;
		top=a;
		s++;
	}
	void pop(){
		if (s>1){
			top=top->p;
		}
		else{
			top=NULL;
		}
		s--;
	}
};
int main(){
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		int n,z=3,y=4;
		cin>>n;
		while (n%z!=0){
			z+=y;
			y*=2;
		}
		cout<<n/z<<endl;
	}
	
}