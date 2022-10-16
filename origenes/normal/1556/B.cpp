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
  int n; cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  vector<int> odds;
  REP(i, n) if (a[i] % 2 == 1) odds.eb(i);
  ll ans = 1e18;
  if ((n + 1) / 2 == odds.size()) {
    ll now = 0;
    REP(i, (n + 1) / 2) now += abs(odds[i] - i * 2);
    chkmin(ans, now);
  }
  if (n / 2 == odds.size()) {
    ll now = 0;
    REP(i, n / 2) now += abs(odds[i] - 2 * i - 1);
    chkmin(ans, now);
  }
  if (ans == 1e18) ans = -1;
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