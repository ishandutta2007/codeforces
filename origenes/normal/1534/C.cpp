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

const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> f(n + 1), g(n + 1), pos(n + 1);
  FOR(i, 1, n) {
    cin >> f[i];
    pos[f[i]] = i;
  }
  FOR(i, 1, n) cin >> g[i];
  vector<bool> vis(n + 1);
  int cnt = 0;
  FOR(i, 1, n) if (!vis[i]) {
    int u = i;
    vis[u] = true;
    while (g[u] != f[i]) {
      u = pos[g[u]];
      vis[u] = true;
    }
    cnt++;
  }
  ll ans = 1;
  while (cnt--) ans = ans * 2 % MOD;
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}