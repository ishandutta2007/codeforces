#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int A = 1000;

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		int mx = *max_element(a.begin(), a.end());

		const int inf = 10 * mx;

		vector<int> dp(2 * 2 * mx + 1, inf); //dp[i] = [i, r]
		dp[0 + 2 * mx] = 0;

		vector<int> new_dp(2 * 2 * mx + 1);
		for (int i = n - 1; i >= 0; i--) {
			fill(new_dp.begin(), new_dp.end(), inf);
			for (int j = -2 * mx; j <= 2 * mx; j++) {
				if (dp[j + 2 * mx] < inf) {
					int l = j - a[i], r = max(0, -a[i] + dp[j + 2 * mx]);
					if (-2 * mx <= l && r <= 2 * mx) {
						new_dp[l + 2 * mx] = min(new_dp[l + 2 * mx], r);
					}
					l = min(0, j + a[i]), r = dp[j + 2 * mx] + a[i];
					if (-2 * mx <= l && r <= 2 * mx) {
						new_dp[l + 2 * mx] = min(new_dp[l + 2 * mx], r);
					}
				}
			}
			dp.swap(new_dp);
		}

		int ans = inf;
		for (int i = -2 * mx; i <= 2 * mx; i++) {
			ans = min(ans, dp[i + 2 * mx] - i + 1);
		}

		cout << ans - 1 << '\n';
	}
	return 0;
}