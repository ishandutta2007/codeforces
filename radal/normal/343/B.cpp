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
int main(){
	string s;
	cin>>s;
	stack st;
	for (int i=0; i<s.size(); i++){
		if (s[i] == st.topp()){
			st.pop();
		}
		else{
			st.push(s[i]);
		}
	}
	if (st.s > 0){
		cout<< "NO";
	}
	else{
		cout << "YES";
	}
}