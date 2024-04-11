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
  sort(all(a));
  ll s = accumulate(all(a), 0LL);
  if (a.front() * ll(n - 2) + s > 0 || a.back() * ll(n - 2) + s < 0) {
    cout << "INF\n";
    return;
  }
  ll k = a.back() * ll(n - 2) + s, b = -(n - 1) * sqr(ll(a[n - 1])), ans = b;
  FOR(i, 1, n - 1) {
    ll x = a[n - i] - a[n - i - 1];
    b += x * k;
    chkmax(ans, b);
    k += a[0] - a[n - 1];
  }
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