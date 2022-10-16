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
  int x, y;
  ll t;
  cin >> t >> x >> y;
  if (x == 0 && y == 0) {
    cout << "YES\n";
    return;
  }
  if (t < (x + y)) {
    cout << "NO\n";
    return;
  }
  vector<vector<ll>> f(120, vector<ll>(120));
  f[0][0] = t - x - y;
  REP(i, 120) REP(j, 120) {
    if (i + 1 < 120) f[i + 1][j] += f[i][j] / 2;
    if (j + 1 < 120) f[i][j + 1] += (f[i][j] + 1) / 2;
  }
  int px = 0, py = 0;
  while (px < 120 && py < 120) {
    if (f[px][py] % 2 == 1) px++;
    else py++;
    if (px == x && py == y) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}