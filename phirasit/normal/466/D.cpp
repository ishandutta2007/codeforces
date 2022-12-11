#include <stdio.h>

#define MOD 1000000007
#define N 2010

long long dp[N][N];
int arr[N];
int n, h;

int main() {
	scanf("%d%d", &n, &h);
	for(int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	if(!(0 <= h-arr[0] && h-arr[0] <= 1)) {
		printf("0\n");
		return 0;
	}
	if(h-arr[0] == 1) {
		dp[0][0] = dp[0][1] = 1;
	}else {
		dp[0][0] = 1;
	}
	for(int i = 1;i < n;i++) {
		int dif = h - arr[i];
		for(int j = 0;j <= n;j++) {
			dp[i][j] = 0;
		}
		if(dif <= i+1) {
			dp[i][dif] = (dp[i-1][dif] + dp[i-1][dif-1]) % MOD;
			if(dif > 0) {
				dp[i][dif-1] = (dif * dp[i][dif]) % MOD;
			}
		}
	}
	printf("%d\n", dp[n-1][0]);
	return 0;
}