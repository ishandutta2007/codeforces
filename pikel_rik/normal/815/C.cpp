#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, b;
	cin >> n >> b;

	vector<vector<int>> g(n);
	vector<int> c(n), d(n), p(n, -1);

	for (int i = 0; i < n; i++) {
		cin >> c[i] >> d[i];
		if (i > 0) {
			cin >> p[i];
			g[--p[i]].push_back(i);
		}
	}

	vector<int> sz(n, 1);
	vector<vector<array<long long, 2>>> dp(n);

	for (int u = n - 1; u >= 0; u--) {
		int big = -1;

		for (int v : g[u]) {
			if (2 * sz[v] >= sz[u]) {
				big = v;
			}
		}

		dp[u].assign(sz[u] + 1, {LLONG_MAX, LLONG_MAX});
		dp[u][0][0] = dp[u][0][1] = 0;
		dp[u][1][0] = c[u], dp[u][1][1] = c[u] - d[u];

		if (big != -1) {
			for (int i = 0; i <= sz[big]; i++) {
				dp[u][i][0] = min(dp[u][i][0], dp[big][i][0]);
				dp[u][i + 1][0] = min(dp[u][i + 1][0], c[u] + dp[big][i][0]);
				dp[u][i + 1][1] = min(dp[u][i + 1][1], c[u] - d[u] + min(dp[big][i][1], dp[big][i][0]));
			}
		}

		for (int v : g[u]) {
			if (big == v) {
				continue;
			}
			for (int i = sz[u]; i >= 0; i--) {
				for (int j = 1; j <= sz[v] && i + j <= sz[u]; j++) {
					if (dp[u][i][0] != LLONG_MAX) {
						dp[u][i + j][0] = min(dp[u][i + j][0], dp[u][i][0] + dp[v][j][0]);
					}
					if (i > 0 && dp[u][i][1] != LLONG_MAX) {
						dp[u][i + j][1] = min(dp[u][i + j][1], dp[u][i][1] + min(dp[v][j][0], dp[v][j][1]));
					}
				}
			}
		}

		if (p[u] != -1) {
			sz[p[u]] += sz[u];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (min(dp[0][i][0], dp[0][i][1]) <= b) {
			ans = i;
		}
	}
	cout << ans << '\n';
	return 0;
}