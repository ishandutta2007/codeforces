#include <bits/stdc++.h>

const int N = 1e6 + 50;
const int T = 550;

int n, m, q, ans[N];
char s[T][T];
std::bitset<T> f1[T][T], f2[T][T];
struct query
{
	int a, b, c, d, id;
} qu[N], S[N];

void solve(int ql, int qr, int l, int r)
{
	if (l <= r && ql <= qr)
	{
		const int mid = ql + qr >> 1;
		int pl = l - 1, pr = r + 1;
		for (int j = m; j >= 1; --j)
		{
			f1[mid][j] = 0;
			if (s[mid][j] == '.')
			{
				f1[mid][j][j] = 1;
				if (j < m) f1[mid][j] |= f1[mid][j + 1];
			}
		}
		for (int j = 1; j <= m; ++j)
		{
			f2[mid][j] = 0;
			if (s[mid][j] == '.')
			{
				f2[mid][j][j] = 1;
				if (j > 1) f2[mid][j] |= f2[mid][j - 1];
			}
		}
		for (int i = mid - 1; i >= ql; --i)
			for (int j = m; j >= 1; --j)
			{
				if (s[i][j] == '#')
				{
					f1[i][j] = 0;
					continue;
				}
				f1[i][j] = f1[i + 1][j];
				if (j < m) f1[i][j] |= f1[i][j + 1];
			}
		for (int i = mid + 1; i <= qr; ++i)
			for (int j = 1; j <= m; ++j)
			{
				if (s[i][j] == '#')
				{
					f2[i][j] = 0;
					continue;
				}
				f2[i][j] = f2[i - 1][j];
				if (j > 1) f2[i][j] |= f2[i][j - 1];
			}
		for (int i = l; i <= r; ++i)
		{
			if (qu[i].c < mid)
			{
				S[++pl] = qu[i];
				continue;
			}
			if (qu[i].a > mid)
			{
				S[--pr] = qu[i];
				continue;
			}
			ans[qu[i].id] = (f1[qu[i].a][qu[i].b] & f2[qu[i].c][qu[i].d]).any() ? 1 : 0;
		}
		for (int i = l; i <= pl; ++i) qu[i] = S[i];
		for (int i = pr; i <= r; ++i) qu[i] = S[i];
		solve(ql, mid - 1, l, pl);
		solve(mid + 1, qr, pr, r);
	}
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
	do ch = io.gc(); while (!isalpha(ch));
	do *s++ = ch, ch = io.gc(), ++len; while (isalpha(ch));
	*s = 0;
	return len;
}

inline char rc()
{
	char ch;
	do ch = io.gc(); while (ch != '.' && ch != '#');
	return ch;
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

inline void outputs(const char *s)
{
	while (*s) io.pc(*s++);
	io.pc('\n');
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			s[i][j] = rc();
	q = read();
	for (int i = 1; i <= q; ++i) qu[i].a = read(), qu[i].b = read(), qu[i].c = read(), qu[i].d = read(), qu[i].id = i;
	solve(1, n, 1, q);
	for (int i = 1; i <= q; ++i)
	{
		if (ans[i]) outputs("Yes");
		else outputs("No");
	}
	return 0;
}