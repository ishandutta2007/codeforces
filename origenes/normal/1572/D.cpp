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

const int maxn = 16123;

struct Edge {
  int from, to, cap, flow, cost;  // cost for one unit flow
  Edge(int u, int v, int c, int f, int w): from(u), to(v), cap(c), flow(f), cost(w) {}
};

struct MCMF {            // Use BellmanFord, need to ensure there is no negative cycle
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool inq[maxn];
  int d[maxn];
  int p[maxn];
  int a[maxn];            // the amount of flow can be changed

  void init(int n) {
    this->n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap, int cost) {
    edges.push_back(Edge(from, to, cap, 0, cost));
    edges.push_back(Edge(to, from, 0, 0, -cost));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  bool BellmanFord(int s, int t, int& flow, ll& cost) {
    for(int i = 0; i < n; i++) { d[i] = 1e9; inq[i] = false; }
    d[s] = 0; inq[s] = true; a[s] = 1e9;

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
    if(d[t] == 1e9) return false;
    flow += a[t];
    cost += (ll)d[t] * (ll)a[t];
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u] ^ 1].flow -= a[t];
    }
    return true;
  }

  int MincostMaxflow(int s, int t, ll& cost) {
    int flow = 0; cost = 0;
    while(BellmanFord(s, t, flow, cost));
    return flow;
  }
} solver;

vector<int> G[maxn];
int c[maxn];

void dfs(int u, int x) {
  c[u] = x;
  for (auto v : G[u]) if (c[v] == -1) dfs(v, 1 - x);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, k;
  cin >> n >> k;
  vector<int> a(1 << n);
  REP(i, 1 << n) cin >> a[i];
  vector<tuple<int, int, int>> edges;
  REP(i, n) REP(j, 1 << n) {
    int nj = j ^ (1 << i);
    if (j < nj) edges.eb(a[j] + a[nj], j, nj);
  }
  if (edges.size() > (2 * n - 1) * (k - 1) + 1) {
    nth_element(edges.begin(), edges.begin() + (2 * n - 1) * (k - 1) + 1, edges.end(), greater<>());
    edges.resize((2 * n - 1) * (k - 1) + 1);
  }
  map<int, int> ids;
  for (auto &[_, u, v] : edges) {
    if (!ids.count(u)) ids[u] = ids.size();
    if (!ids.count(v)) ids[v] = ids.size();
    u = ids[u], v = ids[v];
    G[u].eb(v); G[v].eb(u);
  }
  REP(i, ids.size()) c[i] = -1;
  REP(i, ids.size()) if (c[i] == -1) dfs(i, 0);
  solver.init(int(ids.size()) + 3);
  int src = ids.size(), sink = src + 1, S = sink + 1;
  solver.AddEdge(S, src, k, 0);
  REP(i, ids.size()) {
    if (c[i] == 0) solver.AddEdge(src, i, 1, 0);
    else solver.AddEdge(i, sink, 1, 0);
  }
  for (auto [w, u, v] : edges) {
    if (c[u]) swap(u, v);
    solver.AddEdge(u, v, 1, -w);
  }
  ll ans;
  solver.MincostMaxflow(S, sink, ans);
  cout << -ans << '\n';
}