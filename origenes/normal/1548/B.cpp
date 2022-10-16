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

const int maxn = 212345;

ll a[maxn], f[maxn][18];

void solve() {
  int n; cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n - 1) f[i][0] = abs(a[i] - a[i + 1]);
  FOR(j, 1, 17) FOR(i, 1, n - (1 << j)) f[i][j] = gcd(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
  int best = 1;
  FOR(i, 1, n - 1) if (f[i][0] > 1) {
    int lo = 1, hi = n - i;
    while (lo < hi) {
      int mi = lo + hi + 1 >> 1, k = 0;
      while ((1 << k + 1) <= mi) k++;
      ll g = gcd(f[i][k], f[i + mi - (1 << k)][k]);
      if (g != 1) lo = mi;
      else hi = mi - 1;
    }
    chkmax(best, lo + 1);
  }
  cout << best << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}