#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

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
	int n,k=0,n3,t=0;
	cin>>n;
	n3 = n;
	while (n3){
		if (n3%10 > k){
			k=n3%10;
		}
		n3/=10;
		t++;
	}
	cout<<k<<endl;
	for (int i=0; i<k; i++){
		string s="";
		for (int j=1; j<=t; j++){
			int r=n;
			r%=int(pow(10,j));
			r/=int(pow(10,j-1));
			if (r){
				s+='1';
				n-=pow(10,j-1);
			}
			else{
				s+='0';
			}

		}
		reverse(s.begin(),s.end());
		int p=0;
		while (s[p] == '0'){
			s.erase(0,1);
		}
		cout<<s<<' ';
	}
}