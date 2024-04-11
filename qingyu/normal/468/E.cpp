#include <bits/stdc++.h>

const int N = 1e5 + 50;
const int K = 55;
const int M = 3e6 + 50;
const int mod = 1e9 + 7;

int n, k, t, tot, fact[N], res[N], idr[N], idb[N], fa[N], g[K][K][2], h[K][2], siz[K];
int head[N], nxt[N], ver[N], edge[N], bc[M], ec[K], f[K][K], cnt;
bool vis[N];
std::vector<std::tuple<int, int, int> > edges;
std::vector<int> id[K];
std::vector<std::pair<int, int> > re[K][K], be[K][K];

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }

inline void add(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	edge[cnt] = w;
	head[u] = cnt;
}

inline int find(int x)
{
	while (x != fa[x])
		x = fa[x] = fa[fa[x]];
	return x;
}

void dfs(int x)
{
	vis[x] = true;
	if (x <= t) id[tot][x] = ++idr[tot];
	else id[tot][x] = ++idb[tot];
	int idx = id[tot][x];
	for (int i = head[x]; i; i = nxt[i])
	{
		++ec[tot];
		int y = ver[i];
		if (!vis[y])
		{
			dfs(y);
		}
		int idy = id[tot][y];
		if (x <= t) re[tot][idx].emplace_back(idy, edge[i]);
		else be[tot][idx].emplace_back(idy, edge[i]);
	}
}
inline void build()
{
	std::vector<int> v1, v2;
	int u, v, w;
	auto shrink = [=](std::vector<int> &v)
	{
		std::sort(v.begin(), v.end());
		v.erase(std::unique(v.begin(), v.end()), v.end());
	};
	for (auto p : edges)
	{
		std::tie(u, v, w) = p;
		v1.push_back(u), v2.push_back(v);
	}
	shrink(v1); shrink(v2); t = v1.size();
	for (auto p : edges)
	{
		std::tie(u, v, w) = p;
		u = std::lower_bound(v1.begin(), v1.end(), u) - v1.begin() + 1;
		v = std::lower_bound(v2.begin(), v2.end(), v) - v2.begin() + 1;
		add(u, t + v, w); add(t + v, u, w);
	}
	for (int i = 1; i <= t; ++i)
	{
		if (!vis[i])
		{
			++tot;
			id[tot].resize(2 * k + 1);
			dfs(i);
			ec[tot] /= 2;
		}
	}
}
inline void dp(int *res, int s1, int s2, const std::vector<std::pair<int, int> > *e)
{
	static int f[M], g[M];
	int U = 1 << s1;
	memset(f, 0, (U + 1) << 2);	
	f[0] = 1;
	for (int o = 1; o <= s2; ++o)
	{
		memcpy(g, f, U << 2);
		for (auto p : e[o])
		{
			int y = p.first - 1, w = p.second, t = 1 << y;
			for (int S = 0; S < U; ++S)
			{
				if (S >> y & 1)
				{
					upd(g[S], mul(w, f[S ^ t]));
				}
			}
		}
		memcpy(f, g, U << 2);
	}
	for (int i = 0; i <= k; ++i) res[i] = 0;
	for (int i = 0; i < U; ++i) upd(res[bc[i]], f[i]);
}
void go(int x, int f = 0)
{
	g[x][0][vis[x]] = siz[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], w = edge[i];
		if (y != f)
		{
			go(y, x);
			memset(h, 0, sizeof h);
			for (int a = 0; a <= siz[x]; ++a)
				for (int b = 0; b <= siz[y]; ++b)
				{
					int gyb = inc(g[y][b][0], g[y][b][1]);
					upd(h[a + b][0], mul(g[x][a][0], gyb));
					upd(h[a + b][1], mul(g[x][a][1], gyb));
					upd(h[a + b + 1][1], mul(g[x][a][0], mul(g[y][b][0], w)));
				}
			memcpy(g[x], h, sizeof h);
			siz[x] += siz[y];
		}
	}
}
inline void dp2(int *res, int s1, int s2, const std::vector<std::pair<int, int> > *e)
{
	memset(head, 0, (cnt + 1) << 2);
	edges.clear();
	cnt = 0;
	for (int i = 1; i <= s1 + s2; ++i) fa[i] = i;
	int cur_e = 0;
	for (int x = 1; x <= s1; ++x)
	{
		for (auto p : e[x])
		{
			int y = s1 + p.first, w = p.second, fx = find(x), fy = find(y);
			if (fx != fy)
			{
				fa[fx] = fy;
				add(x, y, w), add(y, x, w);
				++cur_e;
			}
			else
			{
				edges.emplace_back(x, y, w);
			}
		}
	}
	int sz = edges.size(), u, v, w;
	unsigned U = 1u << sz;
	for (unsigned S = 0; S < U; ++S)
	{
		for (int i = 0; i <= s1 + s2; ++i) vis[i] = false;
		bool ok = true;
		int rt = 1, kk = 0;
		for (int i = 0; i < sz; ++i)
			if (S >> i & 1)
			{
				++kk;
				std::tie(u, v, w) = edges[i];
				if (vis[u] || vis[v])
				{
					ok = false;
					break;
				}
				rt = mul(rt, w);
				vis[u] = vis[v] = true;
			}
		if (ok)
		{
			memset(g, 0, sizeof g);
			go(1);
			for (int i = 0; i <= k; ++i)
			{
				upd(res[i + kk], mul(rt, inc(g[1][i][0], g[1][i][1])));
			}
		}
	}
}
inline int solve()
{
	fact[0] = 1;	
	for (int i = 1; i < M; ++i) bc[i] = bc[i >> 1] + (i & 1);
	for (int i = 1; i <= n; ++i) fact[i] = mul(i, fact[i - 1]);
	res[0] = 1;
	memset(head, 0, sizeof head); edges.clear(); memset(vis, 0, sizeof vis);
	cnt = 0;
	for (int i = 1; i <= tot; ++i)
	{
		if ((ec[i] - idr[i] - idb[i]) < std::min(idr[i], idb[i]) / 2 + 1)
		{
			dp2(f[i], idr[i], idb[i], re[i]);
		}
		else
		{
			if (idr[i] < idb[i]) dp(f[i], idr[i], idb[i], be[i]);
			else dp(f[i], idb[i], idr[i], re[i]);
		}
		for (int j = k; j >= 0; --j)
			for (int p = 0; p < j; ++p)
				upd(res[j], mul(res[p], f[i][j - p]));
	}
	int ans = 0;
	for (int i = 0; i <= k; ++i) upd(ans, mul(res[i], fact[n - i]));
	return ans;
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
fast_io<1 << 20> io;
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
inline void read(char *s)
{
	char ch;
	do ch = io.gc(); while ((ch < 48 || ch > 57) && ch != '?');
	do *s++ = ch, ch = io.gc(); while ((ch >= 48 && ch <= 57) || ch == '?');
	*s = 0;
}
inline void put(int64_t x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}
inline void output(int64_t x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}
int main()
{
	n = read(), k = read();
	for (int i = 1; i <= k; ++i)
	{
		int x = read(), y = read(), w = read() - 1;
		edges.emplace_back(x, y, w);	
	}
	build();
	output(solve());
	return 0;
}//qwq