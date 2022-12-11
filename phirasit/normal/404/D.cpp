#include <stdio.h>
#include <string.h>

#define N 1000010
#define MOD 1000000007

char str[N];
long long dp[N][3];
int n;

int main() {
	scanf("%s", str);
	n = strlen(str);
	for(int i = 0;i < n;i++) {
		if(str[i] == '?') {
			if(i == 0) {
				dp[i][0] = 1;
				dp[i][1] = 1;
				dp[i][2] = 1;
			}else {
				dp[i][0] = (dp[i-1][0] + dp[i-1][2]) % MOD;
				dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
				dp[i][2] = (dp[i-1][1] + dp[i-1][2]) % MOD;
			}
		}else if(str[i] == '*') {
			if(i == 0) {
				dp[i][2] = 1;
			}else {
				dp[i][2] = (dp[i-1][1] + dp[i-1][2]) % MOD;
			}
		}else {
			int val = str[i] - '0';
			if(i == 0) {
				if(val == 0) {
					dp[i][0] = 1;
				}else if(val == 1) {
					dp[i][1] = 1;
				}
			}else {
				if(val == 0) {
					dp[i][0] = dp[i-1][0];
				}else if(val == 1) {
					dp[i][0] = dp[i-1][2];
					dp[i][1] = dp[i-1][0];
				}else if(val == 2) {
					dp[i][1] = dp[i-1][2];
				}
			}
		}
//		printf("%d %d - %d\n", dp[i][0], dp[i][1], dp[i][2]);
	}
	long long ans = (dp[n-1][0] + dp[n-1][2]) % MOD;
	printf("%I64d\n", ans);
	return 0;
}