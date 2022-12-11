#include <stdio.h>

#define N 5010
#define MOD 1000000007

long long sum[N];

long long dp[N][N];
int n, k, a, b;

int main() {
	scanf("%d%d%d%d", &n, &a, &b, &k);
	for(int i = 0;i <= k;i++) {
		if(i > 0) {
			sum[0] = 0;
			for(int j = 1;j <= n;j++) {
				sum[j] = (sum[j-1] + dp[i-1][j]) % MOD;
			}
		}
		for(int j = 1;j <= n;j++) {
			if(j == b) {
				dp[i][j] = 0;
			}else if(i == 0) {
				dp[i][j] = (j == a);
			}else if(j < b) {
				dp[i][j] = sum[(j+b)/2-((j+b)%2 == 0)];
				if(j <= ((j+b)/2-((j+b)%2 == 0))) {
					dp[i][j] -= dp[i-1][j];
				}
			}else {
				dp[i][j] = sum[n] - sum[(j+b)/2]; 
				if(j > (j+b)/2) {
					dp[i][j] -= dp[i-1][j];
				}
			}
			dp[i][j] %= MOD;
			while(dp[i][j] < 0) {
				dp[i][j] += MOD;
			}
		}
	}
	long long ans = 0;
	for(int i = 1;i <= n;i++) {
		ans = (ans + dp[k][i]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}