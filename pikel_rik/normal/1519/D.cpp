#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	vector<vector<long long>> dp(n, vector<long long>(n));
	//dp[i][j] = a[i] * b[j] + dp[i + 1][j - 1]

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = (long long)a[i] * b[j];
			if (i + 1 < n && j > 0) {
				dp[i][j] += dp[i + 1][j - 1];
			}
		}
	}

	vector<long long> pref(n);
	for (int i = 0; i < n; i++) pref[i] = (long long)a[i] * b[i];

	partial_sum(pref.begin(), pref.end(), pref.begin());

	long long ans = pref.back();
	for (int l = 0; l < n; l++) {
		for (int r = l; r < n; r++) {
			long long now = 0;
			now += (l > 0 ? pref[l - 1] : 0);
			now += pref[n - 1] - pref[r];

			long long rev = dp[l][r];
			rev -= (r + 1 < n && l > 0 ? dp[r + 1][l - 1] : 0);

			ans = max(ans, now + rev);
		}
	}
	cout << ans << '\n';
	return 0;
}