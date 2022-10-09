#include <bits/stdc++.h>

const int N = 1e4 + 50;
const int M = 1e6 + 50;

int a[N], c[N], p[N];
int n, k, m, s, t, maxflow, mincost;
int head[N], nxt[M], ver[M], edge[M], cost[M], pre[N], incf[N], d[N], cnt = 1;
bool vis[N];

inline void add(int u, int v, int w, int c)
{
	nxt[++cnt] = head[u], ver[cnt] = v, edge[cnt] = w, cost[cnt] = c,  head[u] = cnt;
	nxt[++cnt] = head[v], ver[cnt] = u, edge[cnt] = 0, cost[cnt] = -c, head[v] = cnt;
}

inline bool SPFA()
{
	memset(d, 0x3f, sizeof d);
	memset(vis, 0, sizeof vis);
	std::queue<int> que;
	d[s] = 0, que.emplace(s), incf[s] = 0x3f3f3f3f;
	while (!que.empty())
	{
		int x = que.front(); que.pop(); vis[x] = false;
		for (int i = head[x]; i ; i = nxt[i])
		{
			int y = ver[i];
			if (edge[i] && d[y] > d[x] + cost[i])
			{
				d[y] = d[x] + cost[i];
				incf[y] = std::min(edge[i], incf[x]);
				pre[y] = i;
				if (!vis[y]) que.emplace(y), vis[y] = true;
			}
		}
	}
	return d[t] < 0x3f3f3f3f;
}

inline void EK()
{
	int x = t;
	while (x != s)
	{
		int i = pre[x];
		edge[i] -= incf[t];
		edge[i ^ 1] += incf[t];
		x = ver[i ^ 1];
	}
	maxflow += incf[t];
	mincost += d[t] * incf[t];
}

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) c[i] = read();
	s = 2 * n + 1, t = s + 1;
	for (int i = 1; i <= n; ++i)
		add(s, i, 1, c[a[i]]), add(i + n, t, 1, 0);
	for (int i = 1; i < n; ++i) add(i, i + 1, k - 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		if (p[a[i]]) add(i - 1, p[a[i]] + n, 1, -c[a[i]]);
		p[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) add(i, i + n, 1, 0);
	while (SPFA()) EK();
	printf("%d", mincost);
	return 0;
}