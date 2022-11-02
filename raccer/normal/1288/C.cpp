#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int dp1[20][1010], dp2[20][1010];

int main () {
	int n, m; cin >> n >> m;
	dp1[0][1] = dp2[0][n] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = j; k <= n; k++) {
				dp1[i + 1][k] += dp1[i][j];
				if (dp1[i + 1][k] >= mod) dp1[i + 1][k] -= mod;
			}
			for (int k = 1; k <= j; k++) {
				dp2[i + 1][k] += dp2[i][j];
				if (dp2[i + 1][k] >= mod) dp2[i + 1][k] -= mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ans = (ans + 1ll * dp1[m][i] * dp2[m][j]) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}