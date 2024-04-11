#include <bits/stdc++.h>
using namespace std;

int N, A[3005], B[3005], C[3005], dp[3005][2];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);
	for (int i = 0; i < N; i++) scanf("%d", &C[i]);
	memset(dp, -63, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = max(dp[i-1][0] + B[i-1], dp[i-1][1] + C[i-1]);
		dp[i][1] = max(dp[i-1][0] + A[i-1], dp[i-1][1] + B[i-1]);
	}
	printf("%d\n", dp[N][1]);
}