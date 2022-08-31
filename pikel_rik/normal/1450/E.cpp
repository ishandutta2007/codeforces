#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	struct edge { int u, v, b; };

	int n, m;
	cin >> n >> m;

	vector<edge> e(m);
	vector<vector<int>> g(n);

	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].b;
		g[--e[i].u].push_back(i);
		g[--e[i].v].push_back(i);
	}

	vector<int> mark(n, -1);
	auto dfs = [&](int u, const auto &self) -> void {
		for (int i : g[u]) {
			int v = u ^ e[i].u ^ e[i].v;
			if (mark[v] == -1) {
				mark[v] = mark[u] ^ 1;
				self(v, self);
			}
		}
	};

	mark[0] = 0;
	dfs(0, dfs);

	for (int i = 0; i < m; i++) {
		if (mark[e[i].u] == mark[e[i].v]) {
			return cout << "NO\n", 0;
		}
	}

	constexpr int inf = (int)1e6;
	vector<vector<int>> d(n, vector<int>(n, inf));

	for (int i = 0; i < n; i++) d[i][i] = 0;
	for (int i = 0; i < m; i++) {
		d[e[i].u][e[i].v] = 1;
		if (e[i].b == 0) {
			d[e[i].v][e[i].u] = 1;
		} else {
			d[e[i].v][e[i].u] = -1;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (d[i][i] < 0) {
			return cout << "NO\n", 0;
		}
	}

	int u = 0, v = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] > d[u][v]) {
				u = i, v = j;
			}
		}
	}

	auto [mn, mx] = minmax_element(d[u].begin(), d[u].end());

	cout << "YES\n" << *mx - *mn << '\n';
	for (int i = 0; i < n; i++) cout << d[u][i] << ' ';
	cout << '\n';
	return 0;
}