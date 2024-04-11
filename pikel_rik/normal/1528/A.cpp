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

		vector<int> l(n), r(n);
		for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

		vector<vector<int>> g(n);
		for (int i = 0, u, v; i < n - 1; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<array<long long, 2>> dp(n);
		auto dfs = [&](int x, int p, const auto &self) -> void {
			for (int i : g[x]) {
				if (i != p) {
					self(i, x, self);
					dp[x][0] += max(abs(l[x] - l[i]) + dp[i][0], abs(l[x] - r[i]) + dp[i][1]);
					dp[x][1] += max(abs(r[x] - l[i]) + dp[i][0], abs(r[x] - r[i]) + dp[i][1]);
				}
			}
		};

		dfs(0, -1, dfs);
		cout << max(dp[0][0], dp[0][1]) << '\n';
	}
	return 0;
}