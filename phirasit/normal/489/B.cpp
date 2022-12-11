#include <stdio.h>
#include <algorithm>

#define N 110

int dp[N][N];
int a[N], b[N];
int n, m;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i = 0;i < m;i++) {
		scanf("%d", &b[i]);
	}
	std::sort(a, a+n);
	std::sort(b, b+m);
	for(int i = n-1;i >= 0;i--) {
		for(int j = m-1;j >= 0;j--) {
			if(i == n-1 || j == m-1) {
				if(i < n-1) {
					dp[i][j] = dp[i+1][j];
				}else if(j < m-1) {
					dp[i][j] = dp[i][j+1];
				}else {
					dp[i][j] = 0;
				}
				dp[i][j] = std::max((int) dp[i][j], (int) (std::abs(a[i]-b[j]) <= 1));
			}else {
				dp[i][j] = std::max(dp[i+1][j], dp[i][j+1]);
				dp[i][j] = std::max(dp[i][j], (abs(a[i]-b[j]) <= 1) + dp[i+1][j+1]);
			}
		}
	}
	printf("%d\n", dp[0][0]);
	return 0;
}