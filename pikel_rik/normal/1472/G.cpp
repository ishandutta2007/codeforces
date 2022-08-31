#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> g(n);
		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
		}

		vector<int> d(n, -1);
		queue<int> q;
		q.push(0);
		d[0] = 0;

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i : g[x]) {
				if (d[i] == -1) {
					d[i] = 1 + d[x];
					q.push(i);
				}
			}
		}

		vector<array<int, 2>> dp(n, {-1, -1});

		auto dfs = [&](int x, int f, const auto &self) -> int {
			if (dp[x][f] != -1)
				return dp[x][f];
			if (f == 1) {
				dp[x][f] = d[x];
				for (int i : g[x]) {
					if (d[x] < d[i]) {
						dp[x][f] = min(dp[x][f], self(i, 1, self));
					} else {
						dp[x][f] = min(dp[x][f], self(i, 0, self));
					}
				}
			} else {
				dp[x][f] = d[x];
				for (int i : g[x]) {
					if (d[x] < d[i]) {
						dp[x][f] = min(dp[x][f], self(i, 0, self));
					}
				}
			}
			return dp[x][f];
		};

		for (int i = 0; i < n; i++) {
			cout << dfs(i, 1, dfs) << ' ';
		}
		cout << '\n';
	}
	return 0;
}