#include <iostream>
using namespace std;
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
bool in(int l, int r, int* a, int x){
	for (int i=l; i<r-1; i++){
		if (a[i] == x){
			return 1;
		}
	}
	return 0;
}
int main(){
	int n,k,l=0,r=1;
	cin>>n>>k;
	int a[n],s=0;
	for (int i=0; i<n; i++){
		int x;
		cin>>x;
		if (not(in(l,r,a,x)) && r-l-1<k){
			r++;
			a[r-2] = x;
		}
		if (not(in(l,r,a,x)) && r-l-1>=k){
			r++;
			l++;
			a[r-2] = x;
		}
	}
	cout<<r-l-1<<endl;
	for (int i=r-2; i>=l; i--){
		cout<<a[i]<<' ';
	}
}