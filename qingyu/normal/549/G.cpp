#include <bits/stdc++.h>

const int N = 1e6 + 50;
typedef long long ll;

int n, a[N];

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
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read() + i;
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) a[i] -= i;
	if (std::is_sorted(a + 1, a + n + 1))
		for (int i = 1; i <= n; ++i)
			output(a[i]);
	else io.pc(':'), io.pc('(');
	return 0;
}