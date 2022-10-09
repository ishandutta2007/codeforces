#include <bits/stdc++.h>

const int N = 1e5 + 50;
int p[N], q[N];
int ans[N], stk[N], top;

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
	int t = read();
	while (t--)
	{
		int n = read();
		for (int i = 1; i <= n; ++i) p[i] = read(), q[i] = std::max(q[i - 1], p[i]);
		int last = n;
		for (int i = n; i >= 1; --i)
		{
			if (q[i] != q[i - 1])
			{
				for (int j = i; j <= last; ++j) printf("%d ", p[j]);
				last = i - 1;
			}
		}
		putchar('\n');	
	}
	return 0;
}