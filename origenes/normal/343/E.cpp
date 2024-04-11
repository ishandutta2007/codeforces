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

const int maxn = 213;
const int inf = 0x3f3f3f3f;

struct Dinic { // cant have negative cap!
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
    edges.push_back(Edge(to, from, cap, 0));
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
};

vector<vector<pii>> adj;

struct GomoryHu {
  int n;
  vector<Dinic::Edge> edges;

  void init(int n) {
    this->n = n;
    adj = vector<vector<pii>>(n);
    edges.clear();
  }

  void addEdge(int from, int to, int cap) {
    edges.eb(from, to, cap, 0);
  }

  void solve() {
    set<int> s;
    REP(i, n) s.emplace(i);
    solve(s);
  }

  void solve(const set<int> &ini) {
    if (ini.size() == 1) return;
    static Dinic solver;
    int source = *ini.begin(), sink = *ini.rbegin();
    solver.init(n);
    for (const auto &e : edges) solver.addEdge(e.from, e.to, e.cap);
    int w = solver.maxflow(source, sink);
    set<int> s, t;
    solver.bfs();
    REP(i, n) if (ini.count(i)) {
      if (solver.vis[i]) s.emplace(i);
      else t.emplace(i);
    }
    solve(s);
    solve(t);
    adj[sink].eb(source, w);
    adj[source].eb(sink, w);
  }
};

int n, m;
GomoryHu solver;
vector<int> ans;

void dfs(const set<int> &s, int u, int par, int &cut, int &a, int &b) {
  for (auto e : adj[u]) {
    int v = e._1, w = e._2;
    if (!s.count(v) || v == par) continue;
    if (w < cut) {
      cut = w;
      a = u, b = v;
    }
    dfs(s, v, u, cut, a, b);
  }
}

void dfs(const set<int> &ini, set<int> &s, int u, int par, int a, int b) {
  s.emplace(u);
  for (auto e : adj[u]) {
    int v = e._1;
    if (!ini.count(v) || v == par) continue;
    if (u == a || u == b) {
      if (v == (u ^ a ^ b)) continue;
    }
    dfs(ini, s, v, u, a, b);
  }
}

int solve(const set<int> &ini) {
  int u = *ini.begin();
  if (ini.size() == 1) {
    ans.eb(u);
    return 0;
  }
  set<int> s, t;
  int cut = inf, a, b;
  dfs(ini, u, 0, cut, a, b);
  dfs(ini, s, u, 0, a, b);
  for (auto it : ini) if (!s.count(it)) t.emplace(it);
  return cut + solve(s) + solve(t);
}

int main() {
  scanf("%d%d", &n, &m);
  solver.init(n);
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--, b--;
    solver.addEdge(a, b, c);
  }
  solver.solve();
  set<int> s;
  REP(i, n) s.emplace(i);
  printf("%d\n", solve(s));
  for (auto it : ans) printf("%d ", it + 1);
}