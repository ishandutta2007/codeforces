#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a(n); for (int& i : a) cin >> i;
		vector<vector<int>> dp(n, vector<int>(2));
		dp[0][0] = dp[0][1] = 1;
		for (int i = 1; i < n; ++i) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			if (a[i] > a[i - 1]) dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
			if (a[i] > a[i - 1] + 1) dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
			dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
			if (a[i] + 1 > a[i - 1] + 1) dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
		}
		cout << max(dp[n - 1][0], dp[n - 1][1]) << "\n";
	}
	return 0;
}