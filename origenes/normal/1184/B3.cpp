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

const int maxn = 112;
const int maxs = 112345;

struct Dinic { // cant have negative cap!
#define int ll
#define maxn 2123
#define inf ll(1e14)

  struct Edge {
    int from, to, cap, flow;

    Edge(int from, int to, int cap, int flow) :
        from(from), to(to), cap(cap), flow(flow) {}
  };

  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool vis[maxn];
  int d[maxn];
  int cur[maxn];

  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void addEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[to].push_back(m - 1);
    G[from].push_back(m - 2);
  }

  bool bfs() {
    memset(vis, false, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = true;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = edges[G[x][i]];
        if (!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = true;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  int dfs(int x, int a) {
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int &i = cur[x]; i < G[x].size(); i++) {
      Edge &e = edges[G[x][i]];
      if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i] ^ 1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }

  int maxflow(int s, int t) {
    this->s = s;
    this->t = t;
    int flow = 0;
    while (bfs()) {
      memset(cur, 0, sizeof(cur));
      flow += dfs(s, inf);
    }
    return flow;
  }

  void mincut(vector<int> &ans) { // Use after maxflow found
    bfs();
    for (int i = 0; i < m; i++) {
      Edge &e = edges[i];
      if (vis[e.from] && !vis[e.to] && e.cap > 0) ans.push_back(i);
    }
  }

#undef int
#undef maxn
#undef inf
};

struct SS {
  int x, a, f;
  ll p;
} s[maxs];

struct Base {
  int x, d, g;
} b[maxs];

int n, m, S, B, K;
int dis[maxn][maxn];
bool vis[maxs];

int main() {
  scanf("%d%d", &n, &m);
  reset(dis, 0x3f);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    dis[u][v] = dis[v][u] = 1;
  }
  FOR(i, 1, n) dis[i][i] = 0;
  FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) chkmin(dis[i][j], dis[i][k] + dis[k][j]);
  scanf("%d%d%d", &S, &B, &K);
  FOR(i, 1, S) scanf("%d%d%d%lld", &s[i].x, &s[i].a, &s[i].f, &s[i].p);
  FOR(i, 1, B) scanf("%d%d%d", &b[i].x, &b[i].d, &b[i].g);
  vector<pii> dep(K);
  for (auto &now : dep) {
    scanf("%d%d", &now._1, &now._2);
    vis[now._1] = vis[now._2] = true;
  }
  vector<vector<pii>> tab(n + 1);
  FOR(i, 1, B) tab[b[i].x].eb(b[i].d, b[i].g);
  FOR(i, 1, n) {
    sort(all(tab[i]));
    FOR(j, 1, int(tab[i].size()) - 1) chkmax(tab[i][j]._2, tab[i][j - 1]._2);
  }
  FOR(i, 1, S) {
    ll best = -2e9;
    FOR(j, 1, n) if (dis[s[i].x][j] <= s[i].f && !tab[j].empty()) {
      auto it = upper_bound(all(tab[j]), mp(s[i].a + 1, -1));
      if (it == tab[j].begin()) continue;
      it--;
      chkmax(best, ll(it->_2));
    }
    if (best == -2e9) s[i].p = -1e14;
    else s[i].p = best - s[i].p;
  }
  ll ans = 0;
  vector<int> spec;
  FOR(i, 1, S) {
    if (!vis[i] && s[i].p > 0) ans += s[i].p;
    else if (vis[i]) spec.eb(i);
  }
  Dinic solver;
  solver.init(spec.size() + 2);
  int st = spec.size(), en = st + 1;
  map<int, int> mat;
  REP(i, int(spec.size())) {
    if (s[spec[i]].p >= 0) {
      solver.addEdge(st, i, s[spec[i]].p);
      ans += s[spec[i]].p;
    }
    else solver.addEdge(i, en, -s[spec[i]].p);
    mat[spec[i]] = i;
  }
  for (auto it : dep) solver.addEdge(mat[it._1], mat[it._2], 1e14);
  ans -= solver.maxflow(st, en);
  printf("%lld", ans);
}