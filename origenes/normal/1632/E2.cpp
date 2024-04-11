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

const int maxn = 312345;

int n, f[maxn];
vector<int> G[maxn];

int dfs(int u, int par, int dep) {
  int d1 = dep, d2 = dep;
  for (auto v : G[u]) if (v != par) {
    int d = dfs(v, u, dep + 1);
    if (d > d1) {
      d2 = d1;
      d1 = d;
    } else if (d > d2) d2 = d;
  }
  int cap = min(d1, d2) - 1;
  if (cap >= 0) chkmax(f[cap], d1 + d2 - 2 * dep);
  return d1;
}

void solve() {
  cin >> n;
  FOR(i, 1, n) G[i].clear();
  REP(i, n) f[i] = 0;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  int mx = dfs(1, 0, 0);
  ROF(i, n - 2, 0) chkmax(f[i], f[i + 1]);
  int ans = 0;
  FOR(x, 1, n) {
    while (ans < mx && (f[ans] + 1) / 2 + x > ans) ans++;
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