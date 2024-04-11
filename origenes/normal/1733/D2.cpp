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

void solve() {
  int n;
  ll x, y;
  cin >> n >> x >> y;
  string s, t;
  cin >> s >> t;
  vector<int> g;
  REP(i, n) if (s[i] != t[i]) g.eb(i);
  if (size(g) % 2 == 1) {
    cout << "-1\n";
    return;
  }
  if (x >= y) {
    if (size(g) == 2) {
      if (g[0] == g[1] - 1) cout << min(x, 2 * y) << '\n';
      else cout << y << '\n';
    } else cout << size(g) / 2 * y << '\n';
  } else {
    vector<ll> f(size(g) + 1);
    f[0] = 0;
    FOR(i, 1, int(size(g))) {
      if (i % 2 == 1) {
        if (i == 1) f[i] = f[i - 1];
        else f[i] = min(f[i - 1], f[i - 2] + (g[i - 1] - g[i - 2]) * x);
      } else f[i] = min(f[i - 1] + y, f[i - 2] + (g[i - 1] - g[i - 2]) * x);
    }
    cout << f.back() << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}