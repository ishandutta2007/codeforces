#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
const int N=3*1e5;
long long int a[N],day[N];
//pair <string,long long int> ans[N];
/*void msort(int l,int r){
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
			cntR[p1] += r-p2;
			cntL[p1] +=p1;
			p1++;
		}
		else{
			cntR[p2] += r-p2-1;
			cntL[p2] += mid-p1+1;
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
	int n,b=1;
	cin >> n;
	day[0] = 1;
	day[n-1] = 1;
	deque <long long int> dq;
	for (int i=0; i<n; i++){
		long long int x;
		cin >> a[i];
	}
	for (int i = 1; i<n-1; i++){
		day[i]=min(day[i-1]+1, a[i]);
	}
	for (int i = n-2; i>=1; i--){
		day[i]=min(day[i+1]+1, day[i]);
		if (day[i] > b)	b=day[i];
		//cout<<i<<" : "<<day[i]<<endl;
	}
	cout<<b<<endl;
}