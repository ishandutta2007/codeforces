#include <bits/stdc++.h>
using namespace std;

string s;
int n, dp[100001][4];

int go(int i, int msk) {
	if (i == -1) return 0;
	if (dp[i][msk] != -1) return dp[i][msk];

	int ans = n+1;
	// change this character, whatever
	ans = min(ans, go(i-1, (msk*2 + 1) % 4) + 1);

	// don't change this character
	bool applicable = 1;
	// char 1
	if (s[i] == s[i+1] && (msk % 2 == 0)) {
		applicable = 0;
	}
	if (s[i] == s[i+2] && ((msk/2) % 2 == 0)) {
		applicable = 0;
	}
	if (applicable) ans = min(ans, go(i-1, (msk*2) % 4));

	return dp[i][msk] = ans;
}

void solve() {
	cin >> s;
	n = s.size();
	s.push_back(' ');
	s.push_back('#');

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 4; j++) {
			dp[i][j] = -1;
		}
	}

	cout << go(n-1, 0) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}