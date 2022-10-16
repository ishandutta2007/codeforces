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
    for (auto v : G[u]) {
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
    for (auto &it : G) {
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

int n, p, M, m;

int main() {
  static TwoSat solver;
  scanf("%d%d%d%d", &n, &p, &M, &m);
  solver = TwoSat(p + M + 1);
  while (n--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    solver.add_constraint(x, true, y, true);
  }
  REP(i, p) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    solver.add_constraint(i, false, l + p, true);
    solver.add_constraint(i, false, p + r, false);
  }
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    solver.add_constraint(u, false, v, false);
  }
  REP(i, M) solver.add_constraint(i + p, true, i + p + 1, false);
  if (!solver.solve()) {
    puts("-1");
    return 0;
  }
  auto sel = solver.print();
  vector<int> ans;
  REP(i, p) if (sel[i]) ans.eb(i + 1);
  int f = -1;
  FOR(i, p, p + M) if (sel[i]) f = i - p + 1;
  assert(~f);
  printf("%d %d\n", int(ans.size()), f);
  for (auto u : ans) printf("%d ", u);
}