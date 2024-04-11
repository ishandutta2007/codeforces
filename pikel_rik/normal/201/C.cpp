#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n - 1);
	for (auto &x : a) cin >> x;

	long long ans = 0;

	for (int rot = 0; rot < 2; rot++) {
		vector<long long> suf(n);
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] == 1) {
				suf[i] = 0;
			} else {
				suf[i] = a[i] - a[i] % 2 + suf[i + 1];
			}
		}

		vector<array<long long, 2>> dp(n);
		ans = max(ans, suf[0]);

		for (int i = 1; i < n; i++) {
			if (a[i - 1] > 1) {
				dp[i][1] = a[i - 1] - a[i - 1] % 2 + dp[i - 1][1];
			}
			dp[i][0] = a[i - 1] - !(a[i - 1] % 2) + max(dp[i - 1][0], dp[i - 1][1]);
			ans = max(ans, max(dp[i][0], dp[i][1]) + suf[i]);
		}
		reverse(a.begin(), a.end());
	}
	cout << ans << '\n';
	return 0;
}