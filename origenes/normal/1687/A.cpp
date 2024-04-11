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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  if (k >= n) {
    ll ans = accumulate(all(a), 0LL) + n * ll(n - 1) / 2 + ll(k - n) * n;
    cout << ans << '\n';
    return;
  }
  ll ans = k * ll(k - 1) / 2, s = 0, best;
  FOR(i, 1, k) s += a[i];
  best = s;
  FOR(i, k + 1, n) {
    s += a[i] - a[i - k];
    chkmax(best, s);
  }
  cout << ans + best << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}