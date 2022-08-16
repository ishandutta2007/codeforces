#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, p, M, m;
	cin >> n >> p >> M >> m;

	int sz = p + M;
	vector<vector<int>> g(2 * sz);
	vector<vector<int>> grev(2 * sz);

	auto add_edge = [&](int u, int v) -> void {
		g[u].push_back(v);
		grev[v].push_back(u);
	};

	for (int i = 0; i + 1 < M; i++) {
		add_edge(sz + i + p, sz + i + 1 + p);
		add_edge(i + 1 + p, i + p);
	}

	for (int i = 0, x, y; i < n; i++) {
		cin >> x >> y, --x, --y;
		add_edge(sz + x, y);
		add_edge(sz + y, x);
	}

	for (int i = 0, l, r; i < p; i++) {
		cin >> l >> r, --l, --r;
		add_edge(i, l + p);
		add_edge(sz + l + p, sz + i);
		if (r + 1 != M) {
			add_edge(i, sz + r + 1 + p);
			add_edge(r + 1 + p, sz + i);
		}
	}

	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		add_edge(u, sz + v);
		add_edge(v, sz + u);
	}

	int timer = 0;
	vector<int> tout(2 * sz);
	vector<bool> visited(2 * sz);

	auto dfs_rev = [&](int u, const auto &self) -> void {
		visited[u] = true;
		for (int v : grev[u]) {
			if (!visited[v]) {
				self(v, self);
			}
		}
		tout[timer++] = u;
	};

	for (int i = 0; i < 2 * sz; i++) {
		if (!visited[i]) {
			dfs_rev(i, dfs_rev);
		}
	}

	vector<int> t(2 * sz);
	auto dfs = [&](int u, const auto &self) -> void {
		visited[u] = true, t[u] = timer;
		for (int v : g[u]) {
			if (!visited[v]) {
				self(v, self);
			}
		}
	};

	fill(visited.begin(), visited.end(), false);
	for (int i = 2 * sz - 1; i >= 0; i--) {
		if (!visited[tout[i]]) {
			dfs(tout[i], dfs);
			timer += 1;
		}
	}

	int k = 0, f = 0;
	for (int i = 0; i < sz; i++) {
		if (t[i] == t[i + sz]) {
			return cout << "-1\n", 0;
		}
		if (i < p) {
			k += t[i] < t[i + sz];
		} else if (t[i] < t[i + sz]) {
			f = i - p;
		}
	}

	cout << k << ' ' << f + 1 << '\n';
	for (int i = 0; i < p; i++) {
		if (t[i] < t[i + sz]) {
			cout << i + 1 << ' ';
		}
	}
	cout << '\n';
	return 0;
}