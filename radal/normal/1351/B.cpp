#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int
using namespace std;
/*
void pairsort(ll l, ll r){
	ll m=(l+r)/2;
	if (l == r-1){
		return;
	}
	pairsort(l,m);
	pairsort(m,r);
	ll pl = l;
	ll pr = m;
	for (ll i=l; i<r; i++){
		if (pr >= r || (pl < m && a[pl].first > a[pr].first)){
			b[i].first = a[pl].first;
			b[i].second = a[pl].second;
			pl++;
		}
		else{
			b[i].first = a[pr].first;
			b[i].second = a[pr].second;
			pr++;
		}
	}
	for (ll i=l; i<r; i++){
		a[i].first = b[i].first;
		a[i].second = b[i].second;
	}
}

void msort(ll l,ll r){
	if (r-l==1){
		return;
	}
	ll mid = (l+r)/2;
	msort(l, mid);
	msort(mid, r);
	ll p1,p2;
	p1 = l;
	p2 = mid;
	for (ll i=l; i<r; i++){
		if (p2>=r || (a[p1]<a[p2] and p1<=mid)){
			b[i] = a[p1];
			//L[i] += p2 - mid;
			p1++;
		}
		else{
			b[i] = a[p2];
			//R[i] += mid - p1;
			p2++;
		}
	}
	for (ll i=l; i<r; i++){
		a[i]=b[i];
	}
}*/

int main(){
	ll t;
	cin >> t;
	for (ll p=0; p<t; p++){
		ll a1,b1,a2,b2;
		cin >> a1 >> b1 >> a2 >> b2;
		if (max(a1,b1) == max(a2,b2) && min(a1,b1)+min(a2,b2) == max(a1,b1)){
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
}