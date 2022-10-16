#include <bits/stdc++.h>
using namespace std;

int dc[8001];

void init() {
	for (int i = 1; i <= 8000; i++) {
		dc[i] = dc[i/10] + 1;
	}
}

vector<int> kmp(string s) {
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j]) j = pi[j-1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();

	string s; cin >> s;
	int n = s.size();
	vector<int> dp(n+1, 998244353);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		vector<int> pi = kmp(s.substr(i, n));
		dp[i+1] = min(dp[i+1], dp[i] + 2);
		for (int j = i+1; j < n; j++) {
			int pr = (j-i+1) - pi[j-i];

			if ((j-i+1) % pr == 0) {
				dp[j+1] = min(dp[j+1], dp[i] + dc[(j-i+1)/pr] + pr);
			} else {
				dp[j+1] = min(dp[j+1], dp[i] + dc[1] + j-i+1);
			}
		}
	}
	cout << dp[n] << '\n';

	return 0;
}