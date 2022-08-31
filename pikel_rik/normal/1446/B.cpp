#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	string s, t;
	cin >> s >> t;

	vector<vector<int>> dp(n, vector<int>(m));

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = (s[i] == t[j] ? 2 : -2);
			} else if (i == 0) {
				dp[i][j] = (s[i] == t[j] ? 2 : -1 + dp[i][j - 1]);
			} else if (j == 0) {
				dp[i][j] = (s[i] == t[j] ? 2 : -1 + dp[i - 1][j]);
			} else if (s[i] == t[j]) {
				dp[i][j] = 2 + max(0, dp[i - 1][j - 1]);
			} else {
				dp[i][j] = -1 + max(dp[i - 1][j], dp[i][j - 1]);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}