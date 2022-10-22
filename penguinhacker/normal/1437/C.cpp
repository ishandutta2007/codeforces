#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1, INF)); //minimum cost with first i elements and up to time j
		fill(dp[0].begin(), dp[0].end(), 0);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 2 * n; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(j - a[i]));
			}
		}
		int ans = *min_element(dp[n].begin(), dp[n].end());
		cout << ans << "\n";
	}
	return 0;
}