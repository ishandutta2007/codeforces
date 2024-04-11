#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 1e9 + 7;
int n, k, dp[1001][1001];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j)
			dp[i][j] = 0;
	++dp[1][k];
	ll ans = 0;
	for (int j = k; j >= 1; --j) {
		for (int i = 1; i <= n; ++i) {
			if (i + 1 <= n)
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
			if (i == 1 && j > 1)
				ans += dp[i][j];
			if (i == n)
				ans += dp[i][j];
			if (j > 1 && i > 1)
				dp[n - i + 2][j - 1] = (dp[n - i + 2][j - 1] + dp[i][j]) % MOD;
		}
	}
	cout << ans % MOD << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}