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


void ins(ll& x,ll& ci, map<ll,ll>& all){
	auto it = all.find(x);
	if(it == all.end()){
		all[x] = ci;
	}
	else{
		if(ci < (*it).ss){
			(*it).ss = ci;
		}
	}
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		map<ll, ll> all;
		vector<ll> ans(n);
		vector<vector<ll> > arr(n, vector<ll>(3));
		fori(n){
			forj(3){
				cin>>arr[i][j];
			}
		}
		fori(n){
			ll li = arr[i][0], ri = arr[i][1], ci = arr[i][2];
			ins(li, ci, all);
			ins(ri, ci, all);
			ans[i] = 0;
			auto it = all.begin();
			ans[i]+=(*it).ss;
			it = all.end();
			--it;
			ans[i] += (*it).ss;
		}
		ll lp = inf, rp = -1, cp = 0;
		fori(n){
			ll li = arr[i][0], ri = arr[i][1], ci = arr[i][2];
			if(li < lp || ri > rp){
				cp = inf;
			}
			lp = min(li, lp), rp = max(ri, rp);
			if(li == lp && ri == rp){
				cp = min(cp, ci);
			}
			ans[i] = min(ans[i], cp);
		}
		fori(n){
			cout<<ans[i]<<'\n';
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}