#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
const int N=3*1e5;
long long int a[N],b[N],ans;
priority_queue<long long int> h;
void msort(int l,int r){
	int b[N];
	if (r-l<=1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid);
	msort(mid, r);
	int p1,p2;
	p1 = l;
	p2 = mid;
	for (int i=l; i<r; i++){
		if (p2 >= r || (p1 < mid and a[p1] > a[p2])){
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
}/*
void ans( int t, int l, int r){
	int m=(l+r)/2;
	a[m] = t;
	if (r-l == 1) return;
	if (r-l%2 == 1){
		ans(t+1,l,m);
		t++;
		ans(t+1,m+1,r);
		t++;
	}
	else{
		ans(t+1,m+1,r);
		t++;
		ans(t+2,l,m);	
		t++;
	}
}*/

int main(){
	int t,nad=0,nre=0;
	cin >> t;
	stack <long long int> st;
	long long int k=1;
	for (long long int i=0; i<2*t; i++){
		string s;
		long long int x;
		cin >> s;
		if (s == "add"){
			cin >> x;
			st.push(x);
		}
		if (s == "remove"){
			if (!st.empty()){
				if (k == st.top()){
					k++;
					st.pop();
				}
				else{
					while(!st.empty()){
						h.push(st.top());
						st.pop();
					}
					h.pop();
					k++;
					ans++;
				}
			}
			else{
				h.pop();
				k++;
			}
		}
		
		
	}
	cout<<ans<<endl;
}