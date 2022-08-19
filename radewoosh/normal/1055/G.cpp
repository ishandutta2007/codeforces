#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

struct point {
  int x, y;

  point(): x(0), y(0) {}

  point(int _x, int _y): x(_x), y(_y) {}

  bool read() {
    return (scanf("%d%d", &x, &y) == 2);
  }

  point operator + (const point &p) const {
    return point(x + p.x, y + p.y);
  }

  point operator - (const point &p) const {
    return point(x - p.x, y - p.y);
  }

  long long operator ^ (const point &p) const {
    return (long long) x * p.y - (long long) y * p.x;
  }

  long long operator * (const point&p) const {
    return (long long) x * p.x + (long long) y * p.y;
  }

  long long slen() const {
    return *this * *this;
  }

  int type() const {
    return x < 0 || (x == 0 && y < 0);
  }
};

bool operator < (const point &a, const point &b) {
  if (a.type() != b.type()) {
    return a.type() < b.type();
  }
  return (a ^ b) > 0;
}

ld getAlpha(const point &a, const point &b) {
  return atan2((ld) (a ^ b), (ld) (a * b));
}

bool checkPoint(const point &a, long long d) {
  return a.slen() < d * d;
}

bool checkSeg(const point &a, const point &b, long long d) {
  if (((point(0, 0) - a) * (b - a)) < 0) {
    return checkPoint(a, d);
  }
  if (((point(0, 0) - b) * (a - b)) < 0) {
    return checkPoint(b, d);
  }
  long long x = (a ^ b);
  x = x * x;
  long long y = d * d * (b - a).slen();
  return x < y;
}

bool check(const vector<point> &pol, long long d) {
  for (int i = 0; i + 1 < sz(pol); i++) {
    if (checkSeg(pol[i], pol[i + 1], d)) {
      return true;
    }
  }
  {
    ld alpha = 0;
    for (int i = 0; i + 1 < sz(pol); i++) {
      alpha += getAlpha(pol[i], pol[i + 1]);
    }
    if (alpha > 0.5) {
      return true;
    }
  }
  return false;
}

const int maxn = 205;
int w;
vector<point> pol;
int m;
point qs[maxn];
int rs[maxn];

int read() {
  int n;
  if (scanf("%d%d", &n, &w) < 2) {
    return false;
  }
  pol.resize(n);
  for (int i = 0; i < n; i++) {
    pol[i].read();
  }
  scanf("%d", &m);
  if (!m)
  {
	  printf("0\n");
	  exit(0);
  }
  for (int i = 0; i < m; i++) {
    qs[i].read();
    scanf("%d", &rs[i]);
  }
  return true;
}

using T = int;

int war[(int)5e6];

class LinkedList {
public:
	LinkedList(int N) : N(N), next(N) { clear(); }
	void clear() { head.assign(N, -1); }
	int front(int h) { return head[h]; }
	void pop(int h) { head[h] = next[head[h]]; }
	void push(int h, int u) { next[u] = head[h], head[h] = u; }
private:
	int N;
	vector<int> next, head;
};

class DoublyLinkedList {
private:
	struct Node { int prev, next; };
public:
	DoublyLinkedList(int N) : N(N), nodes(N) { clear(); }
	void clear() { head.assign(N, -1); }
	void erase(int h, int u) {
		int pv = nodes[u].prev, nx = nodes[u].next;
		if (nx >= 0) nodes[nx].prev = pv;
		if (pv >= 0) nodes[pv].next = nx;
		else head[h] = nx;
	}
	void insert(int h, int u) {
		nodes[u] = { -1, head[h]};
		if (head[h] >= 0) nodes[head[h]].prev = u;
		head[h] = u;
	}
	template <typename Func>
	void erase_all(int first, int last, Func f) {
		for (int i = first; i <= last; ++i) {
			for (int h = head[i]; h >= 0; h = nodes[h].next) f(h);
			head[i] = -1;
		}
	}
private:
	int N;
	vector<int> head;
	vector<Node> nodes;
};

