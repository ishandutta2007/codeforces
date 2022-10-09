#include <bits/stdc++.h>

constexpr int N = 5e5 + 50;

int head[N], nxt[N], ver[N], dep[N], cnt;

inline void add(int u, int v)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	head[u] = cnt;
}

inline int read()
{
	int x;
	scanf("%d", &x);
	return x; 
}

void dfs(int u, int d, int f)
{
	dep[u] = d;
	for (int i = head[u]; i; i = nxt[i])
	{
		int v = ver[i];
		if (v != f)
		{
			dfs(v, d + 1, u);
		}
	}
}

int main()
{
	int n = read();
	for (int i = 1; i < n; ++i)
	{
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}
	dfs(1, 1, -1);
	long double ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += 1.0L / dep[i];
	printf("%.10Lf", ans);
	return 0;
}