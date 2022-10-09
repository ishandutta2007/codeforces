#include <bits/stdc++.h>

typedef long long ll;
const int T = 1e5 + 50;
const int N = 4e6 + 50;
const int inf = 0x3f3f3f3f;

int n, m, s, t, q, rightest[N];
int head[T], nxt[N], ver[N], edge[N], d[T], cur[T], cnt = 1;

struct event
{
	int x, y1, y2, type;
	event(int x, int y1, int y2, int type) : x(x), y1(y1), y2(y2), type(type)
	{

	}
	inline bool operator<(const event& e) 
	{ 
		return x != e.x ? x < e.x : type < e.type; 
	}
};

struct rectangle
{
	int x1, y1, x2, y2;
	rectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2)
	{

	}
};

int node_tot;

inline void add(int u, int v, int w)
{
	nxt[++cnt] = head[u], ver[cnt] = v, edge[cnt] = w, head[u] = cnt;
	nxt[++cnt] = head[v], ver[cnt] = u, edge[cnt] = 0, head[v] = cnt;
}


inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

struct SegmentTree
{
	int id[N];
	std::vector<int> leaves, pool;
	void build(int o, int l, int r, bool d)
	{
		id[o] = ++node_tot;
		if (l != r)
		{
			const int mid = l + r >> 1;
			build(lc(o), l, mid, d);
			build(rc(o), mid + 1, r, d);
			if (d)
			{
				add(id[lc(o)], id[o], inf);
				add(id[rc(o)], id[o], inf);
			}
			else
			{
				add(id[o], id[lc(o)], inf);
				add(id[o], id[rc(o)], inf);
			}
		}
		else leaves.emplace_back(id[o]);
	}
	void search(int o, int l, int r, int ql, int qr)
	{
		if (ql <= l && r <= qr) pool.emplace_back(id[o]);
		else
		{
			const int mid = l + r >> 1;
			if (ql <= mid) search(lc(o), l, mid, ql, qr);
			if (qr > mid) search(rc(o), mid + 1, r, ql, qr);
		}
	}
	std::vector<int> extract(int l, int r)
	{
		pool.clear();
		search(1, 1, n, l, r);
		return pool;
	}
} T1, T2;

struct Segment2
{
	int tag[N], same[N];
	inline void maintain(int o, int v)
	{
		tag[o] = same[o] = v;
	}
	inline void push_up(int o)
	{
		int l = same[lc(o)], r = same[rc(o)];
		if (l == -1 || r == -1 || l != r) same[o] = -1;
		else same[o] = l;
	}
	inline void push_down(int o)
	{
		if (tag[o] != -1)
		{
			maintain(lc(o), tag[o]);
			maintain(rc(o), tag[o]);
			tag[o] = -1;
		}
	}
	void cover(int o, int l, int r, int ql, int qr, int v)
	{
		if (ql <= l && r <= qr) maintain(o, v);
		else
		{
			const int mid = l + r >> 1;
			push_down(o);
			if (ql <= mid) cover(lc(o), l, mid, ql, qr, v);
			if (qr > mid) cover(rc(o), mid + 1, r, ql, qr, v);
			push_up(o);
		}
	}
	void cover(int ql, int qr, int v)
	{
		cover(1, 1, n, ql, qr, v);
	}
	int find(int o, int l, int r, int p, int v)
	{
		push_down(o);
		if (same[o] == v) return inf;
		if (l == r) return l;
		const int mid = l + r >> 1;
		if (p <= mid)
		{
			int val = find(lc(o), l, mid, p, v);
			if (val != inf) return val;
		}
		return find(rc(o), mid + 1, r, p, v);
	}
	int query(int o, int l, int r, int p)
	{
		if (l == r) return same[o];
		else
		{
			push_down(o);
			const int mid = l + r >> 1;
			if (p <= mid) return query(lc(o), l, mid, p);
			else return query(rc(o), mid + 1, r, p);
		}
	}
} Tree;

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
	for (int& i = cur[x]; i; i = nxt[i])
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

inline int go()
{
	int flow = 0, maxflow = 0;
	while (dfs()) while (flow = dinic(s, 0x3f3f3f3f)) maxflow += flow;
	return maxflow;
}

inline char nc()
{
	static char buf[1000000], * p1 = buf, * p2 = buf;
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

std::vector<event> eve;
std::vector<rectangle> rec;
inline void loadBannedRectangles()
{
	for (int i = 1; i <= q; ++i)
	{
		int x1 = read(), y1 = read(), x2 = read() + 1, y2 = read() + 1;
		eve.emplace_back(x1, y1, y2, 1);
		eve.emplace_back(x2, y1, y2, 0);
	}
	eve.emplace_back(n + 1, 1, n + 1, 1);
	std::sort(eve.begin(), eve.end());
}

inline int next_i(int i, int kk)
{
	if (i == kk) return inf;
	int vvv = Tree.find(1, 1, n, i, Tree.query(1, 1, n, i));
	if (vvv >= kk) return kk;
	return vvv;
}

inline void getFreeRectangles()
{
	Tree.cover(1, n, 1);
	for (auto &e : eve)
	{
		int x = e.x, y1 = e.y1, y2 = e.y2, t = e.type;
		if (t == 0)
		{
			Tree.cover(y1, y2 - 1, x);
		}
		else
		{		
			for (int i = next_i(y1, y2), last = y1; i <= y2; i = next_i(i, y2))
			{	
				int w = Tree.query(1, 1, n, i - 1);
				if (w < x)
				{
					rec.emplace_back(w, last, x - 1, i - 1);
				}
				last = i;
			}
		}
	}
}

int main()
{
	n = read(), q = read();
	loadBannedRectangles();
	getFreeRectangles();
	n += 2;
	T1.build(1, 1, n, true); T2.build(1, 1, n, false);
	s = ++node_tot, t = ++node_tot;
	
	for (int x : T1.leaves) add(s, x, 1);
	for (int x : T2.leaves) add(x, t, 1);

	for (auto &r :rec)
	{
		std::vector<int> v1 = T1.extract(r.x1, r.x2), v2 = T2.extract(r.y1, r.y2);
		for (int x : v1)
			for (int y: v2)
				add(x, y, inf);
	}	
	printf("%d", go());
	return 0;
}