template <
    typename CapType, typename TotalCapType,
    bool UseGlobal = true, bool UseGap = true
    >
class HighestLabelPushRelabel {
private:
	TotalCapType inf = pow(10., sizeof(TotalCapType) / 4 * 9);
	struct Edge { int to, rev; CapType cap; };

public:
	HighestLabelPushRelabel(int N) : N(N), E(0), G(N), que(N), list(N), dlist(N) {}

	TotalCapType maximum_flow(int s, int t) {
		if (s == t) return 0;
		fprintf(stderr, "%d %d\n", N, E);
		highest_active = 0; // highest label (active)
		highest = 0; // highest label (active and inactive)
		height.assign(N, 0); height[s] = N;
		for (int i = 0; i < N; ++i) if (i != s) dlist.insert(height[i], i);
		count.assign(N, 0); count[0] = N - 1;
		excess.assign(N, 0); excess[s] = inf; excess[t] = -inf;
		for (auto& e : G[s]) push(s, e);
		global_relabel(t);
		for (int u = -1, rest = N; highest_active >= 0; ) {
			if ((u = list.front(highest_active)) < 0) { --highest_active; continue; }
			list.pop(highest_active);
			discharge(u);
			if (--rest == 0) rest = N, global_relabel(t);
		}
		return excess[t] + inf;
	}

	inline void add_directed_edge(int u, int v, CapType cap) {
		E++;
		G[u].push_back({v, (int) G[v].size(), cap});
		G[v].push_back({u, (int) G[u].size() - 1, 0});
	}

	inline void add_undirected_edge(int u, int v, CapType cap) {
		G[u].push_back({v, (int) G[v].size(), cap});
		G[v].push_back({u, (int) G[u].size() - 1, cap});
	}

private:
	void global_relabel(int t) {
		if (!UseGlobal) return;
		height.assign(N, N); height[t] = 0;
		count.assign(N, 0);
		int qh = 0, qt = 0;
		for (que[qt++] = t; qh < qt; ) {
			int u = que[qh++], h = height[u] + 1;
			for (auto& e : G[u]) if (height[e.to] == N && G[e.to][e.rev].cap > 0) {
					count[height[e.to] = h] += 1;
					que[qt++] = e.to;
				}
		}
		// cache
		list.clear(); dlist.clear();
		for (int u = 0; u < N; ++u) if (height[u] < N) {
				dlist.insert(height[u], u);
				if (excess[u] > 0) list.push(height[u], u);
			}
		highest = highest_active = height[que[qt - 1]];
	}

	void push(int u, Edge& e) {
		int v = e.to;
		CapType df = min(excess[u], TotalCapType(e.cap));
		e.cap -= df, G[v][e.rev].cap += df;
		excess[u] -= df, excess[v] += df;
		if (0 < excess[v] && excess[v] <= df) list.push(height[v], v);
	}

	void discharge(int u) {
		int nh = N;
		for (auto& e : G[u]) if (e.cap > 0) {
				if (height[u] == height[e.to] + 1) {
					push(u, e);
					if (excess[u] == 0) return;
				} else nh = min(nh, height[e.to] + 1);
			}
		int h = height[u];
		if (UseGap && count[h] == 1) {
			auto f = [&] (int u) { count[height[u]]--, height[u] = N; };
			dlist.erase_all(h, highest, f);
			highest = h - 1;
		} else {
			count[h]--; dlist.erase(h, u);
			height[u] = nh;
			if (nh == N) return;
			count[nh]++; dlist.insert(nh, u);
			highest = max(highest, highest_active = nh);
			list.push(nh, u);
		}
	}

	int N, E, highest_active, highest;
	vector< vector<Edge> > G;
	vector<int> height, count, que;
	vector<TotalCapType> excess;
	LinkedList list;
	DoublyLinkedList dlist;
};
using HIPR_GP = HighestLabelPushRelabel<int, int, true, true>;

