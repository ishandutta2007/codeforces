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

const int maxn = 412345;
const int dx[] = {1, 0, 0};
const int dy[] = {0, -1, 1};

vector<int> G[maxn], adj[maxn];
int scc_no, clk;
int comp[maxn], lowlink[maxn], pre[maxn], deg[maxn];
stack<int> S;

template <typename T>
class MinFenwickTree {
  vector<T> fen;
  T init_val_;

  int lowbit(int x) { return x & (x ^ (x - 1)); }

public:
  MinFenwickTree(int sz, T init_val) {
    init_val_ = init_val;
    fen.resize(sz + 10, init_val);
  }

  void put(int pos, T val) {
    for (int i = pos + 1; i < int(fen.size()); i += lowbit(i)) chkmin(fen[i], val);
  }

  T get(int pos) {
    T ret = init_val_;
    for (int i = pos + 1; i > 0; i -= lowbit(i)) chkmin(ret, fen[i]);
    return ret;
  }
};

void dfs(int u) {
  pre[u] = lowlink[u] = ++clk;
  S.emplace(u);
  for (auto v : G[u]) {
    if (!pre[v]) {
      dfs(v);
      chkmin(lowlink[u], lowlink[v]);
    } else if (!comp[v]) chkmin(lowlink[u], pre[v]);
  }
  if (pre[u] == lowlink[u]) {
    int v;
    scc_no++;
    do {
      v = S.top(); S.pop();
      comp[v] = scc_no;
    } while (u != v);
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  vector<vector<int>> down(n, vector<int>(m));
  REP(i, n) cin >> s[i];
  REP(j, m) ROF(i, n - 1, 0) {
      if (s[i][j] == '#') down[i][j] = i;
      else down[i][j] = i + 1 < n ? down[i + 1][j] : n;
    }
  REP(i, n) REP(j, m) if (s[i][j] == '#') {
        int u = i * m + j;
        REP(d, 3) {
          int ni = i + dx[d], nj = j + dy[d];
          if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
          ni = down[ni][nj];
          if (ni < 0 || ni >= n) continue;
          if (s[ni][nj] == '#') {
            int v = ni * m + nj;
            G[u].eb(v);
          }
        }
        if (i > 0 && s[i - 1][j] == '#') {
          int v = (i - 1) * m + j;
          G[u].eb(v);
        }
      }
  REP(i, n) REP(j, m) if (s[i][j] == '#' && !comp[i * m + j]) dfs(i * m + j);
  REP(i, n) REP(j, m) {
    int u = i * m + j;
    for (auto v : G[u]) if (comp[u] != comp[v]) {
      adj[comp[u]].eb(comp[v]);
      deg[comp[v]]++;
    }
  }
  vector<int> key(scc_no + 1, m);
  REP(i, n) REP(j, m) if (pre[i * m + j]) chkmin(key[comp[i * m + j]], j);
  vector<pii> starts;
  queue<int> q;
  FOR(i, 1, scc_no) if (!deg[i]) {
    starts.eb(key[i], i);
    q.emplace(i);
  }
  sort(all(starts));
  vector<int> L(scc_no + 1, m), R(scc_no + 1, -1);
  REP(i, int(starts.size())) L[starts[i]._2] = R[starts[i]._2] = i;
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : adj[u]) {
      chkmin(L[v], L[u]);
      chkmax(R[v], R[u]);
      if (!--deg[v]) q.emplace(v);
    }
  }
  vector<int> a(m);
  REP(i, m) cin >> a[i];
  vector<pii> intervals;
  REP(j, m) if (a[j]) {
    int cnt = a[j], pos;
    ROF(i, n - 1, 0) if (s[i][j] == '#' && !--cnt) {
      pos = i;
      break;
    }
    intervals.eb(L[comp[pos * m + j]], R[comp[pos * m + j]]);
  }
  if (intervals.empty()) {
    cout << 0;
    return 0;
  }
  sort(all(intervals), [](pii x, pii y) { return x._2 != y._2 ? x._2 < y._2 : x._1 < y._1; });
  int tot = starts.size();
  vector<int> cnt(tot, tot + 1);
  int mx = -1;
  MinFenwickTree<int> fen(tot, tot + 1);
  int j = 0;
  REP(i, tot) {
    while (j < intervals.size() && intervals[j]._2 < i) {
      chkmax(mx, intervals[j]._1);
      j++;
    }
    if (mx == -1) cnt[i] = 1;
    else cnt[i] = fen.get(tot - 1 - mx) + 1;
    fen.put(tot - 1 - i, cnt[i]);
  }
  for (auto [x, _] : intervals) chkmax(mx, x);
  int ans = tot + 1;
  FOR(i, mx, tot - 1) chkmin(ans, cnt[i]);
  cout << ans;
}