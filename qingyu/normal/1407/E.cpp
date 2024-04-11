#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, m, d[N];
int head[N], nxt[N], ver[N], edge[N], cnt;
int col[N];

inline void add(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	edge[cnt] = w;
	head[u] = cnt;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(v, u, w);
	}
	memset(d, 0x3f, sizeof d);
	memset(col, -1, sizeof col);
	d[n] = 0;
	std::queue<int> que;
	que.emplace(n);
	col[n] = 1;
	while (!que.empty())
	{
		int x = que.front(); que.pop();
		for (int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i], w = edge[i];
			if (x == y) continue;
			if (col[y] == -1)
			{
				col[y] = !w;
			}
			else
			{
				if (col[y] == w)
				{
					if (d[y] > d[x] + 1)
					{
						d[y] = d[x] + 1;
						que.emplace(y);
					}	
				}
			}
		}
	}
	if (d[1] >= 0x3f3f3f3f) d[1] = -1;
	printf("%d\n", d[1]);
	for (int i = 1; i <= n; ++i) 
	{
		if (col[i] == -1) col[i] = 0;
		putchar(48 + col[i]);
	}
	return 0;
}