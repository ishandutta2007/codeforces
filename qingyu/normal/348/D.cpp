#include <bits/stdc++.h>

const int N = 3005;
const int mod = 1e9 + 7;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); } 

int n, m, dp[N][N], f[2][2];
char s[N][N];

int solve(int x1, int y1, int x2, int y2) {
	memset(dp, 0, sizeof dp);
	dp[x1][y1] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (s[i][j] == '#') dp[i][j] = 0;
			else {
				upd(dp[i][j], dp[i - 1][j]);
				upd(dp[i][j], dp[i][j - 1]);
			}
		}
	return dp[x2][y2];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) 
		scanf("%s", s[i] + 1);
	f[0][0] = solve(1, 2, n - 1, m);
	f[0][1] = solve(1, 2, n, m - 1);
	f[1][0] = solve(2, 1, n - 1, m);
	f[1][1] = solve(2, 1, n, m - 1);
	printf("%d\n", dec(mul(f[0][0], f[1][1]), mul(f[1][0], f[0][1])));
	return 0;
}