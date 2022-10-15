#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define t(x) cerr<<#x<<":"<<x<<'\n';
#define t2(a,n) { cerr<<#a<<" = "; for(int i=0; i<n; ++i){ cerr << a[i] << ' '; } ; cerr <<'\n'; }
 
ll mid;
ll nodes;
ll n,l,r;
ll st;
 
void get(){
	st = 0;
	ll p = n;
	while( p>1 ){
		p /= 2;
		st++;
	}
	st++;
	nodes = pow(2,st) - 1;
	mid = pow(2,st-1);
}
 
ll get2(ll ind){
	ll start = mid;
	ll val = n;
	ll off = pow(2,st-2);
	while( true ){
		if( start == ind ){ break; }
		else if( ind < start ){ start -= off; }
		else if( ind > start ){ start += off; }
		off /= 2;
		val /= 2;
	}
	return val % 2;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	cin>>n>>l>>r;
	get();
	ll ans = 0;
	for(ll i=l; i<=r; ++i){
		ans += get2(i);
	}
	cout<<ans<<'\n';
}