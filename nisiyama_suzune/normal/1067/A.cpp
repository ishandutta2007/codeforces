#include <bits/stdc++.h>

const int MOD = 998244353;

int N, A[110000];
int dp[110000][210][2];

int main () {
	scanf ("%d", &N);
	for (int i = 1; i <= N; ++i) scanf ("%d", &A[i]);
	int res = 0;
	dp[0][1][1] = 1;
	for (int i = 1; i <= N; ++i) {
		static int pre[210][2], suf[210][2];
		for (int j = 1; j <= 200; ++j) pre[j][0] = (pre[j - 1][0] + dp[i - 1][j][0]) % MOD;
		for (int j = 1; j <= 200; ++j) pre[j][1] = (pre[j - 1][1] + dp[i - 1][j][1]) % MOD;
		for (int j = 200; j >= 1; --j) suf[j][0] = (suf[j + 1][0] + dp[i - 1][j][0]) % MOD;
		for (int j = 200; j >= 1; --j) suf[j][1] = (suf[j + 1][1] + dp[i - 1][j][1]) % MOD;
		if (A[i] == -1) {
			for (int j = 1;	j <= 200; ++j) dp[i][j][0] = (pre[j - 1][0] + pre[j - 1][1]) % MOD;
			for (int j = 1;	j <= 200; ++j) dp[i][j][1] = (dp[i - 1][j][0] + suf[j][1]) % MOD;
		} else {
			int j = A[i];
			dp[i][j][0] = (pre[j - 1][0] + pre[j - 1][1]) % MOD;
			dp[i][j][1] = (dp[i - 1][j][0] + suf[j][1]) % MOD;
		}
//		for (int j = 1; j <= 200; ++j) {
//			if (dp[i][j][0] >= 1) printf ("(%d, %d, %d) = %d\n", i, j, 0, dp[i][j][0]);
//			if (dp[i][j][1] >= 1) printf ("(%d, %d, %d) = %d\n", i, j, 1, dp[i][j][1]);
//		}
	}
	for (int i = 1; i <= 200; ++i) res = (res + dp[N][i][1]) % MOD;
//	for (int i = 1; i <= 200; ++i) if (dp[N][i][1] >= 1) printf ("%d %d %d\n", N, i, dp[N][i][1]);
	printf ("%d\n", res);
}