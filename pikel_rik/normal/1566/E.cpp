#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> g(n);
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<int> p(n, -1);

		vector<int> regular(n), leaves(n);
		auto dfs = [&](int u, const auto &self) -> void {
			for (int v : g[u]) {
				if (v != p[u]) {
					p[v] = u;
					self(v, self);
					if (g[v].size() == 1) {
						leaves[u] += 1;
					} else {
						regular[u] += 1;
					}
				}
			}
		};
		dfs(0, dfs);

		int ans = 0;
		for (int i = 1; i < n; i++) {
			ans += g[i].size() == 1;
		}

		auto check = [&](int u) -> bool {
			return leaves[u] > 0 && regular[u] == 0;
		};

		queue<int> q;
		for (int i = 1; i < n; i++) {
			if (check(i)) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			ans -= 1;

			int v = p[u];
			regular[v] -= 1;
			if (v != 0) {
				if (check(v)) {
					q.push(v);
				} else if (regular[v] == 0) {
					regular[p[v]] -= 1;
					leaves[p[v]] += 1;
					if (p[v] != 0 && check(p[v])) {
						q.push(p[v]);
					}
					ans += 1;
				}
			} else if (leaves[0] == 0 && regular[0] == 0) {
				ans += 1;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}