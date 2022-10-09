#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, g[N][2];
bool s[N];

void dfs(int o)
{
	if (g[o][1])
	{
		if (g[o][0] && g[o - 1][1]) putchar('0'), --g[o][0], dfs(o - 1);
		else putchar('1'), --g[o][1], dfs(o + 1);
	}
	else if (g[o][0])
	{
		putchar('0');
		--g[o][0];
		dfs(o - 1);
	}
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

inline int read(bool *s)
{
	int tot = 0; char ch;
	do ch = io.gc(); while (ch != 48 && ch != 49);
	do ++tot, *s++ = ch - 48, ch = io.gc(); while (ch == 48 || ch == 49);
	*s = 0;
	return tot;
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
	int T = read();
	while (T--)
	{
		n = read(s + 1);
		for (int i = 0; i <= n * 2; ++i) g[i][0] = g[i][1] = 0;
		int o = n;
		for (int i = 1; i <= n; ++i)
		{
			if (s[i]) ++g[o][1], ++o;
			else ++g[o][0], --o;;
		}
		dfs(n); putchar('\n');
	}
	return 0;
}