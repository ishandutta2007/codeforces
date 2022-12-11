#include <stdio.h>
#include <algorithm>
#include <limits.h>

#define INF LLONG_MAX
#define N 510

long long arr[N][N];
long long dp[N][N];
long long ans[N];
int in[N], u[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			scanf("%I64d", &arr[i][j]);
			dp[i][j] = INF;
		}
		in[i] = 0;
	}
	for(int i = 1;i <= n;i++) {
		scanf("%d", &u[i]);
		ans[i] = 0;
	}
	for(int i = n;i > 0;i--) {
		int v = u[i];
		in[v] = 1;
		for(int j = 1;j <= n;j++) {
			dp[j][v] = std::min(dp[j][v], arr[j][v]);
			dp[v][j] = std::min(dp[v][j], arr[v][j]);
		}
		for(int a = 1;a <= n;a++) {
			for(int b = 1; b <= n;b++) {
				if(dp[a][v] != INF && dp[v][b] != INF) {
					dp[a][b] = std::min(dp[a][b], dp[a][v] + dp[v][b]);
				}
				if(in[a] && in[b]) {
					ans[i] += dp[a][b];
				}
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		printf("%I64d ", ans[i]);
	}
	printf("\n");
	return 0;
}