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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  ll ans = 1e18;
  REP(i, n) {
    ll now = 0, last = 0;
    ROF(j, i - 1, 0) {
      ll tar = last + 1, inc = (tar + a[j] - 1) / a[j];
      now += inc;
      last = a[j] * inc;
    }
    last = 0;
    FOR(j, i + 1, n - 1) {
      ll tar = last + 1, inc = (tar + a[j] - 1) / a[j];
      now += inc;
      last = a[j] * inc;
    }
    chkmin(ans, now);
  }
  cout << ans;
}