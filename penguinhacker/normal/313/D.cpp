#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const ll INF = 1e18;
int n, m, k;
ll c[300][300], dp[300][301];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(c, 0x3f, sizeof(c));
	memset(dp, 0x3f, sizeof(dp));
	cin >> n >> m >> k;
	for (int l, r, x; m--;) {
		cin >> l >> r >> x, --l, --r;
		c[l][r] = min(c[l][r], (ll)x);
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		if (i)
			for (int j = 0; j <= k; ++j)
				dp[i][j] = dp[i - 1][j];
		dp[i][i + 1] = c[0][i];
		ll cur = INF;
		for (int j = 1; j <= i; ++j) {
			cur = min(cur, c[j][i]);
			for (int x = i - j + 1; x <= k; ++x)
				dp[i][x] = min(dp[i][x], dp[j - 1][x - (i - j + 1)] + cur);
		}
		for (int j = 299; ~j; --j)
			dp[i][j] = min(dp[i][j], dp[i][j + 1]);
	}
	cout << (dp[n - 1][k] < INF ? dp[n - 1][k] : -1);
	return 0;
}