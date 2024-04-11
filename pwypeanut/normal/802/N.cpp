#include <bits/stdc++.h>
using namespace std;

int N, K, A[2205], B[2205];
pair<double, int> dp[2205][1105];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);
	double bot = 0, top = 2000000000, mid;
	long long ans = 0;
	memset(dp, 63, sizeof(dp));
	while (bot + 1e-08 < top) {
		mid = (bot + top)/2;
		dp[0][0] = make_pair(0, 0);
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= min(N/2, K); j++) {
				dp[i][j] = make_pair(2000000000, 0);
				if (j > 0) dp[i][j] = min(dp[i][j], make_pair(dp[i - 1][j - 1].first - mid + A[i - 1], dp[i - 1][j - 1].second + 1));
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
				dp[i][j] = min(dp[i][j], make_pair(dp[i - 1][j].first - mid + A[i - 1] + B[i - 1], dp[i - 1][j].second + 1)); 
				if (j < min(N/2, K)) dp[i][j] = min(dp[i][j], make_pair(dp[i - 1][j + 1].first + B[i - 1], dp[i - 1][j + 1].second));
			}
		}
		ans = dp[N][0].first + mid * K + 0.5;
		if (dp[N][0].second >= K) top = mid;
		else if (dp[N][0].second < K) bot = mid;
	}
	
	printf("%lld\n", ans);
}