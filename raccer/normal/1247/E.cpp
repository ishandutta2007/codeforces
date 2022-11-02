#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

char a[2010][2010];
int sum[2010][2010][2];
int dp[2010][2010][2];
int rr[2010][2010];
int dd[2010][2010];

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int main () {
	int n, m; scanf("%d%d", &n, &m);
	if (n == 1 && m == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			rr[i][j] = rr[i][j + 1] + (a[i][j] == 'R');
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			dd[i][j] = dd[i + 1][j] + (a[i][j] == 'R');
		}
	}
	dp[1][1][0] = dp[1][1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			add(sum[i][j][0], sum[i - 1][j][0]), add(sum[i][j][1], sum[i][j - 1][1]);
			dp[i][j][0] += sum[i][j][0], dp[i][j][1] += sum[i][j][1];
			int cnt;
			// p = 0
			cnt = rr[i][j + 1];
			add(sum[i][j + 1][1], dp[i][j][0]), add(sum[i][m - cnt + 1][1], mod - dp[i][j][0]);
			// p = 1
			cnt = dd[i + 1][j];
			add(sum[i + 1][j][0], dp[i][j][1]), add(sum[n - cnt + 1][j][0], mod - dp[i][j][1]);
		}
	}
	int ans = dp[n][m][0];
	add(ans, dp[n][m][1]);
	printf("%d\n", ans);
	return 0;
}