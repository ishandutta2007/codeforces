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

#define MAX 200'010

vector<ll> gbad[MAX];
vector<ll> g[MAX];

ll par[MAX];
ll arr[MAX];
ll tin[MAX];
ll tout[MAX];
bool act[MAX];
bool good[MAX];

void dfs(ll hd, ll pr, ll& tim){
	tin[hd] = tim;
	par[hd] = pr;
	for(auto& hr : gbad[hd]){
		if(hr == pr){
			continue;
		}
		g[hd].pb(hr);
		++tim;
		dfs(hr, hd, tim);
	}
	tout[hd] = tim;
}

ll go(ll u, ll v){
	// go from u to v while havent seen any activated node
	// return first activated node on path
	ll cr = u;
	good[u] = 1;
//	cout<<"we trying to go from "<<u+1<<" to "<<v+1<<endl;
	while(!act[cr]){
		act[cr] = 1;
	//	cout<<"we currently at node "<<cr+1<<endl;
		if(tin[cr] <= tin[v] && tout[v] <= tout[cr]){
			// bin search for right child
			ll lo = 0, hi = (ll)g[cr].size()-1;
			while(lo < hi){
				ll mid = (lo + hi)/2+1;
				ll hr = g[cr][mid];
				if(tin[hr] <= tin[v]){
					lo = mid;
				}
				else{
					hi = mid-1;
				}
			}
			cr = g[cr][lo];
		}
		else{
			cr = par[cr];
		}
	}
	return cr;
}

void deal(){
	ll n;
	cin>>n;
	fori(n){
		cin>>arr[i];
	}
	fori(n-1){
		ll ui, vi;
		cin>>ui>>vi;
		--ui, --vi;
		gbad[ui].pb(vi);
		gbad[vi].pb(ui);
	}
	{
		ll tim = 1;
		dfs(0, -1, tim);
	}
	vector<pair<ll, ll> > all; // (value, node)
	fori(n){
		all.pb(mp(arr[i], i));
	}
	sort(all.rbegin(), all.rend());
	ll ans = 0;
	ll root = all[0].ss;
	ans += arr[root] * 2;
	act[root] = 1;
	good[root] = 1;
//	cout<<115<<endl;
	
	{
		ll sc = all[1].ss; // second  activated node
	//	cout<<119<<endl;
		go(sc, root);
	//	cout<<121<<endl;
		good[sc] = 1;
	}
	
	for(ll i = 2; i<n; i++){
	//	cout<<123<<endl;
		ll cur = all[i].ss;
		if(act[cur]){
			continue;	
		}
		ll wh = go(cur, root);
		if(good[wh]){
			good[wh] = 0;
		}
		else{
			ans += arr[cur];
		}
	}
	
	cout<<ans;
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}