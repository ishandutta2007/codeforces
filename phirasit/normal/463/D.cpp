#include <stdio.h>

#define N 1010
#define K 10

int arr[K][N];
int pos[K][N];
int dp[N];
int n, k;

int p[K];

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0;i < k;i++) {
		for(int j = 0;j < n;j++) {
			scanf("%d", &arr[i][j]);
			pos[i][arr[i][j]] = j;
		}
	}
	int ans = 0;
	for(int i = 0;i < n;i++) {
		dp[i] = 1;
		for(int j = 0;j < i;j++) {
			bool err = false;
			for(int ii = 1;ii < k;ii++) {
				if(pos[ii][arr[0][i]] < pos[ii][arr[0][j]]) {
					err = true;
				}
			}
			if(!err && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		if(dp[i] > ans) {
			ans = dp[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}