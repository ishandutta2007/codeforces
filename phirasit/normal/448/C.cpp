#include <stdio.h>

#define N 5010
#define INF (-1u/2)
#define min(a, b) ((a) < (b) ? (a) : (b))

int dp[2][N];
int arr[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
	}
	for(int i = 1;i <= n;i++) {
		dp[0][i] = INF;
	}
	dp[0][0] = 0;
	for(int i = 1;i <= n;i++) {
		int idx = i % 2;
		int mn = INF;
		for(int j = n;j >= 0;j--) {
			mn = min(mn, dp[!idx][j]);
			if(mn == INF) {
				dp[idx][j] = INF;
			}else if(j < arr[i]) {
				dp[idx][j] = mn + 1;
			}else if(j == arr[i]) {
				dp[idx][j] = mn;
			}else {
				dp[idx][j] = INF;
			}
		}
		for(int j = 0;j <= min(n, arr[i]);j++) {
			if(dp[!idx][j] != INF) {
				dp[idx][j] = min(dp[idx][j], dp[!idx][j] + 1);
				if(arr[i] <= n) {
					dp[idx][arr[i]] = min(dp[idx][arr[i]], dp[!idx][j] + arr[i] - j);
				}
			}
		}
		for(int j = arr[i] + 1;j <= n;j++) {
			dp[idx][j] = INF;
		}
	}
	int ans = INF;
	for(int i = 0;i <= n;i++) {
		if(dp[n%2][i] < ans) {
			ans = dp[n%2][i];
		}
	}
	printf("%d\n", ans);
	return 0;
}