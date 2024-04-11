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
  ll w;
  cin >> n >> w;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  REP(i, n) if (a[i] >= (w + 1) / 2 && a[i] <= w) {
    cout << 1 << '\n' << i + 1 << '\n';
    return;
  }
  ll s = 0;
  vector<int> ans;
  REP(i, n) if (a[i] <= w) {
    s += a[i];
    ans.eb(i + 1);
    if (s >= (w + 1) / 2) {
      cout << ans.size() << '\n';
      for (auto x : ans) cout << x << ' ';
      cout << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}