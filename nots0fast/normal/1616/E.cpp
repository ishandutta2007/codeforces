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

void updTillEnd(ll id, ll vl, vector<ll>& fen){
	ll sz = fen.size();
	while(id < sz){
		fen[id] += vl;
		id+=id & -id;
	}
}

ll queTillStart(ll id, vector<ll>& fen){
	ll sz = fen.size();
	ll s = 0 ;
	id = min(id, sz-1);
	while(id){
		s += fen[id];
		id -= id&-id;
	}
	return s;
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		vector<stack<ll> > all(26);
		ll n;
		string s, t;
		cin>>n>>s>>t;
		s = " "+s;
		t = " "+t;
		for(ll i = n; i; i--){
			all[s[i] - 'a'].push(i);
		}
		ll ans = inf;
		ll cur = 0;
		
		vector<ll> fen(n + 10, 0);
		for(ll i = 1; i<=n; i++){
			ll id = (t[i]- 'a');
			ll mncur = inf;
			for(ll j = id-1; j>-1; j--){
				if(!all[j].empty()){
					ll hd = all[j].top();
					mncur = min(mncur, hd);
				}
			}
			if(mncur != inf){
				ll qr = queTillStart(mncur, fen);
				ans = min(ans, cur + mncur - 1 - qr);
			}
			if(!all[id].empty()){
				ll hd = all[id].top();
				all[id].pop();
				ll qr = queTillStart(hd, fen);
				cur += hd - 1 - qr;
				updTillEnd(hd, 1, fen);
			}
			else{
				break;
			}
		}
		if(ans == inf){
			ans = -1;
		}
		cout<<ans<<'\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}