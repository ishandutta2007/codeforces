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
#define mt make_tuple
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
ll modulo = pow(10,9) + 7;


#define MAX 200'010
map<ll, ll> fen[MAX];

void updTillEnd(ll id1, ll id2, ll vl){
	while(id1 < MAX){
		auto it = fen[id1].find(id2);
		if(it == fen[id1].end() || (*it).ss < vl){
			auto itb = fen[id1].upper_bound(id2);
			--itb;
			if((*itb).ss < vl){
				fen[id1][id2] = vl;
				it = fen[id1].find(id2);
				while(1){
					auto itn = it;
					++itn;
					if(itn!=fen[id1].end() && (*itn).ss <= (*it).ss){
						fen[id1].erase(itn);
					}
					else{
						break;
					}
				}
			}
		}
		id1+=id1&-id1;
	}
}

ll queTillStart(ll id1, ll id2){
	ll mx = 0;
	while(id1){
		auto it = fen[id1].upper_bound(id2);
		--it;
		mx = max(mx, (*it).ss);
		id1-=id1&-id1;
	}
	return mx;
}

void deal(){
	fori(MAX){
		fen[i][-inf] = 0;
	}
	ll n;
	cin>>n;
	ll ans = 0;
	for(ll i  =1; i<=n; i++){
		ll ed;
		cin>>ed;
		if(ed <= i){
			ll delcur = (i-ed);
			ll cur = queTillStart(ed-1, delcur) + 1;
			ans = max(ans, cur);
			updTillEnd(ed, delcur, cur);
		}
	}
	cout<<ans;
}
 

int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}