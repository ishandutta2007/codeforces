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
#define pb(a) push_back(a)
#define mt make_tuple
const ll INF = 0x3f3f3f3f;
const ll inf =  1e18;
const ll modulo = pow(10, 9) + 7;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, x;
		cin>>n;
		vector<ll> arr(n+1, 0);
		for(ll i = 1; i<=n; i++){
			cin>>arr[i];
		}
		cin>>x;
		vector<ll> pf(n+1, 0);
		for(ll i= 1; i<=n; i++){
			pf[i] = pf[i-1] + arr[i];
		}
		vector<ll> minid(n +1, 0);	// minid s.t. we can take all up to that id
		minid[1] = 0;
		set<pair<ll,ll> > all;
		// all contains ( dp[i] - i * x , i )   pairs
		ll id = 0;
		for(ll i = 2; i<=n; i++){
			all.insert(mp(pf[i-2] - (i-2)*x, i-2));
			ll vl = pf[i] - i * x ;
			// vl >= vl2
			ll maxbad = -1;
			{
				auto it = all.end();
				while(it != all.begin()){
					--it;
					if((*it).ff > vl){
						maxbad = max(maxbad, (*it).ss);
					}
					else{
						break;
					}
				}
			}
			while(id < maxbad + 1){
				all.erase(mp(pf[id]  - id *x, id));
				++id;
			}
			minid[i] = id;
		}
		for(ll i = 1; i<=n; i++){
		//	cout<<"minid at "<<i<<" is "<<minid[i]<<endl;
		}
		vector<ll> dp(n+1, 0);
		dp[1] = 1;
		all.clear();
		// store dp[i-1] + -(i-1) for all relavant i's (i >= 1)
		// for 0!!! store dp[i] - i
		all.insert(mp(0, 0));	// for 0
		id = 0;
		for(ll i = 1; i<=n; i++){
			dp[i] = dp[i-1];
			while(id < minid[i]){
				ll vl = 0;
				if(id != 0){
					vl = dp[id-1] - id;
				}
				all.erase(mp(vl, id));
				++id;
			}
			assert(!all.empty());
			auto it = all.end();
			--it;
		//	cout<<"at index "<<i<<" we can include from "<<(*it).ss<<" to get a total of "<<(*it).ff + i<<endl; 
			dp[i] = max(dp[i], (*it).ff + i);
			all.insert(mp(dp[i-1] - i, i));
		}
		cout<<dp[n]<<'\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}