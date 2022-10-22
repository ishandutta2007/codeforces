#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <iomanip>
#include <map>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
const int mxN = 2e5 + 2;
vector <vector <int>> g;
vector <int> color;
vector <bool> used;
void dfs(int v) {
	used[v] = true;
	if (!color[v]) {
		bool c = true;
		for (auto u : g[v])
			if (color[u] == 1) c = false;
		if (c) color[v] = 1;
		else color[v] = 2;
		for (auto u : g[v]) {
			if (!used[u]) dfs(u);
		}
	}
	else {
		for (auto u : g[v]) {
			if (!used[u]) dfs(u);
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n, m; cin >> n >> m;
		g.resize(n + 1);
		color.resize(n + 1);
		used.resize(n + 1);
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		vector <int> ans;
		bool c = true;
		for (int i = 1; i <= n; ++i) {
			if (!used[i]) c = false;
			if (color[i] == 1) ans.push_back(i);
		}
		if (c) {
			cout << "YES\n" << ans.size() << '\n';
			for (auto x : ans) cout << x << ' ';
			cout << '\n';
		}
		else cout << "NO\n";
		g.resize(0);
		color.resize(0);
		used.resize(0);
	}

	return 0;
}