#include <bits/stdc++.h>
using namespace std;

int n; 
string s;
int dp[508][508];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
		
	cin >> n >> s;

	if (n == 1) {cout << "1\n"; return 0;}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			int ans = i;
			for(int k = 1; k < i; k++) {
				ans = min(ans, dp[j][k] + dp[j + k][i - k] + (s[j] == s[i + j] && s[j] == s[k + j]));
			}
			if (s[j] == s[i + j]) ans--;

			dp[j][i] = ans;
		}
	}

	cout << dp[0][n-1] + 1;

	return 0;
}