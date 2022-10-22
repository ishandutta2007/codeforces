#include <bits/stdc++.h>
using namespace std;

int N, a[105], dp[105][2];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	memset(dp, 63, sizeof(dp));
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= N; i++) {
		bool gym_open = ((a[i - 1] & 2) > 0);
		bool contest = ((a[i - 1] & 1) > 0);
		for (int j = 0; j < 2; j++) {
			if (gym_open && j == 0) dp[i][j] = min(dp[i][j], dp[i - 1][1]);
			if (contest && j == 1) dp[i][j] = min(dp[i][j], dp[i - 1][0]);
			dp[i][j] = min(dp[i][j], dp[i - 1][0] + 1);
			dp[i][j] = min(dp[i][j], dp[i - 1][1] + 1);
		}
	}
	printf("%d\n", min(dp[N][0], dp[N][1]));
}