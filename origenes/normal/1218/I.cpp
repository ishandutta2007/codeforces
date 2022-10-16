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

const int maxn = 2123;

int n;
char a[maxn][maxn], b[maxn][maxn], op[maxn];

int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%s", a[i]);
  REP(i, n) scanf("%s", b[i]);
  scanf("%s", op);
  static TwoSat solver = TwoSat(2 * n + 2);
  solver.add_constraint(2 * n, false, 2 * n + 1, true);
  solver.add_constraint(2 * n, false, 2 * n + 1, false);
  REP(i, n) REP(j, n) {
    if (op[i] == '0' && op[j] == '0') {
      if (a[i][j] == b[i][j]) continue;
      puts("-1");
      return 0;
    }
    if (op[i] == '0') solver.add_constraint(i, a[i][j] != b[i][j], 2 * n, true);
    else if (op[j] == '0') solver.add_constraint(j + n, a[i][j] != b[i][j], 2 * n, true);
    else {
      if (a[i][j] == b[i][j]) {
        solver.add_constraint(i, true, j + n, false);
        solver.add_constraint(i, false, j + n, true);
      } else {
        solver.add_constraint(i, false, j + n, false);
        solver.add_constraint(i, true, j + n, true);
      }
    }
  }
  if (!solver.solve()) puts("-1");
  else {
    auto ops = solver.print();
    vector<pair<string, int>> ans;
    REP(i, n) if (ops[i]) ans.eb("row", i);
    REP(i, n) if (ops[i + n]) ans.eb("col", i);
    printf("%d\n", int(ans.size()));
    for (const auto &it : ans) printf("%s %d\n", it._1.c_str(), it._2);
  }
}