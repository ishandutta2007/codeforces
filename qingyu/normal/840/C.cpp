#include <bits/stdc++.h>

const int N = 4e4 + 50;
const int mod = 1e9 + 7;

int n, a[N], b[N], pri[N], cnt, isnt_pri[N], tot;
int fact[N], inv[N];
int f[N], g[N], h[N];

inline int inc(int u, int v) { u += v; if (u >= mod) u -= mod; return u; }
inline int dec(int u, int v) { u -= v; if (u < 0) u += mod; return u; }
inline int mul(int u, int v) { return 1ll * u * v % mod; } 

inline int fastpow(int x, int p)
{
	int res = 1;
	while (p)
	{
		 if (p & 1) res = mul(res, x);
		 x = mul(x, x);
		 p >>= 1;
	}
	return res;
}

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

inline void init()
{
	n = read(); for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 2; i < N; ++i)
	{
		if (isnt_pri[i] == false)
		{
			pri[++cnt] = i;
		}
		for (int j = 1; j <= cnt && i * pri[j] < N; ++j)
		{
			isnt_pri[i * pri[j]] = true;
			if (i % pri[j] == 0) break;
		}
	}
	for (int i = 1; i < N; ++i) pri[i] = pri[i] * pri[i];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= cnt && pri[j] <= a[i]; ++j)
		{
			while (a[i] % (pri[j]) == 0) a[i] /= pri[j];
		}
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		if (a[i] == a[i - 1]) ++b[tot];
		else ++b[++tot];
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = mul(fact[i - 1], i);
	inv[n] = fastpow(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; --i) inv[i] = mul(i + 1, inv[i + 1]);
}

inline void work()
{
	int siz = 0; f[0] = 1;
	for (int i = 1; i <= tot; ++i)
	{
		int fact = 1;
		for (int j = 0; j < b[i]; ++j)
		{
			g[j] = mul(inv[j], fact);
			fact = mul(mul(fact, b[i] - j), b[i] - j - 1);
		}
		memset(h, 0, (siz + b[i] + 1) << 2);
		for (int j = 0; j <= siz; ++j) for (int k = 0; k < b[i]; ++k) h[j + k] = inc(h[j + k], mul(f[j], g[k]));
		siz += b[i] - 1;
		for (int i = 0; i <= siz; ++i) f[i] = h[i];
	}
	for (int i = 0; i <= siz; ++i) f[i] = mul(f[i], fact[n - i]);
	int ans = 0;
	for (int i = 0; i <= siz; ++i)
		if (i & 1) ans = dec(ans, f[i]);
		else ans = inc(ans, f[i]);
	printf("%d", ans);
}


int main()
{
	init();
	work();
	return 0;
}