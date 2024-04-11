#include <bits/stdc++.h>

const int mod = 1e9 + 7;
const int N = 4005;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

int len, n, A[N], k, p, dp[2][N][2][2];
char str[N];

inline int f(int x)
{
	x = std::min(x, 2 * p - 2), x = std::max(x, 0);
	auto s2 = [&](int x) -> int
	{
		return 1ll * x * (x + 1) / 2 % mod;
	};
	if (x > p - 1)
	{
		return inc(s2(std::min(p - 1, x)), dec(s2(p - 2), s2(2 * p - 2 - x - 1)));
	}
	else
	{
		return s2(std::min(p - 1, x));
	}
}

inline int g(int l, int r)
{
	r = std::min(r, 2 * p - 2), l = std::max(l, 0);
	if (l > r) return 0;
	return (r - l + 1ll + f(r) - f(l - 1) + mod) % mod;
}


template<int T>
struct fast_io
{
	char p[T], q[T], * p1, * p2, * q1, * q2;

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

inline long long read()
{
	long long r = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

inline int read(char *s)
{
	char ch;
	int len = 0;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do *s++ = ch, ch = io.gc(), ++len; while (ch >= 48 && ch <= 57);
	*s = 0;
	return len;
}

inline void putint(long long x)
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


inline void output(long long x, char ch = ' ')
{
	putint(x);
	io.pc(ch);
}

int main()
{
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	p = read(), k = read(), len = read(str + 1);
	std::reverse(str + 1, str + len + 1);
	while (len)
	{
		long long x = 0;
		for (int i = len; i >= 1; --i)
		{
			x = x * 10 + str[i] - 48;
			str[i] = x / p + 48, x %= p;
		}
		A[++n] = x;
		while (len && str[len] == 48) --len;
	}
	int v = 1, ans = 0;
	dp[0][0][1][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		memset(dp[v], 0, sizeof dp[v]);
		for (int j = 0; j < i; ++j)
		{
			for (int o = 0; o < 2; ++o)
			{
				int w0 = dp[v ^ 1][j][0][o], w1 = dp[v ^ 1][j][1][o];
				int t = 0;
				int su0 = g(A[i] - o, p - o - 1);
				int su1 = g(0, A[i] - 1 - o);
				int x = A[i] - o;
				if (x >= 0 && x <= p - o - 1)
				{
					t = std::min(x, 2 * p - 2 - x) + 1;
				}
				else t = 0;
				upd(dp[v][j][0][0], mul(su0, w0));
				upd(dp[v][j][1][0], mul(su1, w0));
				upd(dp[v][j][0][0], mul(su0 - t + mod, w1));
				upd(dp[v][j][1][0], mul(su1 + t, w1));
				if (j >= k)
				{
					int w = su1 - !o;
					if (i < n)
						upd(ans, mul(g(!o, p - o - 1), w0 + w1));
					else
						upd(ans, inc(mul(w, w0), mul(w + t, w1)));
				}
				su0 = g(A[i] - o + p, 2 * p - 2);
				su1 = g(p - o, A[i] - 1 - o + p);
				x = A[i] - o + p;
				if (p - o <= x && x <= 2 * p - 2)
				{
					t = std::min(x, 2 * p - 2 - x) + 1;
				}
				else t = 0;
				upd(dp[v][j + 1][0][1], mul(su0, w0));
				upd(dp[v][j + 1][1][1], mul(su1, w0));
				upd(dp[v][j + 1][0][1], mul(su0 - t + mod, w1));
				upd(dp[v][j + 1][1][1], mul(su1 + t, w1));
			}
		}
		v ^= 1;
	}
	output(ans);
	return 0;
}