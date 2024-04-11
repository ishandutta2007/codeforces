#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e4 + 50;

int p[N], s[N];
ll dp[2][N];

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? exit(0), EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main()
{
	int n = read(), c = read();
	for (int i = 1; i <= n; ++i) p[i] = read();
	for (int i = 1; i <= n; ++i) s[i] = read();
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int o = i & 1;
		dp[o][0] = dp[o ^ 1][0] + p[i];
		for (int j = 1; j <= i; ++j)
		{
			dp[o][j] = std::min(dp[o ^ 1][j - 1] + s[i], dp[o ^ 1][j] + 1ll * j * c + p[i]);
		}
	}
	int o = n & 1; ll ans = 1e18;
	for (int i = 0; i <= n; ++i) ans = std::min(ans, dp[o][i]);
	printf("%lld", ans);
}