#include <bits/stdc++.h>

const int N = 1e5 + 50;
typedef long long ll;

int n, s, a[N];

template <int T>
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
		if (q1 == q2) q2 = (q1 = q) + fwrite(q, 1, T, stdout);
		*q1++ = c;
	}
	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1 << 18> io;
inline ll read()
{
	ll res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}
inline void read(char *s)
{
	char ch;
	do ch = io.gc(); while (!isalpha(ch));
	do *s++ = ch, ch = io.gc(); while (isalpha(ch));
	*s = 0;
}
inline int rb()
{
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	return ch - 48;
}
inline void put(ll x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}
inline void output(ll x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}

int _a[N], _b[N], _c[N], tot;
inline void move(int x, int y, int c)
{
	assert(c % x == 0);
	_a[++tot] = x;
	_b[tot] = y;
	_c[tot] = c / x;
	a[x] -= c; a[y] += c;
	assert(a[x] >= 0);
}

int main()
{
	int t = read();
	while (t--)
	{
		n = read(), s = tot = 0;
		for (int i = 1; i <= n; ++i) a[i] = read(), s += a[i];
		if (s % n)
		{
			output(-1, '\n');
		}
		else
		{
			for (int i = 2; i <= n; ++i)
			{
				int t = a[i] % i;
				if (t > 0)
				{
					move(1, i, i - t);
					assert(a[i] % i == 0);
				}
				move(i, 1, a[i]);
			}
			for (int i = 2; i <= n; ++i)
				move(1, i, s / n);
			output(tot, '\n');
			for (int i = 1; i <= tot; ++i)
			{
				output(_a[i]); output(_b[i]); output(_c[i], '\n');
			}
		}
	}
	return 0;
}