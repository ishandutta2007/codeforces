#include <iostream>
using namespace std;
struct node{
	int val;
	node* p;
};

struct stack{
	node* top=NULL;
	int s=0;
	int topp(){
		if (s>0)
		return top->val;
		else
		return NULL;
	}
	void push(int x){
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
bool in(int l, int r, int n){
	if (n>=l and n<=r)
	return 1;
	return 0;
}
int main(){
	int n,m=0;
	cin >> n;
	int a[n][n];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin>>a[i][j];
			if (i==(n-1)/2 || j==(n-1)/2 || i == j || i+j == n-1){
				m+=a[i][j];
			}
		}
	}
	cout << m;
}