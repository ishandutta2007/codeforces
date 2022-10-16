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
  vector<int> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  int lo = 1, hi = 1e9;
  while (lo < hi) {
    int mi = lo + hi + 1 >> 1, cnt = 0, ans = 0;
    auto b = a;
    FOR(i, 1, n) if (b[i] * 2 < mi) {
      cnt++;
      b[i] = 1e9;
    }
    FOR(i, 1, n - 1) chkmax(ans, (b[i] >= mi) + (b[i + 1] >= mi));
    if (cnt + 2 - ans <= k) lo = mi;
    else hi = mi - 1;
  }
  cout << lo << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}