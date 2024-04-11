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

const int maxm = 55;
const int maxn = 255;
const ll inf = 1e15;

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

  void addEdge(int from, int to, ll cap) {
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

pair<pii, pii> rec[maxm];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  vector<int> x, y;
  FOR(i, 1, m) {
    scanf("%d%d%d%d", &rec[i]._1._1, &rec[i]._1._2, &rec[i]._2._1, &rec[i]._2._2);
    rec[i]._2._1++, rec[i]._2._2++;
    x.eb(rec[i]._1._1); y.eb(rec[i]._1._2);
    x.eb(rec[i]._2._1); y.eb(rec[i]._2._2);
  }
  x.eb(1); x.eb(n + 1); y.eb(1); y.eb(n + 1);
  sort(all(x)); uni(x);
  sort(all(y)); uni(y);
  static Dinic solver;
  solver.init(x.size() + y.size());
  int s = x.size() + y.size() - 2, t = x.size() + y.size() - 1;
  REP(i, int(x.size()) - 1) solver.addEdge(s, i, x[i + 1] - x[i]);
  REP(i, int(y.size()) - 1) solver.addEdge(i + x.size() - 1, t, y[i + 1] - y[i]);
  auto check = [&](int i, int j) {
    int x1 = x[i], x2 = x[i + 1], y1 = y[j], y2 = y[j + 1];
    FOR(k, 1, m) if (rec[k]._1._1 <= x1 && x2 <= rec[k]._2._1 && rec[k]._1._2 <= y1 && y2 <= rec[k]._2._2)
      return true;
    return false;
  };
  REP(i, int(x.size()) - 1) REP(j, int(y.size()) - 1) if (check(i, j))
    solver.addEdge(i, j + x.size() - 1, 2e9);
  printf("%lld", solver.maxflow(s, t));
}