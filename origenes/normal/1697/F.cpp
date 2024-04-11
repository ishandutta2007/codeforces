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

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  TwoSat solver(n * k);
  auto get_id = [k](int i, int j) {
    return i * k + j - 1;
  };
  solver.add_constraint(get_id(0, 1), true, get_id(0, 1), true);
  REP(i, n) FOR(j, 2, k) solver.add_constraint(get_id(i, j), false, get_id(i, j - 1), true);
  REP(i, n - 1) FOR(j, 1, k) solver.add_constraint(get_id(i, j), false, get_id(i + 1, j), true);
  while (m--) {
    int op; cin >> op;
    if (op == 1) {
      int i, x;
      cin >> i >> x;
      i--;
      if (x < k) solver.add_constraint(get_id(i, x), false, get_id(i, x + 1), true);
      else solver.add_constraint(get_id(i, x), false, get_id(i, x), false);
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      l--, r--;
      if (op == 2) {
        FOR(j, 1, k) {
          if (j >= x) solver.add_constraint(get_id(l, j), false, get_id(l, j), false);
          else {
            int y = x - j;
            if (y + 1 <= k) solver.add_constraint(get_id(l, j), false, get_id(r, y + 1), false);
          }
        }
      } else {
        FOR(j, 2, min(k, x - 1)) {
          if (x - j + 1 <= k) solver.add_constraint(get_id(l, j), true, get_id(r, x - j + 1), true);
          else solver.add_constraint(get_id(l, j), true, get_id(l, j), true);
        }
      }
    }
  }
  if (!solver.solve()) {
    cout << "-1\n";
    return;
  }
  auto ret = solver.print();
  REP(i, n) {
    ROF(j, k, 1) if (ret[get_id(i, j)]) {
      cout << j << ' ';
      break;
    }
  }
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}