// By Little Qingyu
#include <bits/stdc++.h>

typedef long long ll;
const int N = 3e4 + 50;
const int M = 2e5 + 50;
const int inf = 0x3f3f3f3f;

int n, m, s, t;
int head[N], nxt[N], ver[N], edge[N], d[N], cur[N], cnt = 1;

inline void add(int u, int v, int w)
{
	nxt[++cnt] = head[u], ver[cnt] = v, edge[cnt] = w, head[u] = cnt;
	nxt[++cnt] = head[v], ver[cnt] = u, edge[cnt] = 0, head[v] = cnt;
}
inline bool dfs()
{
	std::queue<int> que;
	que.emplace(s);
	memset(d, 0, sizeof d); d[s] = 1;
	memcpy(cur, head, sizeof head);
	while (!que.empty())
	{
		int x = que.front(); que.pop();
		for (int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i], w = edge[i];
			if (w && !d[y])
			{
				d[y] = d[x] + 1;
				if (y == t) return true;
				que.emplace(y);
			}
		}
	}
	return false;
}

inline int dinic(int x, int flow)
{
	if (x == t) return flow;
	int rest = flow;
	for (int &i = cur[x]; i; i = nxt[i])
		if (edge[i] && d[ver[i]] == d[x] + 1)
		{
			int y = ver[i];
			ll k = dinic(y, std::min(rest, edge[i]));
			if (!k) d[y] = 0;
			edge[i] -= k, edge[i ^ 1] += k, rest -= k;
			if (!rest) break;
		}
	return flow - rest;
}

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? exit(0), EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

inline ll go()
{
	ll flow = 0, maxflow = 0;
	while (dfs()) while (flow = dinic(s, 0x3f3f3f3f)) maxflow += flow;
	return maxflow;
}

int main()
{
	n = read(), m = read(), s = n + m + 1, t = s + 1;
	for (int i = 1; i <= n; ++i) add(i, t, read());
	ll sum = 0;
	for (int i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w = read();
		sum += w;
		add(s, n + i, w);
		add(n + i, u, inf);
		add(n + i, v, inf);
	}
	printf("%lld", sum - go());
	return 0;
}