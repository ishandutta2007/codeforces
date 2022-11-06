#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

const int N = 100004;

int x[N];
std::vector<int> adj[N];
std::vector<pair<int, int> > val[N];

const int mod = 1e9 + 7;

int dfs(int u, int p) {
	int vv = x[u];
	if (p != u) {
		int st = 1;
		if (__gcd(vv, val[p][0].fi) == vv) {
			val[u].pb({vv, val[p][0].se + 1});
		} else {
			st = 0;
			val[u].pb({vv, 1});
		}
		int n = val[p].size();
		for (int i = st; i < n; ++i) {
			vv = __gcd(vv, val[p][i].fi);
			int j = i;
			int su = val[p][i].se;
			while (j + 1 < n && __gcd(vv, val[p][j + 1].fi) == vv) {
				j++;
				su += val[p][j].se;
			}
			val[u].pb({vv, su});
			i = j;
		}
	}
	for (int v : adj[u])
		if (v != p)
			dfs(v, u); 
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> x[i];
	for (int i = 0; i < n - 1; ++i) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int ans = 0;
	val[0].pb({x[0], 1});
	dfs(0, 0);
	for (int i = 0; i < n; ++i) {
		for (auto b : val[i]) 
			ans = (ans + b.se * b.fi % mod) % mod;
	}
	cout << ans;
}