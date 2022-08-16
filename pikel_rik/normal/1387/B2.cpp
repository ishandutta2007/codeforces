#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> sz(n);
	auto dfs = [&](int u, int p, const auto &self) -> void {
		sz[u] = 1;
		for (int v : g[u]) {
			if (v != p) {
				self(v, u, self);
				sz[u] += sz[v];
			}
		}
	};

	auto find_centroid = [&](int u, int p, const auto &self) -> int {
		for (int v : g[u]) {
			if (v != p && 2 * sz[v] > n) {
				return self(v, u, self);
			}
		}
		return u;
	};

	dfs(0, -1, dfs);

	int centroid = find_centroid(0, -1, find_centroid);

	vector<int> order;

	long long ans = 0;
	auto find_subtree = [&](int u, int p, int d, const auto &self) -> void {
		order.push_back(u);
		ans += d;
		for (int v : g[u]) {
			if (v != p) {
				self(v, u, d + 1, self);
			}
		}
	};

	for (int v : g[centroid]) {
		find_subtree(v, centroid, 1, find_subtree);
	}

	order.push_back(centroid);

	vector<int> match(n, -1);
	for (int i = 0; i < n; i++) {
		match[order[i]] = order[(i + n / 2) % n];
	}

	cout << 2 * ans << '\n';
	for (int u = 0; u < n; u++) {
		cout << match[u] + 1 << ' ';
	}
	cout << '\n';
	return 0;
}