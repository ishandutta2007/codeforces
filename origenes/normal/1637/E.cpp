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
  int n, m;
  cin >> n >> m;
  map<int, int> cnt;
  FOR(i, 1, n) {
    int x; cin >> x;
    cnt[x]++;
  }
  set<ll> bad;
  auto h = [](int x, int y) {
    if (x > y) swap(x, y);
    ll MOD = 1e9 + 7;
    return x * MOD + y;
  };
  while (m--) {
    int x, y;
    cin >> x >> y;
    bad.emplace(h(x, y));
  }
  set<int> cnts;
  vector<vector<int>> keys(n + 1);
  for (auto [k, v] : cnt) {
    cnts.emplace(v);
    keys[v].eb(k);
  }
  for (auto &v : keys) sort(all(v), greater<>());
  ll ans = 0;
  for (auto cx : cnts) for (auto cy : cnts) {
    if (cy > cx) break;
    for (auto x : keys[cx]) for (auto y : keys[cy]) {
      if (x != y) {
        if (bad.count(h(x, y))) continue;
        chkmax(ans, ll(x + y) * (cx + cy));
        break;
      }
    }
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