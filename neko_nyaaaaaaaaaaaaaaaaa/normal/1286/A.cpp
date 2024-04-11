#include <bits/stdc++.h>
using namespace std;

int n, p[102], cnt[2];
int dp[102][102][102][2];

int solve(int i, int e, int o, int pr) {
	if (e < 0 || o < 0) return 100000;
	if (i == n+1) return 0;
	if (dp[i][e][o][pr] != -1) return dp[i][e][o][pr];

	if (p[i] != 0) {
		return dp[i][e][o][pr] = solve(i+1, e, o, p[i] % 2) + (pr ^ (p[i] % 2));
	}

	int ans = 100000;

	ans = min(ans, solve(i+1, e-1, o, 0) + pr);
	ans = min(ans, solve(i+1, e, o-1, 1) + (1 - pr));
	
	return dp[i][e][o][pr] = ans;
}

signed main() {
	cin >> n;
	cnt[0] = n/2;
	cnt[1] = n - cnt[0];
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] != 0) cnt[p[i] % 2]--; 
	}
	memset(dp, -1, sizeof(dp));
	
	cout << min(solve(1, cnt[0], cnt[1], 0), solve(1, cnt[0], cnt[1], 1)) << '\n';
}