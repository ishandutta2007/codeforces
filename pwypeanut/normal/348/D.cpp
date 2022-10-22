#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N, M, dp[3005][3005];
char g[3005][3005];

long long count_paths(int sx, int sy, int ex, int ey) {
	memset(dp, 0, sizeof(dp));
	dp[sx][sy] = 1;
	if (g[sx][sy] == '#') return 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (g[i][j] == '#') continue;
			if (i != 0) dp[i][j] += dp[i - 1][j];
			if (j != 0) dp[i][j] += dp[i][j - 1];
			dp[i][j] %= MOD;
		}
	}
	return dp[ex][ey];
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%s", &g[i]);
	printf("%lld\n", ((count_paths(0, 1, N-2, M-1) * count_paths(1, 0, N-1, M-2) - count_paths(0, 1, N-1, M-2) * count_paths(1, 0, N-2, M-1)) % MOD + MOD) % MOD);
}