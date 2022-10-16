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

namespace MCMF {            // Use BellmanFord, need to ensure there is no negative cycle
  struct Edge {
    int from, to, cap, flow, cost;  // cost for one unit flow
    Edge(int u, int v, int c, int f, int w): from(u), to(v), cap(c), flow(f), cost(w) {}
  };

  const int inf = 1e9;

  int n, m;
  vector<Edge> edges;
  vector<vector<int>> G;
  vector<char> inq;
  vector<int> d, p, a;

  void init(int maxnode) {
    n = maxnode;
    G = vector<vector<int>>(n, vector<int>());
    inq = vector<char>(n);
    d = p = a = vector<int>(n);
    edges.clear();
  }

  void addEdge(int from, int to, int cap, int cost) {
    edges.push_back(Edge(from, to, cap, 0, cost));
    edges.push_back(Edge(to, from, 0, 0, -cost));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  bool bellmanFord(int s, int t, int& flow, ll& cost) {
    for(int i = 0; i < n; i++) { d[i] = inf; inq[i] = false; }
    d[s] = 0; inq[s] = true; a[s] = inf;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
      int u = Q.front(); Q.pop();
      inq[u] = false;
      for(int i = 0; i < G[u].size(); i++) {
        Edge& e = edges[G[u][i]];
        if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = G[u][i];
          a[e.to] = min(a[u], e.cap - e.flow);
          if(!inq[e.to]) { inq[e.to] = true; Q.push(e.to); }
        }
      }
    }
    if(d[t] >= 0) return false;
    flow += a[t];
    cost += ll(d[t]) * a[t];
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u] ^ 1].flow -= a[t];
    }
    return true;
  }

  int mcmf(int s, int t, ll& cost) {
    int flow = 0; cost = 0;
    while(bellmanFord(s, t, flow, cost));
    return flow;
  }
}

const int maxm = 212;
const int inf = 1e6;

int n1, n2, m, r, b;
char s1[maxm], s2[maxm];
int st[maxm], en[maxm];

int main() {
  scanf("%d%d%d%d%d", &n1, &n2, &m, &r, &b);
  scanf("%s%s", s1 + 1, s2 + 1);
  FOR(i, 1, m) scanf("%d%d", st + i, en + i);
  int source = 0, sink = n1 + n2 + 1;
  MCMF::init(n1 + n2 + 2);
  FOR(i, 1, n1) {
    if (s1[i] == 'R') MCMF::addEdge(source, i, 1, -inf);
    if (s1[i] != 'B') MCMF::addEdge(source, i, inf, 0);
    if (s1[i] == 'B') MCMF::addEdge(i, sink, 1, -inf);
    if (s1[i] != 'R') MCMF::addEdge(i, sink, inf, 0);
  }
  FOR(i, 1, n2) {
    if (s2[i] == 'B') MCMF::addEdge(source, i + n1, 1, -inf);
    if (s2[i] != 'R') MCMF::addEdge(source, i + n1, inf, 0);
    if (s2[i] == 'R') MCMF::addEdge(i + n1, sink, 1, -inf);
    if (s2[i] != 'B') MCMF::addEdge(i + n1, sink, inf, 0);
  }
  int need = 0, cnt = MCMF::m;
  FOR(i, 1, n1) if (s1[i] != 'U') need++;
  FOR(i, 1, n2) if (s2[i] != 'U') need++;
  FOR(i, 1, m) {
    MCMF::addEdge(st[i], en[i] + n1, 1, r);
    MCMF::addEdge(en[i] + n1, st[i], 1, b);
  }
  ll cost = 0;
  MCMF::mcmf(source, sink, cost);
  cost += need * inf;
  if (cost > 4e4 + 10) {
    puts("-1");
    return 0;
  }
  printf("%lld\n", cost);
  FOR(i, 1, m) {
    char now = 'U';
    if (MCMF::edges[cnt + (i - 1) * 4].flow > 0) now = 'R';
    else if (MCMF::edges[cnt + (i - 1) * 4 + 2].flow > 0) now = 'B';
    putchar(now);
  }
}