// By Qingyu qwq
#include <bits/stdc++.h>

typedef long long ll;

const int N = 2e5 + 50, M = 3050, mod = 998244353;

ll n, m, f[M][M], g[M][M], a[N], w[N];
ll S, S0, S1, inv[N];

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, neg = 1; char ch;
	do
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

inline ll fastpow(ll x, ll p)
{
	ll res = 1;
	while (p)
	{
		if (p & 1) res = res * x % mod;
		x = x * x %mod;
		p >>= 1;
	}
	return res;
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) 
	{
		w[i] = read();
		S += w[i];
		if (a[i]) S1 += w[i]; else S0 += w[i];
	}
	for (int i = 0; i <= (m << 1); ++i) inv[i] = fastpow(S - m  + i, mod - 2);
	for (int i = m; i >= 0; --i)
	{
		f[i][m - i] = g[i][m - i] = 1;
		for (int j = std::min(m - i - 1, S0); j >= 0; --j)
		{
			f[i][j] = ((S1 + i + 1) * f[i + 1][j] + (S0 - j) * f[i][j + 1]) % mod * inv[i - j + m] % mod;
			g[i][j] = ((S1 + i) * g[i + 1][j] + (S0 - j - 1) * g[i][j + 1]) % mod * inv[i - j + m] % mod;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (a[i]) printf("%lld\n", f[0][0] * w[i] % mod);
		else printf("%lld\n", g[0][0] * w[i] % mod);
	}
	return 0;
}