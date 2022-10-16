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

struct Matching {
  int n1, n2;
  vector<set<int>> G;
  vector<int> match;
  vector<bool> used;

  Matching() = default;

  Matching(int n1, int n2) : n1(n1), n2(n2) {
    G.resize(n1);
  }

  void add_edge(int u, int v) {
    G[u].emplace(v);
  }

  void remove_edge(int u, bool rev) {
    if (rev) REP(i, n1) G[i].erase(u);
    else G[u].clear();
  }

  bool dfs(int u) {
    if (used[u]) return false;
    used[u] = true;
    for (auto v : G[u]) if (match[v] == -1 || dfs(match[v])) {
      match[v] = u;
      return true;
    }
    return false;
  }

  int solve() {
    match = vector<int>(n2, -1);
    int ans = 0;
    REP(i, n1) {
      used = vector<bool>(n1);
      ans += dfs(i);
    }
    return ans;
  }
};

const int maxn = 55;

int n, m, k;
ll x[maxn], y[maxn], f[maxn][maxn];
int pre[maxn][maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> k;
  Matching solver(n, n);
  while (m--) {
    int u, v; cin >> u >> v;
    u--, v--;
    solver.add_edge(u, v);
  }
  REP(i, k) cin >> x[i] >> y[i];
  int match = solver.solve(), now = match;
  vector<int> seq;
  while (now--) {
    int best = 0;
    REP(i, n) {
      auto tmp = solver;
      tmp.remove_edge(i, false);
      if (tmp.solve() == now) best = i + 1;
      tmp = solver;
      tmp.remove_edge(i, true);
      if (tmp.solve() == now) best = -(i + 1);
    }
    seq.eb(best);
    if (best < 0) solver.remove_edge(-best - 1, true);
    else solver.remove_edge(best - 1, false);
  }
  reverse(all(seq));
  reset(f, 0xc0);
  f[0][match] = 0;
  REP(i, k) REP(j, match + 1) REP(jj, j + 1) {
    if (i + 1 + jj >= n) break;
    int t = j - jj;
    ll gain = max(x[i] - t * y[i], 0LL);
    if (f[i + 1][jj] < f[i][j] + gain) {
      f[i + 1][jj] = f[i][j] + gain;
      pre[i + 1][jj] = j;
    }
  }
  int tail = max_element(f[k], f[k] + match + 1) - f[k];
  vector<int> ans;
  ROF(i, k, 1) {
    ans.eb(0);
    ROF(j, pre[i][tail] - 1, tail) ans.eb(seq[j]);
    tail = pre[i][tail];
  }
  reverse(all(ans));
  cout << ans.size() << '\n';
  for (auto u : ans) cout << u << ' ';
}