#include <stdio.h>

#define N 50

int dp[N][N][N][N];
int sum[N][N];
char str[N][N];

int n, m, q;

int val(int a, int b, int c, int d) {
	int ans = 0;
	ans += sum[c][d];
	if(a > 0) ans -= sum[a-1][d];
	if(b > 0) ans -= sum[c][b-1];
	if(a > 0 && b > 0) ans += sum[a-1][b-1];
	return ans;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0;i < n;i++) {
		scanf("%s", str[i]);
	}
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			sum[i][j] = (str[i][j] == '1');
			if(i) sum[i][j] += sum[i-1][j];
			if(j) sum[i][j] += sum[i][j-1];
			if(i && j) sum[i][j] -= sum[i-1][j-1];
		}
	}
	for(int i = n-1;i >= 0;i--) {
		for(int j = m-1;j >= 0;j--) {
			for(int ii = i;ii < n;ii++) {
				for(int jj = j;jj < m;jj++) {
					int cnt = 0;
					for(int iii = i;iii <= ii;iii++) {
						for(int jjj = j;jjj <= jj;jjj++) {
							if(val(iii, jjj, ii, jj) == 0) {
								cnt++;
							}
						}
					}
					if(ii > i) cnt += dp[i][j][ii-1][jj];
					if(jj > j) cnt += dp[i][j][ii][jj-1];
					if(ii > i && jj > j) cnt -= dp[i][j][ii-1][jj-1];
					dp[i][j][ii][jj] = cnt;
				}
			}
		}
	}
	for(int i = 0;i < q;i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", dp[a-1][b-1][c-1][d-1]);
	}
	return 0;
}