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
  vector<int> x(n), y(n);
  REP(i, n) cin >> x[i] >> y[i];
  ll ans = 0;
  REP(i, n) {
    auto mod = [](int x) {
      return (x % 4 + 4) % 4;
    };
    int cnt[4][4][4] = {};
    REP(j, n) if (j != i) cnt[mod(x[j] - x[i])][mod(y[j] - y[i])][gcd(abs(x[i] - x[j]), abs(y[i] - y[j])) % 4]++;
    REP(j, 4) REP(k, 4) REP(_i, 4) FOR(jj, j, 3) {
      for (int kk = j == jj ? k : 0; kk < 4; kk++) {
        int dj = mod(jj - j), dk = mod(kk - k);
        if (dj % 2 || dk % 2) continue;
        int opp = dj || dk ? 2 : 0, area = (j * k + (jj - j) * (kk + k) + (4 - jj) * kk) % 4;
        int ii = mod(area - _i - opp);
        if (j == jj && k == kk && _i > ii) continue;
        int coeff = _i % 2 == 1 ? 3 : 1;
        if (j == jj && k == kk && _i == ii) ans += cnt[j][k][_i] * (cnt[j][k][_i] - 1) / 2 * coeff;
        else ans += cnt[j][k][_i] * cnt[jj][kk][ii] * coeff;
      }
    }
  }
  cout << ans / 3;
}