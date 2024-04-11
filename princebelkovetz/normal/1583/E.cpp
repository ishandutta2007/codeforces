#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 5e5 + 3;
const ld eps = 1e-7;

vector <vector <int>> g;
vector <bool> used;
vector <int> p, tin, tout;
int timer = 0;
void dfs(int v, int par) {
	p[v] = par;
	tin[v] = timer++;
	used[v] = true;
	for (auto u : g[v]) {
		if (used[u]) continue;
		dfs(u, v);
	}
	tout[v] = timer++;
}

bool isAnc(int v, int u) {
	return tin[v] <= tin[u] and tout[u] <= tout[v];
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout << fixed << setprecision(6);
    
	int n, m; cin >> n >> m;
	g.resize(n + 1);
	used.resize(n + 1);
	tin.resize(n + 1);
	tout.resize(n + 1);
	p.resize(n + 1);
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 1);
	int q; cin >> q;
	int ans = 0;
	vector <int> cnt(n + 1);
	vector <vector <int>> res;
	while (q--) {
		int u, v; cin >> u >> v;
		cnt[u]++, cnt[v]++;
		ans += -1 * (1 - cnt[u] % 2 * 2);
		ans += -1 * (1 - cnt[v] % 2 * 2);
		int lca = u;
		while (!isAnc(lca, v))
			lca = p[lca];
		vector <int> le, ri;
		while (u != lca)
			le.push_back(u), u = p[u];
		while (v != lca)
			ri.push_back(v), v = p[v];
		reverse(ri.begin(), ri.end());
		res.push_back({});
		for (auto& x : le) res.back().push_back(x);
		res.back().push_back(lca);
		for (auto& x : ri) res.back().push_back(x);
	}
	if (ans) {
		cout << "NO\n";
		cout << (ans >> 1) << '\n';
	}
	else {
		cout << "YES\n";
		for (auto& x : res) {
			cout << x.size() << '\n';
			for (auto& y : x) cout << y << ' ';
			cout << '\n';
		}
	}

	return 0;
}