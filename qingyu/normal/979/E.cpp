#include <bits/stdc++.h>

const int N = 55;
const int mod = 1e9 + 7;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x ,y); }

int n, p, c[N], dp[N][2][2][2], pw2[N];

// dp[vertecies 1...i][parity of answer][if there's an odd-white][if there's an odd-black]

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	std::cin >> n >> p;
	for (int i = 1; i <= n; ++i) std::cin >> c[i];	
	pw2[0] = 1;
	for (int i = 1; i <= n; ++i) pw2[i] = inc(pw2[i - 1], pw2[i - 1]);
	dp[0][0][0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j : {0, 1})
			for (int w : {0, 1})
				for (int b : {0, 1})
				{
					int x = dp[i][j][w][b];
					if (x)
					{
						if (c[i + 1] != 1)
						{
							if (w)
							{
								int y = mul(pw2[i - 1], x);
								upd(dp[i + 1][j][w][b], y);
								upd(dp[i + 1][!j][w][1], y);
							}
							else upd(dp[i + 1][!j][w][1], mul(x, pw2[i]));
						}
						if (c[i + 1] != 0)
						{
							if (b)
							{
								int y = mul(pw2[i - 1], x);
								upd(dp[i + 1][j][w][b], y);
								upd(dp[i + 1][!j][1][b], y);
							}
							else upd(dp[i + 1][!j][1][b], mul(x, pw2[i]));
						}
					}
				}
	int ans = 0;
	for (int x : {0, 1})
		for (int y : {0, 1})
			upd(ans, dp[n][p][x][y]);
	std::cout << ans << '\n';
}