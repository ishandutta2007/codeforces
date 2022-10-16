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

struct TwoSat {
  int n, scc_cnt, clk;
  vector<vector<int>> G;

  vector<int> sccno, in, lowlink;
  stack<int> s;

  TwoSat() = default;

  TwoSat(int n) {
    this->n = 2 * n;
    G = vector<vector<int>>(2 * n);
  }

  // x == x_val or y == y_val
  // odd: true, even: false
  void add_constraint(int x, bool x_val, int y, bool y_val) {
    int u = 2 * x + x_val, v = 2 * y + y_val;
    G[u ^ 1].eb(v);
    G[v ^ 1].eb(u);
  }

  void dfs(int u) {
    in[u] = lowlink[u] = ++clk;
    s.emplace(u);
    for (auto v: G[u]) {
      if (!in[v]) {
        dfs(v);
        chkmin(lowlink[u], lowlink[v]);
      } else if (sccno[v] == -1) {
        chkmin(lowlink[u], in[v]);
      }
    }
    if (lowlink[u] == in[u]) {
      int v;
      do {
        v = s.top();
        s.pop();
        sccno[v] = scc_cnt;
      } while (v != u);
      scc_cnt++;
    }
  }

  bool solve() {
    scc_cnt = clk = 0;
    while (!s.empty()) s.pop();
    sccno = vector<int>(n, -1);
    lowlink = vector<int>(n);
    in = vector<int>(n);
    for (auto &it: G) {
      sort(all(it));
      uni(it);
    }
    REP(i, n) if (sccno[i] == -1) dfs(i);
    for (int i = 0; i < n; i += 2) if (sccno[i] == sccno[i ^ 1]) return false;
    return true;
  }

  vector<char> print() {
    vector<char> ret(n / 2);
    for (int i = 0; i < n; i += 2) ret[i >> 1] = (sccno[i] > sccno[i ^ 1]);
    return ret;
  }
};

const int maxn = 412345;

vector<int> G[maxn];
int dep[maxn], p[maxn];
char c[maxn][2];
bool vis[maxn];

void dfs(int u, int par) {
  p[u] = par;
  dep[u] = dep[par] + 1;
  for (auto v : G[u]) if (v != par) dfs(v, u);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, q;
  cin >> n >> q;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  TwoSat solver(n + q);
  REP(qid, q) {
    int x, y;
    string s;
    cin >> x >> y >> s;
    int len = size(s), l = 0, r = len - 1;
    vector<int> chain(len);
    REP(i, len) {
      if (dep[x] > dep[y]) {
        chain[l++] = x;
        x = p[x];
      } else {
        chain[r--] = y;
        y = p[y];
      }
    }
    REP(i, len) {
      int u = chain[i];
      if (!vis[u]) {
        vis[u] = true;
        c[u][0] = s[i];
        c[u][1] = s[len - i - 1];
      }
      if (c[u][0] != s[i]) solver.add_constraint(u - 1, false, n + qid, true);
      if (c[u][1] != s[i]) solver.add_constraint(u - 1, true, n + qid, true);
      if (c[u][0] != s[len - i - 1]) solver.add_constraint(u - 1, false, n + qid, false);
      if (c[u][1] != s[len - i - 1]) solver.add_constraint(u - 1, true, n + qid, false);
    }
  }
  if (!solver.solve()) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  auto ans = solver.print();
  FOR(i, 1, n) {
    if (!vis[i]) cout << 'a';
    else cout << c[i][1 - ans[i - 1]];
  }
}