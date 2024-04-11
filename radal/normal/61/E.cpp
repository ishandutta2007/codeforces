#include <bits/stdc++.h>

#define ll long long int
#define for(i,l,r) for (ll i=l; i<r; i++)
using namespace std;
const int N=1e6;
pair <ll,ll> a[N],b[N];
ll c[N],d[N];
ll cntl[N],cntr[N];
void pairsort(ll l, ll r){
	ll m=(l+r)/2;
	if (l == r-1){
		return;
	}
	pairsort(l,m);
	pairsort(m,r);
	ll pl = l;
	ll pr = m;
	for (i,l,r){
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
	for (i,l,r){
		a[i].first = b[i].first;
		a[i].second = b[i].second;
	}
}
void msort(ll l, ll r){
	if (r-l == 1){
		return;
	}
	ll m=(l+r)/2;
	ll p1=l,p2=m;
	msort(l,m);
	msort(m,r);
	for (i,l,r){
		if (p2>=r || (p1<m && c[p1] > c[p2])){
			d[i] = c[p1];
			cntr[c[p1]] += p2-m; 
			p1++;
		}
		else{
			d[i] = c[p2];
			cntl[c[p2]] += m-p1;
			p2++;
		}
	}
	for (i,l,r){
		c[i] = d[i];
	}
}
int main ()
{
	ll n;
	ll ans=0;
	cin>>n;
	for (j,0,n){
		ll x;
		cin >> x;
		a[j].first = x;
		a[j].second = j;
	}
	pairsort(0,n);
	for (i,0,n){
		c[a[i].second] = i; 
		//cout<<c[a[i].second]<<endl;
	}
	msort(0,n);
	for (i,0,n){
		
		ans += cntl[i]*cntr[i];
		//cout<<cntl[i]<<' '<<cntr[i];
	}
	cout<<ans<<endl;
}