#include <bits/stdc++.h>

const int N = 5e5 + 50;

int n, m, p[N], fa[N];
int head[N], nxt[N], ver[N], up[N], val[N], cnt;
bool vis[N], vs[N], ok[N];
inline void add(int u, int v)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	head[u] = cnt;
}

bool check(int x, int f = 0)
{
	assert(!vs[x]);
	vs[x] = vis[x] = true;
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if (!vis[y])
		{
			if (check(y, x) == false) 
			{
				vs[x] = false;
				return false;
			}
		}
		else if (!vs[y]) 
		{
			vs[x] = false;
			return false;
		}
	}
	vs[x] = false;
	return true;
}

void dfs(int x, int f = 0)
{
	vis[x] = true;
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if (!vis[y])
		{
			fa[y] = x;
			dfs(y, x);
		}
		else
		{
			int z = x;
			while (z != y)
			{
				assert(z);
				if (!val[z]) val[z] = y;
				else val[z] = -1;
				z = fa[z];	
			}
		}

	}
}
std::vector<int> ans;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void calc(int x, int f = 0)
{
	vis[x] = true;
	if (val[x] != -1)
	{
		ok[x] = ok[val[x]];
		if (ok[x]) ans.push_back(x);
	}
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if (!vis[y])
		{
			calc(y, x);
		}
	}
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
	int t = read();
	while (t--)
	{
		memset(ok, 0, (n + 1) * sizeof(bool));
		ans.clear(); ok[0] = true;
		memset(head, 0, (n + 1) * sizeof(int)); cnt = 0;
		n = read(), m = read();
		for (int i = 1; i <= n; ++i) p[i] = i;
		std::shuffle(p + 1, p + n + 1, rng);
		for (int i = 1; i <= m; ++i)
		{
			int u = read(), v = read();
			add(u, v);
		}
		int rt = -1;
		for (int i = 1; i <= n && i <= 50; ++i)
		{
			memset(vis, 0, (n + 1) * sizeof(bool));
			if (check(p[i]))
			{
				rt = p[i];
				break;
			}
		}
		if (rt == -1) puts("-1");
		else
		{
			memset(vis, 0, (n + 1) * sizeof(bool));
			memset(val, 0, (n + 1) * sizeof(int));
			dfs(rt);

			memset(vis, 0, (n + 1) * sizeof(bool));
			ok[rt] = true;
			calc(rt);
			if (5 * ans.size() < n)
			{
				puts("-1");
			}
			else 
			{
				std::sort(ans.begin(), ans.end());
				for (int z : ans) printf("%d ", z); putchar('\n');
			}
		}
	}
	return 0;
}