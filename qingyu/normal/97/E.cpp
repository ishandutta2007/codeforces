#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e5 + 50;
int n, m, q, head[N], nxt[N << 1], ver[N << 1], f[N], cnt;
int fa[N], dep[N], siz[N], son[N], top[N], d[N];
int tot, dfn[N], low[N];
std::pair<int, int> st[N];
int stop;
bool vis[N];

inline int find(int x)
{
	while (x != f[x])
		x = f[x] = f[f[x]];
	return x;
}

inline void add(int u, int v)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	head[u] = cnt;
}

void dfs1(int x)
{
	siz[x] = 1;
	vis[x] = true;
	int maxson = -1;
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if (!vis[y])
		{
			fa[y] = x;
			dep[y] = dep[x] + 1;
			dfs1(y);
			siz[x] += siz[y];
			if (siz[y] > maxson)
			{
				son[x] = y;
				maxson = siz[y];
			}
		}
	}
}

void dfs2(int u, int topf)
{
	top[u] = topf;
	if (son[u])
	{
		dfs2(son[u], topf);
		for (int i = head[u]; i; i = nxt[i])
		{
			int v = ver[i];
			if (fa[v] == u && v != son[u])
			{
				dfs2(v, v);
			}
		}
	}
}

inline int LCA(int u, int v)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] > dep[top[v]])
			u = fa[top[u]];
		else
			v = fa[top[v]];
	}
	return dep[u] > dep[v] ? v : u;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++tot;
	for (int i = head[u]; i; i = nxt[i])
	{
		int v = ver[i];
		std::pair<int, int> cur = std::make_pair(u, v);
		if (fa[v] == u)
		{
			st[++stop] = cur;
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
			if (low[v] >= dfn[u])
			{
				int f = 0;
				for (int j = stop;; --j)
				{
					if ((dep[st[j].first] & 1) == (dep[st[j].second] & 1))
					{
						f = 1;
						break;
					}
					if (st[j] == cur)
						break;
				}
				do
				{
					if (st[stop].first != u) d[st[stop].first] = f;
					if (st[stop].second != u) d[st[stop].second] = f;
				} while (st[stop--] != cur);
			}
		} 
		else if (dfn[v] < dfn[u] && fa[u] != v)
		{
			low[u] = std::min(low[u], dfn[v]);
			st[++stop] = cur;
		}
	}
}

inline void calc(int u)
{
	d[u] += d[fa[u]];
	for (int i = head[u]; i; i = nxt[i])
	{
		int v = ver[i];
		if (fa[v] == u)
			calc(v);
	}
}



template <int T>
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
fast_io<1 << 18> io;
inline ll read()
{
	ll res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}
inline void read(char *s)
{
	char ch;
	do ch = io.gc(); while (!isalpha(ch));
	do *s++ = ch, ch = io.gc(); while (isalpha(ch));
	*s = 0;
}
inline int rb()
{
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	return ch - 48;
}
inline void put(ll x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}
inline void output(ll x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}
inline void outputs(const char *s)
{
	while (*s) io.pc(*s++);
	io.pc('\n');
}

inline bool solve(int u, int v)
{
	if (find(u) != find(v))
	{
		return false;
	}
	if ((dep[u] ^ dep[v]) & 1)
		return true;
	int lca = LCA(u, v);
	return d[u] + d[v] - (d[lca] << 1) > 0;
}
int main()
{ 
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		add(u, v), add(v, u);
		u = find(u), v = find(v);
		if (u != v) f[u] = v;
	}
	q = read();
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			dfs1(i);
			dfs2(i, i);
			tarjan(i);
			calc(i);
		}
	}
	while (q--)
	{
		int u = read(), v = read();
		outputs(solve(u, v) ? "Yes" : "No");
	}
	return 0;
}