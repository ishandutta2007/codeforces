#include <bits/stdc++.h>

const int N = 500;
const int M = 2e5 + 50;
const int K = 500;

int head[N], nxt[M], ver[M], edge[M], sp[K], c[K], b[K][K], pw[K], cnt = 1;
int n, m, s, t, p[N], cur[N], d[N], tp, unlu[M], unlv[M], ttot, bu[K * K], bv[K * K];

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
			int k = dinic(y, std::min(rest, edge[i]));
			if (!k) d[y] = 0;
			edge[i] -= k, edge[i ^ 1] += k, rest -= k;
			if (!rest) break;
		}
	return flow - rest;
}

inline int go()
{
	int flow = 0, maxflow = 0;
	while (dfs())
		while (flow = dinic(s, 0x3f3f3f3f))
			maxflow += flow;
	return maxflow;
}

int deg[K], tree_eu[K], tree_ev[K], tot, w[K][K];
inline void generate_tree()
{
	tot = 0;
	for (int i = 1; i <= tp; ++i) deg[i] = 1;
	for (int i = 1; i <= tp - 2; ++i) ++deg[p[i]];
	std::priority_queue<int, std::vector<int>, std::greater<int> > que;
	for (int i = 1; i <= tp; ++i) if (deg[i] == 1) que.emplace(i);
	for (int i = 1; i <= tp - 2; ++i)
	{
		int x = que.top(); que.pop();
		tree_eu[++tot] = x, tree_ev[tot] = p[i];
		if (--deg[p[i]] == 1) que.emplace(p[i]);
	}
	tree_eu[++tot] = tp, tree_ev[tot] = que.top();
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
inline int read()
{
	int res = 0;
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
inline int rn()
{
	char ch; int c = 0;
	do ch = io.gc(); while (ch != '?');
	do ++c, ch = io.gc(); while (ch == '?');
	return c;
}
inline void put(int x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}
inline void output(int x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}

inline int digitlength(int n)
{
	if (n < 1e1) return 1;
	if (n < 1e2) return 2;
	if (n < 1e3) return 3;
	if (n < 1e4) return 4;
	if (n < 1e5) return 5;
	return 6;
}

void solve(int x)
{
	if (x >= tp - 1)
	{
		memset(w, 0, sizeof w);
		generate_tree();
		for (int i = 1; i < n; ++i)
		{
			if (unlu[i] > unlv[i]) std::swap(unlu[i], unlv[i]);
			++w[unlu[i]][unlv[i]];
		
		}
		for (int i = 1; i < tp; ++i)
		{
			if (tree_eu[i] > tree_ev[i])
				std::swap(tree_eu[i], tree_ev[i]);
			--w[tree_eu[i]][tree_ev[i]];
			if (w[tree_eu[i]][tree_ev[i]] < 0)
				return;
		}
		memset(head, 0, sizeof head); cnt = 1;
		s = ttot + tp + 1, t = s + 1;
		const int inf = 1e6;
		int sumofwij = 0;
		for (int i = 1; i <= tp; ++i)
			for (int j = i; j <= tp; ++j)
			{
				sumofwij += w[i][j];
				add(s, b[i][j], w[i][j]);
				add(b[i][j], ttot + i, inf);
				add(b[i][j], ttot + j, inf);
			}
		for (int i = 1; i <= tp; ++i)
			add(ttot + i, t, c[i]);
		int flow = go();
		if (flow == n - tp)
		{
			std::vector<std::pair<int, int>> edges;
			for (int x = 1; x <= tp; ++x)
			{
				int st = sp[x];
				for (int i = head[ttot + x]; i; i = nxt[i])
				{
					int y = ver[i];
					if (y != t && edge[i])
					{
						if (x == bu[y]) 
						{
							for (int _ = 0; _ < edge[i]; ++_)
							{
								edges.emplace_back(++st, sp[bv[y]]);
								assert(digitlength(st) == x); assert(digitlength(sp[bv[y]] == y));
							}
						}
						else 
						{
							for (int _ = 0; _ < edge[i]; ++_)
							{
								edges.emplace_back(++st, sp[bu[y]]);
								assert(digitlength(st) == x); assert(digitlength(sp[bu[y]] == y));
							}
						}
					}
				}
			}
			for (int i = 1; i < tp; ++i) edges.emplace_back(sp[tree_eu[i]], sp[tree_ev[i]]);
			for (auto &[x, y] : edges)
			{
				output(x); output(y, '\n');
			}
			exit(0);
		}
	}
	else
	{
		for (int i = 1; i <= tp; ++i)
		{
			p[x] = i;
			solve(x + 1);
		}
	}
}
int main()
{
	n = read();
	for (int i = 1; i < n; ++i)
	{
		int x = rn(), y = rn();
		if (x > y) std::swap(x, y);
		unlu[i] = x, unlv[i] = y;
	}
	if (n < 10) tp = 1;
	else if (n < 1e2) tp = 2;
	else if (n < 1e3) tp = 3;
	else if (n < 1e4) tp = 4;
	else if (n < 1e5) tp = 5;
	else tp = 6;	
	pw[0] = 1;
	for (int i = 1; i <= tp; ++i) 
	{
		pw[i] = pw[i - 1] * 10;
		sp[i] = pw[i - 1];	
	}
	for (int i = 1; i < tp; ++i)
		c[i] = pw[i] - pw[i - 1] - 1;
	c[tp] = n - pw[tp - 1];
	for (int i = 1; i <= tp; ++i)
		for (int j = i; j <= tp; ++j)
		{
			b[i][j] = ++ttot;
			bu[ttot] = i, bv[ttot] = j;
		}
	solve(1);
	output(-1, 0);
	return 0;
}