#include <bits/stdc++.h>

const int N = 105;
const int mod = 998244353;

int n, l[N], r[N], b[N], f[N], g[N], inve[N], tot;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }
inline int fastpow(int x, int p)
{
	int r = 1;
	while (p)
	{
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

template<int T>
struct fast_io
{
	char p[T], q[T], *p1, *p2, *q1, *q2;

	fast_io()
	{
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}

	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}

	inline void pc(char c)
	{
		if (q1 == q2)
		{
			fwrite(q, 1, T, stdout);
			q1 = q;
		}
		*q1++ = c;
	}

	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};

fast_io<2000000> io;

inline int64_t read()
{
	int64_t r = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	}
	while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

inline void putint(int x)
{
	if (x < 0)
	{
		io.pc('-');
		putint(-x);
		return;
	}
	if (x / 10) putint(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int x, char ch = ' ')
{
	putint(x);
	io.pc(ch);
}
int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
	{
		l[i] = read(), r[i] = read() + 1;
		b[++tot] = l[i], b[++tot] = r[i];
	}
	inve[1] = 1;
	for (int i = 2; i <= n; ++i) inve[i] = mul(mod - mod / i, inve[mod % i]);
	for (int i = 1; i <= n; ++i) assert(mul(i, inve[i]) == 1);
	std::sort(b + 1, b + tot + 1);
	tot = std::unique(b + 1, b + tot + 1) - (b + 1);
	auto get = [&](int v) -> int
	{
		return std::lower_bound(b + 1, b + tot + 1, v) - b;
	};
	for (int i = 1; i <= n; ++i)
	{
		l[i] = get(l[i]), r[i] = get(r[i]);
	}
	f[0] = 1;
	for (int j = tot - 1; j > 0; --j)
	{
		int z = b[j + 1] - b[j];
		g[0] = 1;
		for (int i = 1; i <= n; ++i) g[i] = mul(g[i - 1], mul(z + i - 1, inve[i]));
		for (int i = n; i > 0; --i)
		{
			if (l[i] <= j && j < r[i])
			{
				int p = 0;
				for (int k = i - 1; k >= 0; --k)
				{
					upd(f[i], mul(g[++p], f[k]));
					if (l[k] > j || j >= r[k]) break;
				}
			}
		}
	}
	int ans = f[n];
	for (int i = 1; i <= n; ++i) pud(ans, fastpow(b[r[i]] - b[l[i]], mod - 2));
	output(ans);
	return 0;
}