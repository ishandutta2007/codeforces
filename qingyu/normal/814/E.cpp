#include<bits/stdc++.h>

const int mod = 1e9 + 7;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

const int N = 305;
int n, f[N][N], g[N][N][N];
int c[N][N], a[N], d[N];

inline void init()
{
	c[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)c[i][j] = inc(c[i - 1][j], c[i - 1][j - 1]);
	}
	a[2] = a[3] = 1;
	for (int i = 4; i <= n; ++i)
		a[i] = mul(a[i - 1], i - 1);
	g[0][0][0] = 1;
	for (int k = 1; k <= n; ++k)
		for (int l = 3; l <= k; ++l)
			upd(g[0][0][k], mul(g[0][0][k - l], mul(c[k - 1][l - 1], a[l])));
	for (int j = 1; j <= n; ++j)
		for (int k = 0; k <= n - j; ++k)
		{
			if (j >= 2) upd(g[0][j][k], mul(g[0][j - 2][k], j - 1));
			if (k >= 1) upd(g[0][j][k], mul(g[0][j][k - 1], k));
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= n - i; ++j)
			for (int k = 0; k <= n - i - j; ++k)
			{	
				if (j > 0) upd(g[i][j][k], mul(g[i - 1][j - 1][k], j));
				if (k > 0) upd(g[i][j][k], mul(g[i - 1][j + 1][k - 1], k));
			}
}

inline int solve()
{
	int w = d[1];
	f[w + 1][w] = 1;
	for (int i = w + 2; i <= n; ++i)
		for (int j = 1; j <= i - w - 1; ++j)
			for (int k = 1, c0 = 0, c1 = 0; k < i - j; ++k)
			{
				if (d[i - j - k + 1] == 2) ++c0;
				else ++c1;
				upd(f[i][j], mul(f[i - j][k], g[j][c0][c1]));
			}
	int ans = 0, c0 = 0, c1 = 0;
	for (int i = 1; i < n; ++i)
	{
		if (d[n - i + 1] == 2) ++c0;
		else ++c1;
		upd(ans, mul(f[n][i], g[0][c0][c1]));
	}
	return ans;
}

template <int T>
struct fast_io
{
	char p[T], *p1, *p2, q[T], *q1, *q2;
	fast_io()
	{
		p1 = p2 = p, q1 = q, q2 = q + T;
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

fast_io<1000000> io;

inline int read()
{
	int r = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r;
}

inline int read(char *s)
{
	char ch; int len = 0;
	do ch = io.gc(); while (!isalpha(ch));
	do *s++ = ch, ch = io.gc(), ++len; while (isalpha(ch));
	return len;
}

void putint(int x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) putint(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int x, char ch = ' ')
{
	putint(x); io.pc(ch);
}

int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
		d[i] = read();
	init();
	output(solve());
	return 0;
}