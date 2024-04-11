#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n, m;
vector<pair<int, int>> e;
vector<int> par, vis, dep;
vector<vector<int>> g;

void dfs(int v, int prev, int d = 0) {
	if (vis[v]) return;
	vis[v] = 1;
	par[v] = prev;
	dep[v] = d;
	for (const auto &i : g[v])
		dfs(i, v, d + 1);
}

void solve() {
	cin >> n >> m;
	e.resize(m);
	g.clear();
	g.resize(n);
	par.resize(n);
	dep.resize(n);
	vis.resize(n);
	for (auto &i : vis) i = 0;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		e[i] = make_pair(u, v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	string ans(m, '0');
	if (m == n - 1) {
		cout << ans << '\n';
		return;
	}
	vector<int> special;
	set<int> s;
	dfs(0, -1);
	for (int i = 0; i < m; i++) {
		int u = e[i].first, v = e[i].second;
		if (par[u] == v || par[v] == u)
			continue;
		s.insert(u);
		s.insert(v);
		special.push_back(i);
	}
	if (m < n + 2 || s.size() > 3) {
		for (const auto &i : special)
			ans[i] = '1';
		cout << ans << '\n';
		return;
	}
	// swap
	int u = e[special[0]].first, v = e[special[0]].second;
	if (dep[u] < dep[v]) swap(u, v);
	int w = par[u];
	int other = -1;
	for (int i = 0; i < m; i++) {
		if ((e[i].first == u && e[i].second == w) || (e[i].first == w && e[i].second == u)) {
			other = i;
			break;
		}
	}
	ans[other] = '1';
	ans[special[1]] = ans[special[2]] = '1';
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}