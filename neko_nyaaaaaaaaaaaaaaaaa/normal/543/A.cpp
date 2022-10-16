#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, b, M, a[501], dp[501][501][2];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> b >> M;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= b; k++) {
				if (j >= 1 && k >= a[i]) {
					dp[j][k][i & 1] = (dp[j][k][(i - 1) & 1] + dp[j - 1][k - a[i]][i & 1]) % M;
				} else {
					dp[j][k][i & 1] = dp[j][k][(i - 1) & 1];
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= b; i++) {
		ans += dp[m][i][n & 1];
		ans %= M;
	}
	
	cout << ans;
	
	return 0;
}