struct Flow {
	int n=0;
	vector<pair<pair<int,int>,int>> e;
	void add_edge(int u,int v,int c) {
		n=max(n,max(u,v)+1);
		e.push_back(make_pair(make_pair(u,v),c));
	}
};

Flow janusz;

void solve() {
  {
    int pos = 0;
    for (int i = 1; i < sz(pol); i++) {
      if (pol[i].x < pol[pos].x || (pol[i].x == pol[pos].x && pol[i].y < pol[pos].y)) {
        pos = i;
      }
    }
    rotate(pol.begin(), pol.begin() + pos, pol.end());
    point p0 = pol[0];
    for (int i = 0; i < sz(pol); i++) {
      pol[i] = pol[i] - p0;
    }
    pol.push_back(pol[0]);
  }
  int wpol = 0;
  for (int i = 0; i < sz(pol); i++) {
    wpol = max(wpol, pol[i].x);
  }
  w -= wpol;
  vector<point> psum;
  {
    vector<point> qol = pol;
    qol.pop_back();
    for (int i = 0; i < sz(qol); i++) {
      qol[i] = point(0, 0) - qol[i];
    }
    {
      int pos = 0;
      for (int i = 1; i < sz(qol); i++) {
        if (qol[i].x < qol[pos].x || (qol[i].x == qol[pos].x && qol[i].y < qol[pos].y)) {
          pos = i;
        }
      }
      rotate(qol.begin(), qol.begin() + pos, qol.end());
    }
    qol.push_back(qol[0]);
    point p0 = qol[0];
    vector<point> es0, es1, es;
    for (int i = 0; i + 1 < sz(pol); i++) {
      es0.push_back(pol[i + 1] - pol[i]);
    }
    for (int i = 0; i + 1 < sz(qol); i++) {
      es1.push_back(qol[i + 1] - qol[i]);
    }
    es.resize(sz(es0) + sz(es1));
    merge(es0.begin(), es0.end(), es1.begin(), es1.end(), es.begin());
    psum.push_back(p0);
    for (int i = 0; i < sz(es); i++) {
      p0 = p0 + es[i];
      psum.push_back(p0);
    }
  }
  int s = 2 * m, t = s + 1;
  //~ Flow::init(t + 1);
  for (int i = 0; i < m; i++) {
    //~ Flow::addEdge(2 * i, 2 * i + 1, 1);
    janusz.add_edge(2*i, 2*i+1, 1);
    int l = qs[i].x - wpol - rs[i], r = qs[i].x + rs[i];
    if (l < 0) {
      //~ Flow::addEdge(s, 2 * i, inf);
      janusz.add_edge(s, 2*i, inf);
    }
    if (w < r) {
      //~ Flow::addEdge(2 * i + 1, t, inf);
      janusz.add_edge(2*i+1, t, inf);
    }
    for (int j = i + 1; j < m; j++) {
      vector<point> cur = psum;
      {
        point toadd = qs[j] - qs[i];
        for (int it = 0; it < sz(cur); it++) {
          cur[it] = cur[it] + toadd;
        }
      }
      int curr = rs[i] + rs[j];
      if (check(cur, curr)) {
        //~ Flow::addEdge(2 * i + 1, 2 * j, inf);
        janusz.add_edge(2*i+1, 2*j, inf);
        //~ Flow::addEdge(2 * j + 1, 2 * i, inf);
        janusz.add_edge(2*j+1, 2*i, inf);
      }
    }
  }
  //~ printf("%d\n", Flow::maxFlow(s, t));
  //~ printf("%d\n", janusz.dinic(s, t));
	auto flow = HIPR_GP(janusz.n);
	for (auto p:janusz.e) {
		flow.add_directed_edge(p.first.first, p.first.second, p.second);
	}
	printf("%d\n", flow.maximum_flow(s, t));
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}