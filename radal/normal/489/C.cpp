#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
/*void msort(int l,int r,int* a){
	int b[10000];
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid, a);
	msort(mid, r, a);
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
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
}
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
};*/
const int N=1e6;
int a[N];

int main(){
	int m,s,s2,m2;
	cin >> m >> s;
	s2 = s;
	m2 = m;
	if (m>1 and !s || m*9<s){
		cout << "-1 -1" << endl;
		return 0;
	}
	if (!s){
		cout<<"0 0";
		return 0;
	}
	if ((m-1)*9>=s-1){
		cout<<1;
		m--;
		s--;
	}
	while((m-1)*9 >= s){
		cout << 0;
		m--;
	}
	while((m-1)*9 >= s-1){
		cout << 1;
		m--;
		s--;
	}
	while((m-1)*9 >= s-2){
		cout << 2;
		m--;
		s-=2;
	}
	while((m-1)*9 >= s-3){
		cout << 3;
		m--;
		s-=3;
	}
	while((m-1)*9 >= s-4){
		cout << 4;
		m--;
		s-=4;
	}
	while((m-1)*9 >= s-5){
		cout << 5;
		m--;
		s-=5;
	}
	while((m-1)*9 >= s-6){
		cout << 6;
		m--;
		s-=6;
	}
	while((m-1)*9 >= s-7){
		cout << 7;
		m--;
		s-=7;
	}
	while((m-1)*9 >= s-8){
		cout << 8;
		m--;
		s-=8;
	}
	while(s){
		cout << 9;
		m--;
		s-=9;
	}
	cout<<' ';
	
	while (9<=s2 and m2){
		cout<<9;
		m2--;
		s2-=9;
	}
	while (8<=s2 && m2){
		cout<<8;
		m2--;
		s2-=8;
	}
	while (7<=s2 && m2){
		cout<<7;
		m2--;
		s2-=7;
	}
	while (6<=s2 && m2){
		cout<<6;
		m2--;
		s2-=6;
	}
	while (5<=s2 && m2){
		cout<<5;
		m2--;
		s2-=5;
	}
	while (4<=s2 && m2){
		cout<<4;
		m2--;
		s2-=4;
	}
	while (3<=s2 && m2){
		cout<<3;
		m2--;
		s2-=3;
	}
	while (2<=s2 && m2){
		cout<<2;
		m2--;
		s2-=2;
	}
	while (s2){
		cout<<1;
		m2--;
		s2-=1;
	}
	while (m2){
		cout<<0;
		m2--;
		s2-=0;
	}
}