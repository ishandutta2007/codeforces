#include <bits/stdc++.h>

const int N = 5e5 + 50;

int n, m, f[N], fn[N];
std::vector<std::pair<int, int> > G[N];
int dfn[N], low[N], tot, cnt = 1;
bool bridge[N];

struct edge
{
	int u, v, w, id, ans;
} e[N];

inline bool cmp(const edge &u, const edge &v)
{
	return u.w < v.w;
}

inline bool bck(const edge &u, const edge &v)
{
	return u.id < v.id;
}

int find(int x)
{
	while (x != f[x])
		x = f[x] = f[f[x]];
	return x;
}

void tarjan_bridge(int x, int in_f = 0)
{
	dfn[x] = low[x] = ++tot;
	for (int i = 0; i < G[x].size(); ++i)
	{
		int y = G[x][i].first, id = G[x][i].second;
		if (!dfn[y])
		{
			tarjan_bridge(y, id);
			low[x] = std::min(low[x], low[y]);
			if (dfn[x] < low[y]) e[id].ans = 1;
			else e[id].ans = 0;
		}
		else if (id != in_f) low[x] = std::min(low[x], dfn[y]);
	}
}

template <int T>
struct fast_io
{
	char ib[T], ob[T], * p1, * p2, * q1, * q2;
	fast_io()
	{
		p1 = p2 = ib;
		q1 = ob;
		q2 = ob + T;
	}
	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = ib) + fread(ib, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char ch)
	{
		if (q1 == q2) q2 = (q1 = ob) + fwrite(ob, 1, T, stdout);
		*q1++ = ch;
	}
	~fast_io()
	{
		fwrite(ob, 1, q1 - ob, stdout);
	}
};
fast_io<1000000> io;

inline int read()
{
	int res = 0, neg = 1;
	char ch;
	do 
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

inline void putint(int x)
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

inline void output(int x, char ch = ' ')
{
	putint(x);
	io.pc(ch);
}

int main()
{ 
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		e[i].u = read(), e[i].v = read(), e[i].w = read(), e[i].id = i;
	}
	std::sort(e + 1, e + m + 1, cmp);
	int p = 1, cn = n;
	while (p <= m)
	{
		int p0 = p;
		while (e[p].w == e[p + 1].w) ++p;
		for (int i = p0; i <= p; ++i)
		{
			int u = find(e[i].u), v = find(e[i].v);
			if (u == v) e[i].ans = -1;
			else
			{
				G[u].push_back(std::make_pair(v, i));
				G[v].push_back(std::make_pair(u, i));
				dfn[u] = dfn[v] = 0;
			}
		}
		for (int i = p0; i <= p; ++i)
		{
			int u = find(e[i].u), v = find(e[i].v);
			if (!dfn[u]) tarjan_bridge(u);
		}
		for (int i = p0; i <= p; ++i)
		{
			int u = find(e[i].u), v = find(e[i].v);
			if (u != v)
			{
				G[u].clear();
				G[v].clear();
				f[u] = v;
			}
		}
		++p;
	}
	std::sort(e + 1, e + m + 1, bck);
	for (int i = 1; i <= m; ++i)
	{
		if (e[i].ans == -1) puts("none");
		else if (e[i].ans == 0) puts("at least one");
		else puts("any");
	}
	return 0;
}