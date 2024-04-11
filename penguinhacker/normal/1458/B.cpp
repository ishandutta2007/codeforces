#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100], b[100], dp[10001][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	memset(dp, 0x80, sizeof(dp));
	dp[0][0] = 0;

	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		sum += b[i];
		for (int j = 100 * (i + 1); j >= a[i]; --j) {
			for (int k = i + 1; k >= 1; --k) {
				dp[j][k] = max(dp[j][k], dp[j - a[i]][k - 1] + b[i]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		double ans = 0;
		for (int j = 0; j <= 100 * i; ++j) {
			if (dp[j][i] < 0) continue;
			double cur = min((double)j, dp[j][i] + (double)(sum - dp[j][i]) / 2);
			ans = max(ans, cur);
		}
		cout << ans << " ";
	}
	return 0;
}