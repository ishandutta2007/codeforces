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
	for (ll k=0; k<t; k++){
		ll n,x,te=0,to=0;
		cin >> n >> x;;
		ll a[n];
		for (ll i=0; i<n; i++){
			cin >> a[i];
			if (a[i]%2) to++;
			else  te++;
		}
		if (to && ((x<=to && x%2) || (x < to && (te)) || (x >= to && (to%2 == 1 || x-to+1 <= te)))){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}