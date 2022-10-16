#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int dp[1 << n];
	for (int i = 0; i < (1 << n); i++) {
		dp[i] = 100000000;
	}
	dp[0] = 0;

	for (int mask = 1; mask < (1 << n); mask++) {
		int lb = __builtin_ctz(mask);

		for (int i = 0; i < m; i++) {
			dp[mask] = min(dp[mask], dp[mask ^ (1 << lb)] + a[lb][i]);

			int sum = 0, mx = 0, bits = 0;
			for (int j = 0; j < n; j++) {
				if (s[j][i] == s[lb][i]) {
					sum += a[j][i];
					mx = max(mx, a[j][i]);
					bits |= (1 << j);
				}
			}

			dp[mask] = min(dp[mask], dp[mask & (mask ^ bits)] + (sum - mx));
		}
	}

	cout << dp[(1 << n) - 1];

	return 0;
}