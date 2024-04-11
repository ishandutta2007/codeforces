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
		for (int i = 1, v; i < n; i++) {
			cin >> v, --v;
			g[i].push_back(v);
			g[v].push_back(i);
		}

		vector<int> a(n), d(n);
		for (int i = 1; i < n; i++) cin >> a[i];

		vector<vector<int>> lvl(n);

		auto dfs = [&](int x, int p, const auto &self) -> void {
			lvl[d[x]].push_back(x);
			for (int i : g[x]) {
				if (i != p) {
					d[i] = 1 + d[x];
					self(i, x, self);
				}
			}
		};

		dfs(0, -1, dfs);

		int mx_d = 0;
		for (int i = 0; i < n && !lvl[i].empty(); i++) {
			mx_d = i;
		}

		vector<long long> dp(n);
		for (int i = mx_d - 1; i >= 0; i--) {
			int mx_val = INT_MIN, mn_val = INT_MIN;
			long long mx_dp = LLONG_MIN, mn_dp = LLONG_MIN;

			for (int u : lvl[i + 1]) {
				mx_val = max(mx_val, a[u]);
				mn_val = max(mn_val, -a[u]);
				mx_dp = max(mx_dp, a[u] + dp[u]);
				mn_dp = max(mn_dp, -a[u] + dp[u]);
			}

			for (int u : lvl[i]) {
				for (int x : g[u]) {
					if (d[x] == i - 1) continue;
					dp[u] = max({dp[u], a[x] + mn_val + dp[x], -a[x] + mx_val + dp[x]});
					dp[u] = max(dp[u], -a[x] + mx_dp);
					dp[u] = max(dp[u], a[x] + mn_dp);
				}
			}
		}

		cout << dp[0] << '\n';
	}
	return 0;
}