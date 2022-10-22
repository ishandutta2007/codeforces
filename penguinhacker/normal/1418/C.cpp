#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& i : a) {
			cin >> i;
		}
		const int INF = 1e9;
		vector<vector<int>> dp(n + 1, vector<int>(2, INF));
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			dp[i][0] = dp[i - 1][1];
			dp[i][1] = dp[i - 1][0] + a[i - 1];
			if (i >= 2) {
				dp[i][0] = min(dp[i][0], dp[i - 2][1]);
				dp[i][1] = min(dp[i][1], dp[i - 2][0] + a[i - 1] + a[i - 2]);
			}
		}
		cout << min(dp[n][0], dp[n][1]) << "\n";
	}

	return 0;
}