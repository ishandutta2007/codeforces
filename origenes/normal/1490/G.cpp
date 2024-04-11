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
  int n, m; cin >> n >> m;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  vector<ll> s(n);
  s[0] = a[0];
  FOR(i, 1, n - 1) s[i] = s[i - 1] + a[i];
  vector<pair<ll, int>> monos;
  REP(i, n) if (monos.empty() || monos.back()._1 < s[i]) monos.eb(s[i], i);
  while (m--) {
    ll x; cin >> x;
    auto it = lower_bound(all(monos), mp(x, 0));
    if (it != monos.end()) {
      cout << it->_2 << ' ';
      continue;
    }
    if (s[n - 1] <= 0) {
      cout << -1 << ' ';
      continue;
    }
    ll rd = (x - monos.back()._1 + s[n - 1] - 1) / s[n - 1], req = rd * n;
    x -= rd * s[n - 1];
    it = lower_bound(all(monos), mp(x, 0));
    cout << req + it->_2 << ' ';
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