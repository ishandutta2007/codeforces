#include <bits/stdc++.h>
using namespace std;

int n, a[101], dp[101][3]; //rest, contest, gym

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> a[i];
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=0; j<3; ++j)
			dp[i][0] = min(dp[i][0], dp[i-1][j]+1);
		if (a[i]&1)
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
		if (a[i]&(1<<1))
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
	}
	int ans = 1e9;
	for (int i=0; i<3; ++i)
		ans = min(ans, dp[n][i]);
	cout << ans;
	return 0;
}