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

	vector<int> p(n, -1), mx(n, -1), sz(n, 1), c(n);
	auto dfs = [&](int u, auto &&self) -> void {
		for (int v : g[u]) {
			if (v != p[u]) {
				p[v] = u;
				self(v, self);
				sz[u] += sz[v], c[u] += 1;
				if (mx[u] == -1 || sz[mx[u]] < sz[v]) {
					mx[u] = v;
				}
			}
		}
	};
	dfs(0, dfs);

	int q;
	cin >> q;

	vector<vector<pair<int, int>>> queries(n);
	for (int i = 0; i < q; i++) {
		int v, k;
		cin >> v >> k, --v;
		queries[v].emplace_back(k, i);
	}

	vector<int> ans(q);
	auto dp_dfs = [&](int u, auto &&self) -> vector<int> {
		vector<int> dp;
		for (int v : g[u]) {
			if (v != p[u]) {
				auto dp_v = self(v, self);
				int k = 0;
				for (; k < (int) dp_v.size(); k++) {
					if (k == (int) dp.size()) {
						dp.push_back(c[u]);
					}
					if (dp_v[k] - k > 1) {
						dp[k] += dp_v[k] - k - 1;
					} else {
						break;
					}
				}
				for (; k <= sz[u]; k++) {
					if (k == (int) dp.size()) {
						dp.push_back(c[u]);
					}
					if (c[v] - k > 1) {
						dp[k] += c[v] - k - 1;
					} else {
						break;
					}
				}
			}
		}
		for (auto [k, i] : queries[u]) {
			ans[i] = (k < (int) dp.size() ? dp[k] : c[u]);
		}
		return dp;
	};
	dp_dfs(0, dp_dfs);

	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}