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
#define lll __int128
#define pb(a) push_back(a)
#define mt make_tuple
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
ll modulo = pow(10,9) + 7;


void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<ll> tot(30, 0);
		bool seen = 0;
		fori(n){
			ll ed;
			cin>>ed;
			if(ed != 0){
				seen = 1;
				forj(30){
					if((1<<j) & ed){
						tot[j]++;
					}
				}
			}
		}
		if(!seen){
			for(ll i = 1; i<=n; i++){
				cout<<i<<' ';
			}
			cout<<'\n';
		}
		else{
			ll ans = -1;
			fori(30){
				if(tot[i]){
					if(ans == -1){
						ans = tot[i];
					}
					else{
						ans = __gcd(tot[i], ans);
					}
				}
			}
			for(ll i = 1; i<=n; i++){
				if(ans % i == 0){
					cout<<i<<' ';
				}
			}
			cout<<'\n';
		}
	}
	
}


int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}