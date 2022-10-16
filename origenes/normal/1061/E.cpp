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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 512;
const int inf = 0x3f3f3f3f;

struct Edge {
  int from, to, cap, flow, cost;
  Edge(int u, int v, int c, int f, int w) : from(u), to(v), cap(c), flow(f), cost(w) {}
};

struct MCMF {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn * 2];
  bool inq[maxn * 2];
  int d[maxn * 2], p[maxn * 2], a[maxn * 2];

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

  bool bfs(int s, int t, int &flow, int &cost) {
    fill(d, d + n, inf);
    fill(inq, inq + n, false);
    d[s] = 0; inq[s] = true; a[s] = inf;
    queue<int> que;
    que.emplace(s);
    while (!que.empty()) {
      int u = que.front(); que.pop();
      inq[u] = false;
      for (auto id : G[u]) {
        auto &e = edges[id];
        if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = id;
          a[e.to] = min(a[u], e.cap - e.flow);
          if (!inq[e.to]) {
            inq[e.to] = true;
            que.emplace(e.to);
          }
        }
      }
    }
    if (d[t] == inf) return false;
    flow += a[t];
    cost += d[t] * a[t];
    for (int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u] ^ 1].flow -= a[t];
    }
    return true;
  }

  int mcmf(int s, int t, int &cost) {
    int flow = 0; cost = 0;
    while (bfs(s, t, flow, cost));
    return flow;
  }
};

bool bad;
int n, r1, r2, q1, q2, mmax, tot1;
int a[maxn], need[maxn], cap1[maxn], cap2[maxn], off1[maxn], off2[maxn];
vector<int> G1[maxn], G2[maxn];
MCMF solver;

int dfs(const vector<int> G[maxn], int u, int par, int *cap, int *off, int anc) {
  if (need[u] != -1) anc = u;
  off[u] = anc;
  int cost = 0;
  for (int v : G[u]) if (v != par) cost += dfs(G, v, u, cap, off, anc);
  if (need[u] != -1) {
    if (cost > need[u]) bad = true;
    cap[u] = need[u] - cost;
    cost = need[u];
  }
  return cost;
}

int main() {
  scanf("%d%d%d", &n, &r1, &r2);
  r1--, r2--;
  REP(i, n) {
    scanf("%d", a + i);
    chkmax(mmax, a[i]);
  }
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    G1[u].eb(v);
    G1[v].eb(u);
  }
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    G2[u].eb(v);
    G2[v].eb(u);
  }
  reset(need, -1);
  scanf("%d", &q1);
  while (q1--) {
    int id;
    scanf("%d", &id);
    scanf("%d", need + id - 1);
  }
  tot1 = need[r1];
  fill(cap1, cap1 + n, 1e4);
  dfs(G1, r1, -1, cap1, off1, r1);
  if (bad) {
    puts("-1");
    return 0;
  }
  reset(need, -1);
  scanf("%d", &q2);
  while (q2--) {
    int id;
    scanf("%d", &id);
    scanf("%d", need + id - 1);
  }
  if (need[r2] != tot1) {
    puts("-1");
    return 0;
  }
  fill(cap2, cap2 + n, 1e4);
  dfs(G2, r2, -1, cap2, off2, r2);
  if (bad) {
    puts("-1");
    return 0;
  }
  solver.init(2 * n + 2);
  REP(i, n) {
    solver.addEdge(0, i + 1, cap1[i], 0);
    solver.addEdge(i + n + 1, 2 * n + 1, cap2[i], 0);
    solver.addEdge(off1[i] + 1, n + off2[i] + 1, 1, mmax - a[i]);
  }
  int cost, flow = solver.mcmf(0, 2 * n + 1, cost);
  if (flow != tot1) puts("-1");
  else printf("%d", mmax * tot1 - cost);
}