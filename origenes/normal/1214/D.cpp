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

const int maxn = 2123456;
const int inf = 1e9;

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
} solver;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> mat(n);
  REP(i, n) cin >> mat[i];
  solver.init(n * m * 2);
  REP(i, n) REP(j, m) if (mat[i][j] != '#') {
    int uin = (i * m + j) * 2, uout = (i * m + j) * 2 + 1;
    solver.addEdge(uin, uout, 1);
    if (i + 1 < n && mat[i + 1][j] != '#') {
      int vin = ((i + 1) * m + j) * 2;
      solver.addEdge(uout, vin, 2);
    }
    if (j + 1 < m && mat[i][j + 1] != '#') {
      int vin = (i * m + j + 1) * 2;
      solver.addEdge(uout, vin, 2);
    }
  }
  int ans = solver.maxflow(1, ((n - 1) * m + m - 1) * 2);
//  FOR(i, 1, n + m - 3) chkmin(ans, cnt[i]);
  cout << ans;
}