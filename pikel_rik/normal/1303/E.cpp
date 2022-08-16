#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		string s, t;
		cin >> s >> t;

		int n = s.length(), m = t.length();

		int jj = 0;
		for (int i = 0; i < n && jj < m; i++) {
			if (s[i] == t[jj]) jj++;
		}

		if (jj == m) {
			cout << "YES\n";
			continue;
		}

		bool possible = false;
		for (int ii = 0; ii < m - 1; ii++) {
			string t1 = t.substr(0, ii + 1), t2 = t.substr(ii + 1);
			int l1 = ii + 1, l2 = m - ii - 1;

			vector<vector<int>> dp(n, vector<int>(l1 + 1, -1));

			if (t1[0] == s[0]) {
				dp[0][1] = 0;
			}
			if (t2[0] == s[0]) {
				dp[0][0] = 1;
			} else {
				dp[0][0] = 0;
			}

			for (int i = 1; i < n; i++) {
				for (int j = 0; j <= min(l1, i + 1); j++) {
					dp[i][j] = dp[i - 1][j];
					if (dp[i - 1][j] == l2) {
						continue;
					}
					if (dp[i - 1][j] != -1 && t2[dp[i - 1][j]] == s[i]) {
						dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j]);
					}
					if (j > 0 && dp[i - 1][j - 1] != -1 && t1[j - 1] == s[i]) {
						dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
					}
				}
			}

			possible |= dp[n - 1][l1] == l2;
		}

		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}