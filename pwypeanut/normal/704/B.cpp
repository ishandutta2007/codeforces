#include <bits/stdc++.h>
using namespace std;

int N, S, E, A[5005], B[5005], C[5005], D[5005], X[5005];
long long dp[2][10005];

int main() {
	scanf("%d%d%d", &N, &S, &E);
	for (int i = 0; i < N; i++) scanf("%d", &X[i]);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);
	for (int i = 0; i < N; i++) scanf("%d", &C[i]);
	for (int i = 0; i < N; i++) scanf("%d", &D[i]);
	memset(dp, 63, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		long long d = 0;
		memset(dp[i % 2], 63, sizeof(dp[i % 2]));
		if (i < N) d = X[i] - X[i - 1];
		for (int j = (i != N); j <= 2 * N; j++) {
			if (S == i) {
				dp[i % 2][j] = min(dp[i % 2][j], dp[!(i % 2)][j + 1] + C[i - 1]);
				if (j >= 1) dp[i % 2][j] = min(dp[i % 2][j], dp[!(i % 2)][j - 1] + D[i - 1]);
			}
			else if (E == i) {
				dp[i % 2][j] = min(dp[i % 2][j], dp[!(i % 2)][j + 1] + A[i - 1]);
				if (j >= 1) dp[i % 2][j] = min(dp[i % 2][j], dp[!(i % 2)][j - 1] + B[i - 1]);
			} else {
				dp[i % 2][j] = min(dp[i % 2][j], dp[!(i % 2)][j + 2] + A[i - 1] + C[i - 1]);
				if (j >= 2) dp[i % 2][j] = min(dp[i % 2][j], dp[!(i % 2)][j - 2] + B[i - 1] + D[i - 1]);
				if (j != 0) {
					if (j != 1) dp[i % 2][j] = min(dp[i % 2][j], dp[!(i % 2)][j] + min(A[i - 1] + D[i - 1], B[i - 1] + C[i - 1]));
					else {
						if (S < E) dp[i % 2][j] = min(dp[i % 2][j], dp[!(i % 2)][j] + A[i - 1] + D[i - 1]);
						else dp[i % 2][j] = min(dp[i % 2][j], dp[!(i % 2)][j] + B[i - 1] + C[i - 1]);
					}
				}
			}
			
			dp[i % 2][j] += (long long)j * d;
		}
	}
	printf("%lld\n", dp[N % 2][0]);
}