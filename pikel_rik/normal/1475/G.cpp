#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int N = (int)2e5;

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> cnt(N + 1), dp(N + 1);
		for (auto &x : a) cnt[x]++;

		for (int i = N; i >= 1; i--) {
			if (!cnt[i]) continue;
			dp[i] = cnt[i];
			for (int j = 2 * i; j <= N; j += i) {
				dp[i] = max(dp[i], cnt[i] + dp[j]);
			}
		}

		cout << n - *max_element(dp.begin(), dp.end()) << '\n';
	}
	return 0;
}