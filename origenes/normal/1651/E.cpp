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

const int maxn = 1512;

int n;
vector<int> G[maxn * 2], cyc;
bool vis[maxn * 2];

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  cyc.eb(u);
  for (auto v : G[u]) dfs(v);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, 2 * n) {
    int x, y;
    cin >> x >> y;
    G[x].eb(y);
    G[y].eb(x);
  }
  ll ans = 0;
  FOR(i, 1, n) if (!vis[i]) {
    dfs(i);
    int m = size(cyc);
    REP(j, m) {
      int l = cyc[j], r = cyc[j], L = cyc[(j + 1) % m], R = cyc[(j + 1) % m];
      auto f = [](int l, int r, int k) -> ll {
        if (l <= k && k <= r) return 0;
        if (l > n) {
          l -= n;
          r -= n;
          k -= n;
        }
        if (k < l) return (l - k) * (n - r + 1);
        return l * (k - r);
      };
      auto g = [](int l, int r) -> ll {
        if (l > n) {
          l -= n;
          r -= n;
        }
        return l * (n - r + 1);
      };
      for (int k = 2; k < m; k += 2) {
        ans += f(l, r, cyc[(j + k) % m]) * g(L, R);
        chkmin(l, cyc[(j + k) % m]);
        chkmax(r, cyc[(j + k) % m]);
        chkmin(L, cyc[(j + k + 1) % m]);
        chkmax(R, cyc[(j + k + 1) % m]);
      }
      if (l <= n) ans += g(l, r) * g(L, R);
    }
    cyc.clear();
  }
  cout << ans;
}