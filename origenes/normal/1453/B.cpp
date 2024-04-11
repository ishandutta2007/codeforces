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
  cin >> n;
  vector<int> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  vector<vector<ll>> f(n + 1, vector<ll>(2));
  ROF(i, n - 1, 1) {
    f[i][0] = f[i + 1][0] + abs(a[i] - a[i + 1]);
    f[i][1] = f[i + 1][1] + abs(a[i] - a[i + 1]);
    if (i + 2 <= n) chkmin(f[i][1], f[i + 2][0] + abs(a[i] - a[i + 2]));
    else chkmin(f[i][1], 0LL);
  }
  cout << min(f[1][1], f[2][0]) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}