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

struct Edge {
  int to, cap, flow;

  Edge() = default;
  Edge(int to, int cap, int flow): to(to), cap(cap), flow(flow) {}
};

const int maxn = 11234;

int n, m;
vector<int> G[maxn];
vector<Edge> edges;
bool vis[maxn];

void add_edge(int u, int v, int c) {
  G[u].eb(edges.size());
  edges.eb(v, c, 0);
  G[v].eb(edges.size());
  edges.eb(u, 0, 0);
}

bool dfs(int u) {
  if (u == n + 1) return true;
  vis[u] = true;
  for (auto id : G[u]) if (!vis[edges[id].to] && edges[id].flow < edges[id].cap && dfs(edges[id].to)) {
    edges[id].flow++;
    edges[id ^ 1].flow--;
    return true;
  }
  return false;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  vector<int> s(n), a(n);
  int pos = -1;
  REP(i, n) {
    cin >> s[i];
    if (!s[i]) pos = i;
  }
  REP(i, n) cin >> a[i];
  int val = accumulate(all(a), 0);
  vector<int> x(m), y(m);
  REP(i, m) {
    int u, v;
    cin >> u >> v;
    x[i] = u, y[i] = v;
    u--, v--;
    if (!s[u]) u = pos;
    if (!s[v]) v = pos;
    a[u]++, a[v]--;
    add_edge(u, v, 1);
  }
  bool ok = true;
  if (pos != -1) a[pos] -= val;
  else if (val) ok = false;
  val = 0;
  REP(i, n) if (a[i] || i == pos) {
    if (a[i] & 1) ok = false;
    if (a[i] > 0) {
      add_edge(n, i, a[i] / 2);
      val += a[i] / 2;
    } else add_edge(i, n + 1, -a[i] / 2);
  }
  while (dfs(n)) {
    reset(vis, 0);
    val--;
  }
  if (val) ok = false;
  if (ok) {
    cout << "YES\n";
    REP(i, m) {
      if (edges[i << 1].flow) swap(x[i], y[i]);
      cout << x[i] << ' ' << y[i] << '\n';
    }
  } else cout << "NO";
}