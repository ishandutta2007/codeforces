#include <bits/stdc++.h>
#include<algorithm>
#define ll long long int
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
ll a[50][50];
ll check(ll n ,ll m){
	ll ans1=0,ans2=0;
	for (ll x=0; x<n; x++){
		bool f=0;
		for (ll y=0; y<m; y++){
			if (a[x][y]){
				f =1;
				break;
			}
		}
		if (!f) ans1++;
	}
	for (ll y=0; y<m; y++){
		bool f=0;
		for (ll x=0; x<n; x++){
			if (a[x][y]){
				f =1;
				break;
			}
		}
		if (!f) ans2++;
	}
	return min(ans1,ans2);
}
int main(){
	ll t;
	cin >> t;
	ll a[t];
	for (ll k=0; k<t; k++){
		cin >> a[k];
	}
	sort(a,a+t);
	for (ll i=0; i<t; i++){
		cout<<a[i]<<' ';
	}
}