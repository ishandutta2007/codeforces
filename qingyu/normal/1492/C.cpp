#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, m, f[N], g[N];
char s[N], t[N];

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
	scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
	int p = 1;
	for (int i = 1; i <= m; ++i)
	{
		while (p <= n && s[p] != t[i]) ++p;
		f[i] = p; ++p;
	}
	p = n;
	for (int i = m; i >= 1; --i)
	{
		while (p >= 1 && s[p] != t[i]) --p;
		g[i] = p; --p;
	}
	int ans = 0;
	for (int i = 1; i < m; ++i) ans = std::max(ans, g[i + 1] - f[i]);
	printf("%d\n", ans);
}