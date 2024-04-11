#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, s, e;
	cin >> n >> m >> s >> e;

	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x, --x;
	for (auto &x : b) cin >> x, --x;

	vector<vector<int>> pos(100000);
	for (int i = 0; i < m; i++) pos[b[i]].push_back(i);

	int seq = min({n, m, s / e});

	vector<vector<int>> dp(n, vector<int>(seq + 1, -1));
	dp[0][1] = !pos[a[0]].empty() ? pos[a[0]][0] : -1;

	for (int i = 1; i < n; i++) {
		if (!pos[a[i]].empty()) {
			if (dp[i - 1][1] == -1) {
				dp[i][1] = pos[a[i]][0];
			} else {
				dp[i][1] = min(dp[i - 1][1], pos[a[i]][0]);
			}
		} else {
			dp[i][1] = dp[i - 1][1];
		}

		for (int j = 1; j < seq && dp[i - 1][j] != -1; j++) {
			int idx = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), dp[i - 1][j]) - pos[a[i]].begin();
			if (idx < int(pos[a[i]].size())) {
				if (dp[i - 1][j + 1] == -1) {
					dp[i][j + 1] = pos[a[i]][idx];
				} else {
					dp[i][j + 1] = min(dp[i - 1][j + 1], pos[a[i]][idx]);
				}
			} else {
				dp[i][j + 1] = dp[i - 1][j + 1];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= seq; j++) {
			if (dp[i][j] != -1 && s - j * e >= i + 1 + dp[i][j] + 1) {
				ans = max(ans, j);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}