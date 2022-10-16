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

const int maxn = 1123456;

int n, q;
int fen[maxn], cnt[maxn], a[maxn], ans[maxn];
vector<int> G[maxn];
unordered_set<int> val[maxn];
vector<tuple<int, int, int>> queries[maxn];

void add(int x, int v) {
  if (x == 0) return;
  while (x <= n) {
    fen[x] += v;
    x += x & -x;
  }
}

int query(int x) {
  if (x == 0) return 0;
  int ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= x & -x;
  }
  return ret;
}

void dfs(int u, int par) {
  add(cnt[a[u]], -1);
  val[cnt[a[u]]].erase(a[u]);
  add(++cnt[a[u]], 1);
  val[cnt[a[u]]].emplace(a[u]);
  for (auto [l, k, id] : queries[u]) {
    int off = query(l - 1);
    if (query(n) - off < k) {
      ans[id] = -1;
      continue;
    }
    int lo = l, hi = n;
    while (lo < hi) {
      int mi = lo + hi >> 1;
      if (query(mi) - off < k) lo = mi + 1;
      else hi = mi;
    }
    assert(!val[lo].empty());
    ans[id] = *val[lo].begin();
  }
  for (auto v : G[u]) if (v != par) dfs(v, u);
  add(cnt[a[u]], -1);
  val[cnt[a[u]]].erase(a[u]);
  add(--cnt[a[u]], 1);
  val[cnt[a[u]]].emplace(a[u]);
}

void solve() {
  cin >> n >> q;
  FOR(i, 1, n) {
    G[i].clear();
    queries[i].clear();
  }
  val[0].clear();
  FOR(i, 1, n) {
    cin >> a[i];
    val[0].emplace(a[i]);
  }
  FOR(i, 2, n) {
    int p; cin >> p;
    G[p].eb(i);
    G[i].eb(p);
  }
  FOR(i, 1, q) {
    int v, l, k;
    cin >> v >> l >> k;
    queries[v].eb(l, k, i);
  }
  cnt[0] = n;
  dfs(1, 0);
  FOR(i, 1, q) cout << ans[i] << ' ';
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