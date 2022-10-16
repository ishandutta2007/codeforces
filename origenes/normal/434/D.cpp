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

const int maxn = 112345;
const ll mx = 1e9;
const ll inf = 1e18;

struct Dinic { // cant have negative cap!
  struct Edge {
    int from, to;
    ll cap, flow;

    Edge(int from, int to, ll cap, ll flow) :
        from(from), to(to), cap(cap), flow(flow) {}
  };

  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool vis[maxn];
  ll d[maxn];
  int cur[maxn];

  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void addEdge(int from, ll to, ll cap) {
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

  ll dfs(int x, ll a) {
    if (x == t || a == 0) return a;
    ll flow = 0, f;
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

  ll maxflow(int s, int t) {
    this->s = s;
    this->t = t;
    ll flow = 0;
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
};

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(n + 1), c(n + 1);
  FOR(i, 1, n) cin >> a[i] >> b[i] >> c[i];
  vector<int> l(n + 1), r(n + 1);
  int cnt = 0;
  FOR(i, 1, n) {
    cin >> l[i] >> r[i];
    cnt += r[i] - l[i] + 2;
  }
  static Dinic solver;
  int src = 0, sink = cnt + 1;
  solver.init(cnt + 2);
  vector<map<int, int>> id(n + 1);
  int j = 1;
  FOR(i, 1, n) {
    solver.addEdge(src, j++, inf);
    FOR(x, l[i], r[i]) {
      auto f = [=]() -> ll {
        return a[i] * ll(sqr(x)) + b[i] * x + c[i];
      };
      solver.addEdge(j - 1, j, mx - f());
      id[i][x] = j++;
    }
    solver.addEdge(j - 1, sink, inf);
  }
  while (m--) {
    int u, v, d;
    cin >> u >> v >> d;
    FOR(i, l[u], r[u]) {
      j = i - d;
      if (j <= l[v]) continue;
      if (j > r[v]) solver.addEdge(id[u][i] - 1, sink, inf);
      else solver.addEdge(id[u][i] - 1, id[v][j] - 1, inf);
    }
  }
  cout << n * mx - solver.maxflow(src, sink);
}