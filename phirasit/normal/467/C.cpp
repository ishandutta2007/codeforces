#include <stdio.h>
#include <algorithm>

#define N 5010

using namespace std;

long long dp[N][N];
long long arr[N];
int n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	arr[0] = 0;
	for(int i = 1;i <= n;i++) {
		scanf("%I64d", &arr[i]);
		arr[i] += arr[i-1];
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j <= k;j++) {
			if(j == 0) {
				dp[i][j] = 0;
			}else {
				if(i-m > 0) {
					dp[i][j] = max(dp[i-m][j-1] + arr[i] - arr[i-m], dp[i-1][j]);
				}else {
					dp[i][j] = max(arr[i], dp[i-1][j]);
				}
			}
		}
	}
	printf("%I64d\n", dp[n][k]);
	return 0;
}