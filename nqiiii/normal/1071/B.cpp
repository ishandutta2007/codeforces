#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000, inf = 0x3f3f3f3f;
int n, m, dp[maxn + 10][maxn + 10], k;
int dx[maxn + 10][maxn + 10], rk[maxn + 10][maxn + 10];
int dy[maxn + 10][maxn + 10];
int rx, ry;
char s[maxn + 10][maxn + 10];

struct pos {
	int x, y;
	bool operator < (const pos &t) const {
		return s[x][y] != s[t.x][t.y] ? s[x][y] < s[t.x][t.y] : rk[x + dx[x][y]][y + dy[x][y]] < rk[t.x + dx[t.x][t.y]][t.y + dy[t.x][t.y]];
	}
}a[maxn * 2 + 10];
int pcnt;

void travel(int x, int y) {
	while (x <= n && y <= m) {
		printf("%c", s[x][y]);
		int tx = x + dx[x][y], ty = y + dy[x][y];
		x = tx; y = ty;
	}
}


int main() {
	scanf("%d%d", &n, &k); m = n;
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	memset(dp, 0x3f, sizeof dp);
	dp[1][1] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (i > 1) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			if (j > 1) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			dp[i][j] += (s[i][j] != 'a');
		}
	memset(rk, 0x3f, sizeof rk);
	rk[n][m] = 1; dx[n][m] = 1; dy[n][m] = 1;
	for (int s = n + m; s >= 2; --s) {
		pcnt = 0;
		for (int j = 1; j <= n; ++j)
			if (j >= 1 && j <= n && s - j >= 1 && s - j <= m) 
				a[++pcnt] = (pos){j, s - j};
		for (int j = 1; j <= pcnt; ++j)
			if (rk[a[j].x + 1][a[j].y] < rk[a[j].x][a[j].y + 1]) dx[a[j].x][a[j].y] = 1;
			else dy[a[j].x][a[j].y] = 1;
		sort(a + 1, a + pcnt + 1);
		for (int j = 1; j <= pcnt; ++j)
			rk[a[j].x][a[j].y] = j;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (dp[i][j] <= k)
				if (i + j > rx + ry || (i + j == rx + ry && rk[i + dx[i][j]][j + dy[i][j]] < rk[rx + dx[rx][ry]][ry + dy[rx][ry]])) {
					rx = i; ry = j;
				}
		}
	if (rx == 0) travel(1, 1);
	else {
		for (int i = 1; i <= rx + ry - 1; ++i)
			printf("a");
		travel(rx + dx[rx][ry], ry + dy[rx][ry]);
	}
}