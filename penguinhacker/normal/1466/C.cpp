#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int n = s.size();
		int ans = 0;
		for (int i = 1; i < n; ++i) {
			if (s[i] == s[i - 1] || (i >= 2 && s[i] == s[i - 2])) {
				++ans;
				for (char c = 'a'; c <= 'z'; ++c) {
					if (c == s[i - 1]) continue;
					if (i >= 2 && c == s[i - 2]) continue;
					if (i + 1 < n && c == s[i + 1]) continue;
					if (i + 2 < n && c == s[i + 2]) continue;
					s[i] = c;
					break;
				}
			}
		}
		cout << ans << "\n";
		/*if (n == 1) {cout << "0\n"; continue;}
		if (n == 2) {cout << (s[0] != s[1] ? 0 : 1) << "\n"; continue;}

		vector<vector<int>> dp(n, vector<int>(26, 1e9));
		fill(dp[0].begin(), dp[0].end(), 1);
		dp[0][s[0] - 'a'] = 0;
		for (int i = 0; i < 26; ++i) {
			dp[1][i] = 0;
			if (i == s[0] - 'a') ++dp[1][i];
			if (i != s[1] - 'a') ++dp[1][i];
		}
		for (int i = 2; i < n; ++i) {
			int c = s[i - 1] - 'a';
			for (int j = 0; j < 26; ++j) {
				for (int k = 0; k < 26; ++k) {
					if (j != k) {
						dp[i][j] = min(dp[i][j], dp[i - 2][k] + (j != c && k != c) + (j != s[i] - 'a'));
					}
				}
			}
		}
		cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";*/
	}
	return 0;
}