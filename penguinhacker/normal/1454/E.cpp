#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
bool vis[200000];
vector<int> adj[200000];
vector<int> cyc;

bool dfs(int u = 0, int p = -1) {
	vis[u] = 1;
	cyc.push_back(u);
	for (int v : adj[u]) {
		if (v == p) continue;
		if (vis[v]) {
			cyc.push_back(v);
			return 1;
		}
		if (dfs(v, u)) return 1;
	}
	cyc.pop_back();
	return 0;
}

int dfs2(int u, int p) {
	int ret = 1;
	for (int v : adj[u]) if (v != p) ret += dfs2(v, u);
	return ret;
}

void solve() {
	cyc.clear();
	cin >> n;
	ll ans = (ll)n * (n - 1);
	for (int i = 0; i < n; ++i) {
		vis[i] = 0;
		adj[i].clear();
	}
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	assert(dfs());
	cyc = vector<int>(find(cyc.begin(), cyc.end(), cyc.back()) + 1, cyc.end());
	int k = cyc.size();
	for (int i = 0; i < k; ++i) {
		int a = cyc[i], b = cyc[(i + 1) % k], c = cyc[(i + 2) % k];
		int cur = 1;
		for (int v : adj[b]) if (v != a && v != c) cur += dfs2(v, b);
		ans -= (ll)cur * (cur - 1) / 2;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}