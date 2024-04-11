#include <stdio.h>

#define N 2010
#define MOD 1000000007

int dp[N][N];
int n, k;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0;i < k;i++) {
		for(int j = 1;j <= n;j++) {
			dp[i+1][j] = 0;
		}
		for(int j = 1;j <= n;j++) {
			if(i == 0) {
				dp[i+1][j] = 1;
			}else {
				for(int p = j;p <= n;p+=j) {
					dp[i+1][p] = (dp[i+1][p] + dp[i][j]) % MOD;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		ans = (ans + dp[k][i]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}