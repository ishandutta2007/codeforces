#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
 

#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define double long double
#define MAX (int)(pow(10,6) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;

ll sqt(ll n){
	ll lo = 0, hi = 1e9;
		while(lo < hi){
			ll mid = (lo+hi)/2;
			if(mid * mid < n){
				lo = mid+1;
			}
			else{
				hi = mid;
			}
		}
	return lo;
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		
		
		if((n%4 == 0 && sqt(n/4) * sqt(n/4) == n/4) || (n%2 == 0 && sqt(n/2) * sqt(n/2) == n/2) ){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
		
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}