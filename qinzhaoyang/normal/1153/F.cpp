#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
const int P = 998244353;

inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
inline int mul(int x, int y) {return 1ll * x * y % P;}
inline void upd(int &x, int y) {x = add(x, y);}
inline int Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) r = mul(r, x); return r;}
inline int pw(int x) {int r = 1; for (int i = 1; i <= x; i++) r = mul(r, i); return r;}

int n, k, l, dp[N * 2][N][2];

int main() {
	scanf("%d%d%d", &n, &k, &l);
	dp[0][0][0] = 1;
	for (int i = 0; i < 2 * n + 1; i++)
		for (int j = 0; j <= n; j++) {
			for (int o = 0; o < 2; o++) {
				int t = dp[i][j][o];
				if (!t) continue;
				upd(dp[i + 1][j + 1][o], t);
				if (j) upd(dp[i + 1][j - 1][o], mul(t, j));
			}
			if (j >= k) upd(dp[i + 1][j][1], dp[i][j][0]);
		}
	int ans = dp[2 * n + 1][0][1];
	ans = mul(ans, mul(pw(n), Pow(2, n)));
	ans = mul(ans, Pow(pw(2 * n + 1), P - 2));
	printf("%d\n", mul(ans, l % P));
	return 0;
}