#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

void solve() {
	int n = ri();
	int a[2 * n];
	for (auto &i : a) i = ri() - 1;
	
	std::vector<std::pair<int, int> > all;
	for (int i = 0; i < 2 * n; ) {
		int j = i;
		while (j < 2 * n && a[j] <= a[i]) j++;
		all.push_back({i, j});
		i = j;
	}
	int m = all.size();
	int dp[m + 1][n + 1];
	for (auto &i : dp) for (auto &j : i) j = -1;
	dp[0][0] = 0;
	for (int i = 0; i < m; i++) {
		int cur = all[i].second - all[i].first;
		for (int j = 0; j <= n; j++) {
			if (dp[i][j] == -1) continue;
			dp[i + 1][j] = 0;
			if (j + cur <= n) dp[i + 1][j + cur] = 1;
		}
	}
	puts(dp[m][n] != -1 ? "YES" : "NO");
}

int main() {
	int t = ri();
	for (int i = 0; i < t; i++) solve();
	return 0;
}