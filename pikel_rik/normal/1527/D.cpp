#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	auto choose = [&](long long n) -> long long {
		return (n * n - n) / 2;
	};

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> g(n);
		for (int i = 0, u, v; i < n - 1; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		int timer = 0;
		vector<int> sz(n), tin(n), tout(n);

		auto dfs = [&](int x, int p, const auto &self) -> void {
			tin[x] = timer++, sz[x] = 1;
			for (int i : g[x]) {
				if (i != p) {
					self(i, x, self);
					sz[x] += sz[i];
				}
			}
			tout[x] = timer++;
		};

		dfs(0, -1, dfs);

		auto is_anc = [&](int u, int v) -> bool {
			return tin[u] <= tin[v] && tout[u] >= tout[v];
		};

		vector<long long> ans(n + 2);

		int sz1 = 1, sz2 = sz[1], leaf1 = 0, leaf2 = 1;
		for (int i : g[0]) {
			if (!is_anc(i, 1)) {
				sz1 += sz[i];
			}
		}

		ans[2] = (long long)sz1 * sz2;
		for (int u = 2; u < n; u++) {
			if (!is_anc(u, leaf1) && !is_anc(u, leaf2)) {
				if (is_anc(leaf2, u)) {
					sz2 = sz[u], leaf2 = u;
				} else if (is_anc(leaf1, u)) {
					if (leaf1 == 0) {
						bool ok = true;
						for (int i : g[0]) {
							ok &= !is_anc(i, u) || !is_anc(i, leaf2);
						}
						if (!ok) {
							break;
						}
					}
					sz1 = sz[u], leaf1 = u;
				} else {
					break;
				}
			}
			ans[u + 1] = (long long)sz1 * sz2;
		}

		long long sum_sq = 0, sum = 0;
		for (int i : g[0]) {
			sum_sq += (long long)sz[i] * sz[i];
			sum += sz[i];
		}

		ans[0] = choose(n), ans[1] = (sum * sum - sum_sq) / 2 + n - 1;
		for (int i = 0; i <= n; i++) cout << ans[i] - ans[i + 1] << ' ';
		cout << '\n';
	}
	return 0;
}