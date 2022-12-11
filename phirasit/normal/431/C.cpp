#include <stdio.h>

#define MOD 1000000007
#define LL long long
#define N 110

LL opt[N][N][2];
int n,k,d;

int main() {
	scanf("%d%d%d", &n, &k, &d);
	for(int i = 0;i <= n;i++) {
		opt[0][i][0] = opt[0][i][1] = 0;
	}
	opt[0][0][0] = 1;
	LL ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= n;j++) {
			opt[i][j][0] = opt[i][j][1] = 0;
			for(int ii = 1;ii <= k;ii++) {
				if(ii > j) continue;
				if(ii < d) {
					opt[i][j][0] = (opt[i][j][0] + opt[i-1][j-ii][0]) % MOD;
					opt[i][j][1] = (opt[i][j][1] + opt[i-1][j-ii][1]) % MOD;
				}else {
					opt[i][j][1] = (opt[i][j][1] + opt[i-1][j-ii][0] + opt[i-1][j-ii][1]) % MOD;
				}
			}
		}
		ans = (ans + opt[i][n][1]) % MOD;
	}
	printf("%I64d\n",ans);
	return 0;
}