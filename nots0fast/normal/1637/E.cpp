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
#define ll long long
#define ld long double
#define pb push_back
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = pow(10, 9) + 7;
double eps = 1e-6;
ifstream in;
ofstream out;

#define MAX 10'010

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, m;
		cin>>n>>m;
		vector<set<ll> > maxes(n); // noone will occur n times, because answer exists 
		vector<bool> bad(n, 0);
		set<ll> seen;
		map<ll, ll> ord;
		map<ll, ll> tot;
		vector<ll> actual(n);
		vector< vector<ll> > bads(n);
		
		fori(n){
			ll ed;
			cin>>ed;
			ord[ed] = 1;
			tot[ed]++;
		}
		{
			ll id = 0;
			for(auto& el : ord){
				el.ss = id;
				actual[id] = el.ff;
				++id;
			}
		}
		fori(m){
			ll xi, yi;
			cin>>xi>>yi;
			ll id1 = ord[xi], id2 = ord[yi];
			bads[id2].pb(id1);
		}
		ll ans = 0;
		for(auto& el : tot){
			ll vl = el.ff, occ = el.ss;
			ll id = ord[vl];
			for(auto& el : bads[id]){
				bad[el] = 1;
			}
			
			for(auto& el : seen){
				ll cnt = el;
				for(auto it = maxes[cnt].end(); it != maxes[cnt].begin(); ){
					--it;
					ll wh = (*it);
					if(!bad[wh]){
						ll v2 = actual[wh];
						ans = max(ans, (vl + v2) *(cnt+ occ));
						break;
					}
				}
			}
			
			maxes[occ].insert(id);
			seen.insert(occ);
			
			for(auto& el : bads[id]){
				bad[el] = 0;
			}
		}
		
		cout<<ans<<'\n';
		
	}
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}