#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD=1e8;

int n1, n2, k1, k2, dp[201][101][2]; // (total, how many 0s (means we can find # of 1s), ends with what type)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(dp, 0, sizeof(dp));
	cin >> n1 >> n2 >> k1 >> k2;
	dp[0][0][0] = dp[0][0][1] = 1;
	for (int i=1; i<=n1+n2; ++i) {
		for (int j=0; j<=n1&&j<=i; ++j) {
			for (int k=1; k<=k1; ++k) {
				if (i-k>=0&&j-k>=0)
					dp[i][j][0] = (dp[i][j][0]+dp[i-k][j-k][1])%MOD;
			}
			for (int k=1; k<=k2; ++k) {
				if (i-k>=0)
					dp[i][j][1] = (dp[i][j][1]+dp[i-k][j][0])%MOD;
			}
		}
	}
	cout << (dp[n1+n2][n1][0]+dp[n1+n2][n1][1])%MOD;
	return 0;
}