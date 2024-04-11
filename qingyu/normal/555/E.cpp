// By Qingyu
#include <bits/stdc++.h>

const int N = 1e6 + 50;

struct fastio
{
	static const int SIZ = 1 << 20;
	char p[SIZ], q[SIZ], *p1 = p, *p2 = p, *q1 = q, *q2 = q + SIZ;
	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, SIZ, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char c)
	{
		if (q1 == q2) q2 = (q1 = q) + fwrite(q, 1, SIZ, stdout);
		*q1++ = c;
	}
	~fastio()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
} io;

int n, m, q;
int head[N], nxt[N], ver[N], c[N], f[N], siz[N], dep[N], son[N], top[N], rt[N], cnt = 1;
bool bridge[N];
int dfn[N], low[N], col[N], tot, ctot;
int up[N], dw[N];
std::vector<std::vector<int> > G;

inline void tarjan(int x, int e = -1)
{
	dfn[x] = low[x] = ++tot;
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if (!dfn[y])
		{
			tarjan(y, i ^ 1);
			low[x] = std::min(low[x], low[y]);
			if (low[y] > dfn[x])
			{
				bridge[i] = bridge[i ^ 1] = true;
			}
		}
		else if (i != e)
		{
			low[x] = std::min(low[x], dfn[y]);
		}
	}
}

void dfs(int x)
{
	col[x] = ctot;
	for (int i = head[x]; i; i = nxt[i])
		if (!bridge[i] && !col[ver[i]]) dfs(ver[i]);
}

void dfs1(int x, int fa, int d, int r)
{
	f[x] = fa, dep[x] = d, siz[x] = 1, rt[x] = r;
	int maxson = -1;
	for (int y : G[x])
	{
		if (y != fa)
		{
			dfs1(y, x, d + 1, r);
			siz[x] += siz[y];
			if (maxson < siz[y])
			{
				maxson = siz[y];
				son[x] = y;
			}
		}
	}
}

void dfs2(int x, int topf)
{
	top[x] = topf;
	if (son[x])
	{
		dfs2(son[x], topf);
		for (int y : G[x])
		{
			if (y != f[x] && y != son[x]) dfs2(y, y);
		}
	}
}

inline int LCA(int x, int y)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = f[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

inline void add(int u, int v)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	head[u] = cnt;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}

inline void putint(int x)
{
	if (x / 10) putint(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int x, char c = ' ')
{
	putint(x);
	io.pc(c);
}

bool calced[N];

void dfs3(int x)
{
	calced[x] = true;
	for (int y : G[x])
		if (y != f[x])
		{
			dfs3(y);
			up[x] += up[y], dw[x] += dw[y];
		}
}

bool solve()
{
	for (int _ = 1; _ <= q; ++_)
	{
		int u = col[read()], v = col[read()];
		if (rt[u] != rt[v]) return false;
		int g = LCA(u, v);
		++up[u], --up[g];
		++dw[v], --dw[g];
	}
	for (int i = 1; i <= ctot; ++i) if (!calced[rt[i]]) dfs3(rt[i]);
	for (int i = 1; i <= ctot; ++i) if (up[i] && dw[i]) return false;
	return true;
}

int main()
{
	n = read(), m = read(), q = read();
	for (int i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		add(u, v), add(v, u);
	}
	for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; ++i) if (!col[i]) ++ctot, dfs(i);
	G.assign(ctot + 1, std::vector<int>());
	for (int x = 1; x <= n; ++x)
		for (int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i];
			if (col[x] != col[y])
			{
				G[col[x]].emplace_back(col[y]);
			}
		}
	n = ctot;
	for (int i = 1; i <= ctot; ++i)
		if (!rt[i])
		{
			dfs1(i, 0, 1, i);
			dfs2(i, i);
		}
	puts(solve() ? "Yes" : "No");
	return 0;
}