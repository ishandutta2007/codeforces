#include <bits/stdc++.h>

const int N = 1e6 + 50;
int dist[305][35][1305];
int tot, d[305][35];
int v[N][35];

int myi(int a)
{
	for (int i = 1; i <= tot; ++i)
	{
		bool ok = true;
		for (int j = 1; j <= 8; ++j)
			if (d[i][j] != v[a][j])
				ok = false;
		if (ok) return i;
	}
	throw;
}

uint64_t get_hash(int *v)
{
	uint64_t r = 1;
	for (int i = 1; i <= 8; ++i)
		r = (r * 233 + v[i]);
	return r;
}

inline void init()
{
	std::set<uint64_t> s;
	for (int i = 1; i <= 1e6; ++i)
	{
		int t = 0, y = i;
		for (int j = 2; j * j <= y; j++)
			if (y % j == 0)
			{
				++t;
				while (y % j == 0)
				{
					++v[i][t];
					y /= j;
				}
			}
		if (y > 1) ++v[i][++t];
		std::sort(v[i] + 1, v[i] + 9);
		uint64_t r = get_hash(v[i]);
		if (!s.count(r))
		{
			++tot;
			for (int j = 1; j <= 8; ++j)
				d[tot][j] = v[i][j];
			s.insert(r);
		}
	}
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= tot; ++i)
	{
		dist[i][0][1] = 0;
		for (int j = 1; j <= 30; ++j)
			for (int k = 1; k < 1300; ++k)
				if (dist[i][j - 1][k] < 0x3f3f3f3f)
					for (int p = 0; k * (p + 1) < 1300 && p <= 30; ++p)
						dist[i][j][k * (p + 1)] = std::min(dist[i][j][k * (p + 1)], dist[i][j - 1][k] + std::abs(d[i][j] - p));
	}
}

template <long long T>
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
fast_io<1 << 20> io;
inline long long read()
{
	long long res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}
inline void put(int64_t x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}
inline void output(int64_t x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}

int main()
{
	init();
	int t = read();
	while (t--)
	{
		int a = myi(read()), b = myi(read());
		int ans = 1e9;
		for (int i = 0; i < 1300; ++i)
			ans = std::min(ans, dist[a][30][i] + dist[b][30][i]);
		output(ans, '\n');
	}
	return 0;
}