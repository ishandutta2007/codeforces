#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, m, s;
int head[N], nxt[N], ver[N], edge[N], cnt = 1, to[N];
int64_t d[N], min[N];

std::priority_queue<std::tuple<int64_t, int, int>> q;

inline void add(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	edge[cnt] = w;
	head[u] = cnt;
}

void dijkstra(int s)
{
	memset(d, 0x3f, sizeof d); memset(min, 0x3f, sizeof min);
	d[s] = 0; q.emplace(-d[s], 0, s); min[s] = 0;
	while (!q.empty())
	{
		auto [dist, len, x] = q.top(); q.pop();
		if (dist == -d[x] && len == -min[x])
		{
			for (int i = head[x]; i; i = nxt[i])
			{
				int y = ver[i];
				if (d[y] > d[x] + edge[i] || (d[y] == d[x] + edge[i] && min[y] > edge[i]))
				{
					d[y] = d[x] + edge[i];
					min[y] = edge[i];
					to[y] = i >> 1;
					q.emplace(-d[y], -min[y], y);
				}
			}
		}
	}
}

template <int T>
struct fast_io
{
	char p[T], *p1 = p, *p2 = p, q[T], *q1 = q, *q2 = q + T;
	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF: *p1++;
	}
	inline void pc(char ch)
	{
		if (q1 == q2)
		{
			q2 = (q1 = q) + fwrite(q, 1, T, stdout);
		}
		*q1++ = ch;
	}
	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};

fast_io<1000000> io;

inline int read()
{
	int res = 0; char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}

void putint(int64_t x)
{
	if (x >= 10) putint(x / 10);
	io.pc(48 + x % 10);
}

template <char ch = ' '>
void output(int64_t x)
{
	putint(x);
	io.pc(ch);
}

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w = read();
		add(u, v, w), add(v, u, w);
	}
	s = read(); dijkstra(s);
	int64_t ans = 0;
	for (int i = 1; i <= n; ++i) ans += min[i];
	printf("%lld\n", ans);
	for (int i = 1; i <= n; ++i)
	{
		if (i != s)
		{
			printf("%d ", to[i]);
		}
	}
	return 0;
}