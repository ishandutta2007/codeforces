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

const int maxn = 16;

int n;
vector<int> G[1 << maxn];
int f[1 << maxn], pre[1 << maxn], mask[1 << maxn];

void solve() {
  cin >> n;
  REP(i, 1 << n) {
    G[i].clear();
    f[i] = -1;
    pre[i] = mask[i] = 0;
  }
  REP(i, n * (1 << n - 1)) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  queue<int> q;
  q.emplace(0);
  f[0] = 0;
  REP(i, n) mask[G[0][i]] = 1 << i;
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    pre[mask[u]] = u;
    for (auto v : G[u]) {
      if (f[v] == -1 || f[v] == f[u] + 1) mask[v] |= mask[u];
      if (f[v] == -1) {
        f[v] = f[u] + 1;
        q.emplace(v);
      }
    }
  }
  REP(i, 1 << n) cout << pre[i] << ' ';
  cout << '\n';
  if (n != 1 && n != 2 && n != 4 && n != 8 && n != 16) {
    cout << -1 << '\n';
    return;
  }
  REP(i, 1 << n) {
    int m = mask[i], ans = 0;
    for (int len = 1; len < n; len <<= 1) {
      int bit = 0;
      for (int j = 0; j < n; j += len << 1) FOR(k, j, j + len - 1) bit ^= m >> k & 1;
      if (bit) ans |= len;
    }
    cout << ans << ' ';
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