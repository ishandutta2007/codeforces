#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	vector<vector<int>> dp(n + 1, vector<int>(10000 + 1, -1));

	dp[0][0] = 0;
	dp[1][a[0]] = b[0];

	for (int i = 1; i < n; i++) {
		for (int k = i + 1; k >= 1; k--) {
			for (int j = a[i]; j <= 10000; j++) {
				if (dp[k - 1][j - a[i]] != -1) {
					dp[k][j] = max(dp[k][j], b[i] + dp[k - 1][j - a[i]]);
				}
			}
		}
	}

	int sum_b = accumulate(b.begin(), b.end(), 0);
	cout << fixed << setprecision(12);

	for (int k = 1; k <= n; k++) {
		double ans = 0;
		for (int j = 1; j <= 10000; j++) {
			if (dp[k][j] != -1) {
				ans = max(ans, min((double)j, dp[k][j] + (sum_b - dp[k][j]) / 2.0));
			}
		}
		cout << ans << ' ';
	}
	cout << '\n';
	return 0;
}