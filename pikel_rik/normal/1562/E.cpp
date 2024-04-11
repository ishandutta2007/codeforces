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

		string s;
		cin >> s;

		vector<vector<int>> lcp(n, vector<int>(n));
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (s[i] == s[j]) {
					lcp[i][j] = 1 + (i + 1 < n && j + 1 < n ? lcp[i + 1][j + 1] : 0);
				}
			}
		}

		vector<long long> dp(n);
		for (int i = 0; i < n; i++) {
			dp[i] = n - i;
			for (int j = 0; j < i; j++) {
				if (s[j] < s[i]) {
					dp[i] = max(dp[i], n - i + dp[j]);
				} else if (s[j] == s[i]) {
					int k = lcp[i][j];
					if (k != n - i && s[j + k] < s[i + k]) {
						dp[i] = max(dp[i], n - i - k + dp[j]);
					}
				}
			}
		}

		cout << *max_element(dp.begin(), dp.end()) << '\n';
	}
	return 0;
}