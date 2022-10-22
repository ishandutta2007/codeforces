#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD=1e9+7;

int n, k, d, dp[101];

int solve(int x) {
	memset(dp, 0, sizeof(dp));
	dp[0]=1;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=x; ++j) {
			if (i-j>=0)
				dp[i] = (dp[i]+dp[i-j])%MOD;
		}
	}
	return dp[n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> d;
	int ans = solve(k)-solve(d-1);
	if (ans<0)
		ans += MOD;
	cout << ans;
	return 0;
}