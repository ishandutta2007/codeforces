#include <bits/stdc++.h>

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

const int N = 1e5 + 50;

struct status_t
{
	int c, k, b;
	status_t() : c(0), k(0), b(0)
	{

	}
	status_t(int c, int k, int b) : c(c), k(k), b(b)
	{

	}
};
struct counter_t
{
	int x, c, b;
	inline void reset()
	{
		x = c = b = 0;
	}
};
std::vector<status_t> f[N];

inline int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}

const int K = 40;

int n, m;

inline int solve(int x)
{
	static counter_t b[105];
	for (int i = 0; i <= K ;++i) b[i].reset();
	int ans = 0, p = 0;
	auto &v = f[x];
	auto ok = [&](int k1, int b1, int k2, int b2)
	{
		if (k1 == k2) return b1 == b2;
		int g = gcd(k1, k2);
		return (b1 - b2) % g == 0;
	};
	for (int o = 0; o < v.size(); ++o)
	{
		if (o > 0 && v[o].c != v[o - 1].c + 1)
		{
			while (p < o)
			{
				--b[v[p++].k].c;
			}
		}
		for (int k = 1; k <= K; ++k)
		{
			if (b[k].c > 0 && !ok(k, b[k].b, v[o].k, v[o].b))
			{
				while (p <= b[k].x) --b[v[p++].k].c;
			}
		}
		++b[v[o].k].c;
		b[v[o].k].b = v[o].b;
		b[v[o].k].x = o;
		ans = std::max(ans, o - p + 1);
	}
	return ans;
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
	{
		int k = read();
		for (int j = 1; j <= k; ++j)
		{
			int v = read();
			f[v].emplace_back(i, k, j - 1);
		}
	}
	for (int x = 1; x <= m; ++x)
	{
		output(solve(x), '\n');
	}
	return 0;
}