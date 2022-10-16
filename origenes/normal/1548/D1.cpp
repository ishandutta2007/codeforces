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
  vector<vector<int>> cnt(2, vector<int>(2));
  while (n--) {
    int x, y;
    cin >> x >> y;
    x /= 2, y /= 2;
    cnt[x & 1][y & 1]++;
  }
  ll ans = 0;
  REP(i, 2) REP(j, 2) ans += ll(cnt[i][j]) * (cnt[i][j] - 1) * (cnt[i][j] - 2) / 6;
  REP(i, 2) REP(j, 2) REP(ii, 2) REP(jj, 2) if (ii != i || jj != j)
    ans += cnt[i][j] * ll(cnt[ii][jj]) * (cnt[ii][jj] - 1) / 2;
  ll three = 0;
  REP(i, 2) REP(j, 2) REP(ii, 2) REP(jj, 2) {
    if (ii == i && jj == j) continue;
    REP(iii, 2) REP(jjj, 2) {
      if ((iii == i && jjj == j) || (iii == ii && jjj == jj)) continue;
      int d = gcd(abs(ii - i), abs(jj - j)) + gcd(abs(iii - i), abs(jjj - j)) + gcd(abs(iii - ii), abs(jjj - jj));
      if (d % 2 == 0) three += ll(cnt[i][j]) * cnt[ii][jj] * cnt[iii][jjj];
    }
  }
  ans += three / 6;
  cout << ans;
}