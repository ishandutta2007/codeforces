#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	sort(a.begin(), a.end());

	vector<vector<long long>> dp(n, vector<long long>(n));
	for (int l = 2; l <= n; l++) {
		for (int i = 0; i + l <= n; i++) {
			int j = i + l - 1;
			dp[i][j] = a[j] - a[i] + min(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[0][n - 1] << '\n';
	return 0;
}