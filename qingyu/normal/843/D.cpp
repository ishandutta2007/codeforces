#include <bits/stdc++.h>

const int N = 1e5 + 50;
const int M = 2e5 + 50;

int n, m, q, eu[M], ev[M];
int head[N], nxt[M], ver[M], cnt;
long long d[N], f[N], edge[M], ew[M];

inline void add(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	edge[cnt] = w;
	head[u] = cnt;
}

inline void dijkstra()
{
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	std::priority_queue<std::pair<long long, int> > que;
	que.emplace(0, 1);
	while (!que.empty())
	{
		auto [dis, x] = que.top(); que.pop();
		if (d[x] == -dis)
		{
			for (int i = head[x]; i; i = nxt[i])
			{
				int y = ver[i];
				if (d[y] > d[x] + edge[i])
				{
					d[y] = d[x] + edge[i];
					que.emplace(-d[y], y);
				}
			}
		}
	}
}

std::vector<int> v[M];
inline void maintain()
{
	for (int i = 0; i <= m; ++i) v[i].clear();
	for (int i = 1; i <= n; ++i) d[i] = m;
	d[1] = 0;
	v[0].push_back(1);
	for (int p = 0; p <= m; ++p)
	{
		for (int i = 0; i < v[p].size(); ++i)
		{
			int x = v[p][i];
			if (d[x] == p)
			{
				for (int i = head[x]; i; i = nxt[i])
				{
					int y = ver[i];
					if (d[y] > d[x] + edge[i])
					{
						d[y] = d[x] + edge[i];
						v[d[y]].push_back(y);
					}
				}
			}
		}
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

inline void putint(int64_t x)
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

inline void output(int64_t x, char ch = ' ')
{
	putint(x);
	io.pc(ch);
}

int main()
{
	n = read(), m = read(), q = read();
	for (int i = 1; i <= m; ++i)
	{
		int x = read(), y = read(), z = read();
		add(x, y, z);
		eu[i] = x, ev[i] = y, ew[i] = z;
	}
	dijkstra();
	for (int i = 1; i <= q; ++i)
	{
		int op = read(), c = read();
		if (op == 1)
		{
			if (d[c] >= 1e18) output(-1, '\n');
			else output(d[c], '\n');
		}
		else
		{
			for (int i = 1; i <= n; ++i) f[i] = d[i];
			for (int i = 1; i <= m; ++i) 
			{
				edge[i] = d[eu[i]] + ew[i] - d[ev[i]];
			}
			for (int i = 1; i <= c; ++i)
			{
				int x = read();
				++edge[x]; ++ew[x];
			}
			maintain();
			for (int i = 1; i <= n; ++i) 	
			{
				d[i] += f[i];
				d[i] = std::min(d[i], (long long)1e18);
			}
		}
	}
	return 0;
}