#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> tag(n);
		for (auto &x : tag) cin >> x;

		vector<int> s(n);
		for (auto &x : s) cin >> x;

		vector<long long> dp(n);
		for (int i = 1; i < n; i++) {
			vector<long long> new_dp = dp;
			for (int j = 0; j < i; j++) {
				if (tag[j] != tag[i]) {
					new_dp[i] = max(new_dp[i], dp[j] + abs(s[i] - s[j]));
				}
			}
			long long mx = 0;
			for (int j = i - 1; j >= 0; j--) {
				if (tag[j] != tag[i]) {
					new_dp[j] = max(new_dp[j], mx + abs(s[j] - s[i]));
					mx = max(mx, dp[j] + abs(s[i] - s[j]));
				}
			}
			dp.swap(new_dp);
		}

		cout << *max_element(dp.begin(), dp.end()) << '\n';
	}
	return 0;
}