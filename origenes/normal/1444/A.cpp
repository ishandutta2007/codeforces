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

ll pw(ll p, int k) {
  ll ret = 1;
  REP(i, k) ret = ret * p;
  return ret;
}

void solve() {
  ll p, q;
  cin >> p >> q;
  if (p % q != 0) {
    cout << p << '\n';
    return;
  }
  map<ll, int> cnt;
  for (ll i = 2; sqr(i) <= q; i++) if (q % i == 0) {
    while (q % i == 0) cnt[i]++, q /= i;
  }
  if (q > 1) cnt[q]++;
  ll ans = 1;
  bool f = false;
  for (auto [k, v] : cnt) {
    ll P = p;
    int c = 0;
    while (P % k == 0) P /= k, c++;
    chkmax(ans, p / pw(k, c - v + 1));
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