#include <stdio.h>

#define N 100010
#define MOD 1000000007

int dp[N];
int t, k;

int main() {
	scanf("%d%d", &t, &k);
	dp[0] = 1;
	for(int i = 1;i < N;i++) {
		dp[i] = dp[i-1];
		if(i >= k) {
			dp[i] += dp[i-k];
		}
		dp[i] %= MOD;
	}
	for(int i = 1;i < N;i++) {
		dp[i] += dp[i-1];
		dp[i] %= MOD;
	}
	while(t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int ans = (dp[b] - dp[a-1]) % MOD;
		if(ans < 0) {
			ans += MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}