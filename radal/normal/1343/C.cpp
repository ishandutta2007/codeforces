#include <bits/stdc++.h>
#include <algorithm>
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
/*struct stack{
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
};*/
const int N=1e5*2;
long long int a[N];
bool ham(int a,int b){
	if ((a>0 && b>0)||(a<0 && b<0)){
		return 1;
	}
	return 0;
}
int main(){
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		long long int n,m=0;
		stack <long long int> st;
		cin >> n;
		for (int j=0; j<n; j++){
			cin >> a[i];
			if (st.empty()){
				st.push(a[i]);
			}
			if (!st.empty() && ham(st.top(),a[i])){
				if (a[i]>st.top()){
					st.pop();
					st.push(a[i]);
				}
			}
			else if (!st.empty() && !ham(st.top(),a[i])){
				st.push(a[i]);
			}
		}
		for (int i=0; i<st.size(); i+=0){
			m+=st.top();
			st.pop();
		}
		cout<<m<<endl;
	}
	
}