#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
#define MAX_N 30
#define MAX_K 50
int main() {
	int dp[MAX_N + 1][MAX_N + 1][MAX_K + 1];
	for (auto &i : dp) for (auto &j : i) for (auto &k : j) k = 1000000000;
	for (int i = 1; i <= MAX_N; i++) dp[0][i][0] = -i * i;
	for (int i = 0; i <= MAX_N; i++) {
		for (int j = 0; j <= MAX_N; j++) {
			for (int k = 0; k <= MAX_K; k++) {
				if (dp[i][j][k] == 1000000000) continue;
				for (int l = i + 1; l <= MAX_N; l++) {
					dp[l][j][k] = std::min(dp[l][j][k], dp[i][j][k] + j * j);
					int next_k = k + j * (l - i);
					if (next_k <= MAX_K) dp[l][j][next_k] = std::min(dp[l][j][next_k], dp[i][j][k] + j * j);
				}
				for (int l = j + 1; l <= MAX_N; l++) {
					dp[i][l][k] = std::min(dp[i][l][k], dp[i][j][k] + i * i);
					int next_k = k + i * (l - j);
					if (next_k <= MAX_K) dp[i][l][next_k] = std::min(dp[i][l][next_k], dp[i][j][k] + i * i);
				}
			}
		}
	}
	int q = ri();
	for (int i = 0; i < q; i++) {
		int x = ri();
		int y = ri();
		int k = ri();
		printf("%d\n", dp[x][y][k]);
	}
	return 0;
}