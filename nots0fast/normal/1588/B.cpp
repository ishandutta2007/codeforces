/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
*/

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
#define lll __int128
#define pb(a) push_back(a)
#define ld long double
#define mt make_tuple
const ll INF = 0x3f3f3f3f;
ll inf = 1e18;
ll modulo = pow(10,9) + 7;

const bool debug = 1;

ll tot = 0;

ll ask(ll i, ll j){
	cout<<"? "<<i<<" "<<j<<endl;
	ll ans;
	cin>>ans;
	return ans;
}

ll getx(ll val){
	ll x = sqrt((long double) 2*val);
	while(x * ( x  + 1) < 2*val){
		++x;
	}
	return x;
}

void deal(){  
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		ll lo = 1, hi = n;
		
		ll tot = ask(1, n);
		
		while(lo < hi){
			ll mid = (lo+hi)/2;
			ll cur = ask(1, mid);
			if(cur == tot){
				hi = mid;
			}
			else{
				lo = mid + 1;
			}
		}
		ll cur1 = ask(1, lo);
		ll cur2 = ask(1, lo-1);
		
		ll x1 = cur1 - cur2;
		
		ll k = lo;
		ll j = k - x1;
		
		ll cur3 = ask(1, j-1);
		ll cur4 = ask(1, j-2);
		
		ll x2 = cur3 - cur4;
		
		ll i = j-1-x2;
		
		cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
		
		
	}
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}