#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 5123;
const int inf = 0x3f3f3f3f;

struct Edge {
  int from, to, cap, flow, cost;

  Edge(int from, int to, int cap, int flow, int cost) : from(from), to(to), cap(cap), flow(flow), cost(cost) {}
};

struct MCMF {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool inq[maxn];
  int d[maxn], p[maxn], a[maxn];

  void init(int n) {
    this->n = n;
    REP(i, n) G[i].clear();
    edges.clear();
  }

  void addEdge(int from, int to, int cap, int cost) {
    edges.eb(from, to, cap, 0, cost);
    edges.eb(to, from, 0, 0, -cost);
    m = edges.size();
    G[from].eb(m - 2);
    G[to].eb(m - 1);
  }

  bool bellmanFord(int s, int t, int &flow, ll &cost) {
    fill(inq, inq + n, false);
    fill(d, d + n, inf);
    d[s] = 0; inq[s] = true; a[s] = inf;
    queue<int> q;
    q.emplace(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      inq[u] = false;
      for (auto id : G[u]) {
        auto &e = edges[id];
        if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = id;
          a[e.to] = min(a[u], e.cap - e.flow);
          if (!inq[e.to]) {
            inq[e.to] = true;
            q.emplace(e.to);
          }
        }
      }
    }
    if (d[t] == inf) return false;
    flow += a[t];
    cost += ll(d[t]) * a[t];
    for (int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u] ^ 1].flow -= a[t];
    }
    return true;
  }

  int mcmf(int s, int t, ll &cost) {
    int flow = 0;
    cost = 0;
    while (bellmanFord(s, t, flow, cost));
    return flow;
  }
};

inline int get(int u, int clk) {
  return (u - 1) * 100 + clk;
}

int n, m, k, c, d;
MCMF solver;

int main() {
  scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
  int s = 0, t = 100 * n + 1;
  solver.init(t + 1);
  FOR(i, 1, k) {
    int a;
    scanf("%d", &a);
    solver.addEdge(s, get(a, 1), 1, 0);
  }
  FOR(i, 1, n) FOR(j, 1, 99) solver.addEdge(get(i, j), get(i, j + 1), k, c);
  FOR(i, 1, 100) solver.addEdge(get(1, i), t, k, 0);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    FOR(j, 1, 99) FOR(kk, 1, k) {
      solver.addEdge(get(u, j), get(v, j + 1), 1, c + (2 * kk - 1) * d);
      solver.addEdge(get(v, j), get(u, j + 1), 1, c + (2 * kk - 1) * d);
    }
  }
  ll ans;
  solver.mcmf(s, t, ans);
  printf("%lld", ans);
}