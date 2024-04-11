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

		vector<int> c(n), a(n), b(n);
		for (auto &x : c) cin >> x;
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;

		vector<long long> dp(n);
		dp[1] = abs(b[1] - a[1]) + 2 + c[1] - 1;

		for (int i = 2; i < n; i++) {
			if (a[i] == b[i]) {
				dp[i] = 2 + c[i] - 1;
			} else {
				dp[i] = dp[i - 1] + 2 - abs(b[i] - a[i]) + c[i] - 1;
			}
			dp[i] = max(dp[i], abs(b[i] - a[i]) + 2ll + c[i] - 1);
		}

		cout << *max_element(dp.begin(), dp.end()) << '\n';
	}
	return 0;
}