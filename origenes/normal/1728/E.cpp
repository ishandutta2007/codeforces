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

int a[maxn];
ll f[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  FOR(i, 1, n) {
    int b;
    cin >> a[i] >> b;
    f[0] += b;
    a[i] -= b;
  }
  sort(a + 1, a + n + 1);
  FOR(i, 1, n) f[i] = f[i - 1] + a[n - i + 1];
  map<tuple<int, int, bool>, ll> g;
  int m; cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    bool flip = false;
    if (x < y) {
      swap(x, y);
      flip = true;
    }
    if (g.count({x, y, flip})) {
      cout << g[{x, y, flip}] << '\n';
      continue;
    }
    ll ans = -1;
    for (int i = 0; i <= n; i += x) if ((n - i) % y == 0) {
      if (flip) chkmax(ans, f[n - i]);
      else chkmax(ans, f[i]);
    }
    cout << (g[{x, y, flip}] = ans) << '\n';
  }
}