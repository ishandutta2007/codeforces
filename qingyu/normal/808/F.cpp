// By Little Qingyu
#include <bits/stdc++.h>

typedef long long ll;
const int N = 5e4 + 50;
const int M = 2e5 + 50;
const int inf = 0x3f3f3f3f;

int n, m, s, t, k, pr[M], pcnt, p[N], c[N], l[N], cur_head[N], cur_edge[N], cur_cnt;
int head[N], nxt[N], ver[N], edge[N], d[N], cur[N], cnt = 1;
bool isnt_p[M];

inline void add(int u, int v, int w)
{
	nxt[++cnt] = head[u], ver[cnt] = v, edge[cnt] = w, head[u] = cnt;
	nxt[++cnt] = head[v], ver[cnt] = u, edge[cnt] = 0, head[v] = cnt;
}

inline void init(int n)
{
	isnt_p[1] = true;
	for (int i = 2; i <= n; ++i)
	{
		if (!isnt_p[i]) pr[++pcnt] = i;
		for (int j = 1; j <= pcnt && i * pr[j] <= n; ++j)
		{
			isnt_p[i * pr[j]] = true;
			if (i % pr[j] == 0) break;
		}
	}
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

inline int go()
{
	int flow = 0, maxflow = 0;
	while (dfs()) while (flow = dinic(s, 0x3f3f3f3f)) maxflow += flow;
	return maxflow;
}

inline bool check(int mid)
{
	memcpy(edge, cur_edge, sizeof cur_edge);
	memcpy(head, cur_head, sizeof cur_head);
	cnt = cur_cnt;
	int sum = 0, uu = -1, cc = 0;
	for (int i = 1; i <= n; ++i)
	       	if (l[i] <= mid)
		{	
			if (c[i] == 1) 
			{
				uu = i;
				cc = std::max(cc, p[i]);
			}
			else
			{
				sum += p[i];
				if (c[i] & 1) add(s, i, p[i]);
				else add(i, t, p[i]);
			}
		}
	if (uu != -1) add(s, uu, cc); 
	sum += cc;
	int cur = sum - go();
	return cur >= k;
}

int main()
{
	n = read(), k = read(); s = n + 1, t = s + 1;
	init(2e5);
	for (int i = 1; i <= n; ++i) p[i] = read(), c[i] = read(), l[i] = read();
	for (int i = 1; i <= n; ++i)
		if (c[i] & 1)
			for (int j = 1; j <= n; ++j)
				if (!(c[j] & 1))
				{
					if (!isnt_p[c[i] + c[j]])
					{
						add(i, j, 0x3f3f3f3f);
					}
				}
	memcpy(cur_edge, edge, sizeof edge);
	memcpy(cur_head, head, sizeof head);
	cur_cnt = cnt;
	int L = 1, R = n, ans = -1;
	while (L <= R)
	{
		const int mid = L + R >> 1;
		if (check(mid)) ans = mid, R = mid - 1;
		else L = mid + 1;
	}
	printf("%d", ans);
	return 0;
}