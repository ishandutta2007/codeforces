#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> x(n);
	for (auto &it : x) cin >> it;

	vector<bool> visited(n);

	vector<int> path;
	auto dfs = [&](int u, int p, const auto &self) -> void {
		path.push_back(u);
		x[u] ^= 1;
		visited[u] = true;
		for (int i : g[u]) {
			if (!visited[i]) {
				self(i, u, self);
				path.push_back(u);
				x[u] ^= 1;
			}
		}
		if (x[u]) {
			if (p != -1) {
				path.push_back(p);
				x[p] ^= 1;
				path.push_back(u);
				x[u] ^= 1;
			} else {
				if (g[u].empty()) {
					cout << "-1\n";
					exit(0);
				} else {
					path.push_back(g[u][0]);
					path.push_back(u);
					x[u] ^= 1;
					path.push_back(g[u][0]);
				}
			}
		}
	};

	for (int i = 0; i < n; i++) {
		if (x[i]) {
			dfs(i, -1, dfs);
			break;
		}
	}

	if (count(x.begin(), x.end(), 1)) {
		cout << "-1\n";
	} else {
		cout << path.size() << '\n';
		for (auto i : path) cout << i + 1 << ' '; cout << '\n';
	}
	return 0;
}