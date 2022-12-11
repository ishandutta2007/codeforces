#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define int ll

const int N = 5001;

vector<pii> T[N];

ll to[N];
ll al;

ll subt[N];

ll tru[N];

void dfs(int u, int par){
	int sz;
	subt[u] = 1;
	for(auto x : T[u]){
		if(x.fi == par)
			continue;
		dfs(x.fi, u);
		tru[u] += 1ll * to[u] * subt[x.fi] + to[x.fi] * 1ll * subt[u];
		tru[u] += 1ll * subt[u] * subt[x.fi] * x.se;
		to[u] += to[x.fi] + 1ll * subt[x.fi] * x.se;
		subt[u] += subt[x.fi];
	}
	al += tru[u];
}

ll flt[N];

ll mins;

void dfs1(int u, int par, ll sum, int sy){
	flt[u] = to[u] + sum;
	mins = min(mins, flt[u]);
	int add;
	for(auto x : T[u]){
		if(x.fi == par)
			continue;
		add = to[u];
		add -= to[x.fi] + subt[x.fi] * 1ll * x.se;
		dfs1(x.fi, u, sum + add + ((sy - subt[x.fi]) * 1ll * x.se), sy);
	}
}

signed main(){
	fastIO;
	int n;
	cin >> n;
	int u[n], v[n];
	ll w[n];
	for(int i = 1 ; i < n; i ++ ){
		cin >> u[i] >> v[i] >> w[i];
	}
	int s1, s2;
	ll w1, w2;
	ll answ = (ll)1e18;
	ll c1, c2;
	ll curr;
	for(int i = 1; i < n; i ++ ){
		for(int j = 1; j < n; j++ ){
			if(i != j){
				T[u[j]].push_back(mp(v[j], w[j]));
				T[v[j]].push_back(mp(u[j], w[j]));
			} 
		}
		al = 0;
		dfs(u[i], -1);
		s1 = subt[u[i]];
		w1 = al;
		al = 0;
		dfs(v[i], -1);
		s2 = subt[v[i]];
		w2 = al;
		
		mins = (ll)1e18;
		dfs1(u[i], -1, 0, s1);
		c1 = mins;
		mins = (ll)1e18;
		dfs1(v[i], -1, 0, s2);
		c2 = mins;
		curr = 0;
		curr += w1 + w2;
		curr += 1ll * s1 * s2 * w[i];
		curr += 1ll * s1 * c2;
		curr += 1ll * s2 * c1;
		answ = min(answ, curr);
		for(int z = 1; z <= n; z ++ ){
			subt[z] = 0;
			flt[z] = 0;
			to[z] = 0;
			tru[z] = 0;
			T[z].clear();
		}
	}
	cout << answ << "\n";
	return 0;
}