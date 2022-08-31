#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<vector<int>> g(n);
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		int xor_sum = accumulate(a.begin(), a.end(), 0, bit_xor<>());

		if (xor_sum == 0) {
			cout << "YES\n";
			continue;
		}

		vector<int> xor_d(n), p(n, -1);

		auto dfs = [&](int u, const auto &self) -> void {
			xor_d[u] = a[u];
			for (int v : g[u]) {
				if (v != p[u]) {
					p[v] = u;
					self(v, self);
					xor_d[u] ^= xor_d[v];
				}
			}
		};

		dfs(0, dfs);

		bool possible = false;
		int zero = 0;

		auto second_dfs = [&](int u, const auto &self) -> bool {
			if (xor_d[u] == xor_sum) {
				possible |= k - 1 >= 2 && zero > 0;
			}
			zero += xor_d[u] == 0;
			int cnt = 0;
			for (int v : g[u]) {
				if (v != p[u]) {
					cnt += self(v, self);
				}
			}
			possible |= k - 1 >= 2 && cnt >= 2;
			cnt += xor_d[u] == xor_sum;
			zero -= xor_d[u] == 0;
			return cnt > 0;
		};

		second_dfs(0, second_dfs);
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}