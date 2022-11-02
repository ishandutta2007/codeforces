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
	int q;
	cin >> q;
	for (int i=0; i<q; i++){
		int c,m,x,n;
		cin >> c >> m >> x;
		n = c+m+x;
		if (n<3*min(c,m)){
			cout<<n/3<<endl;
		}
		else{
			cout<<min(c,m)<<endl;
		}
	}
}