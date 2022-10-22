#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 998244353;
int n, m, last1[1000], last2[1000], dp[1000][1000][26];
string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t, n = s.size(), m = t.size();
	last1[0] = last2[0] = -1;
	for (int i = 1; i < n; ++i)
		last1[i] = s[i] != s[i - 1] ? last1[i - 1] : i - 1;
	for (int i = 1; i < m; ++i)
		last2[i] = t[i] != t[i - 1] ? last2[i - 1] : i - 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i] ^ t[j]) {
				dp[i][j][s[i] - 'a'] += j - last2[j];
				dp[i][j][t[j] - 'a'] += i - last1[i];
			}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < 26; ++k)
				if (dp[i][j][k]) {
					dp[i][j][k] %= MOD;
					ans += dp[i][j][k];
					if (i + 1 < n && s[i + 1] - 'a' != k)
						dp[i + 1][j][s[i + 1] - 'a'] += dp[i][j][k];
					if (j + 1 < m && t[j + 1] - 'a' != k)
						dp[i][j + 1][t[j + 1] - 'a'] += dp[i][j][k];
				}
	cout << ans % MOD;
	return 0;
}