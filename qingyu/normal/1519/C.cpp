#include <bits/stdc++.h>

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

std::vector<int> v[200005];
int u[200005], s[200005];
int a[200005];
long long ans[200005], sum[200005], tot;
int main()
{
	int t = read();
	while (t--)
	{
		int n = read();
		for (int i = 1; i <= n; ++i) v[i].clear(), ans[i] = 0;
		for (int i = 1; i <= n; ++i)
			u[i] = read();
		for (int i = 1; i <= n; ++i)
			s[i] = read();
		for (int i = 1; i <= n; ++i) v[u[i]].emplace_back(s[i]);
		for (int i = 1; i <= n; ++i) std::sort(v[i].begin(), v[i].end(), std::greater<int>());
		for (int i = 1; i <= n; ++i)
		{
			auto z = v[i];
			tot = z.size();
			for (int i = 1; i <= tot; ++i) a[i] = z[i - 1], sum[i] = a[i] + sum[i - 1];
			for (int k = 1; k <= tot; ++k)
			{
				int rem = tot - tot % k;
				ans[k] += sum[rem];
			}
		}
		for (int i = 1; i <= n; ++i) output(ans[i]);
		io.pc('\n');
	}
	return 0;
}