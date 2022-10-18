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

const int maxn = 212;

int n, k;
ll x[maxn], y[maxn];
pair<int, ll> f[maxn][maxn];

int check(ll mi) {
  FOR(gap, 1, n - 1) REP(r, n) {
    int l = (r + gap) % n;
    if (gap == 1) {
      f[l][r] = {0, 0};
      continue;
    }
    f[l][r] = {-1, -1};
    for (int i = r; i != l; i = (i + 1) % n) {
      ll delta = (x[r] - x[l]) * (y[i] - y[l]) - (x[i] - x[l]) * (y[r] - y[l]);
      auto now = mp(f[l][i]._1 + f[i][r]._1, f[l][i]._2 + f[i][r]._2 + delta);
      if (now._2 >= mi) {
        now._2 = 0;
        now._1++;
      }
      chkmax(f[l][r], now);
    }
  }
  int ans = 0;
  REP(i, n) chkmax(ans, f[i][(i + 1) % n]._1);
  return ans;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  REP(i, n) cin >> x[i] >> y[i];
  ll lo = 0, hi = 1e18;
  while (lo < hi) {
    ll mi = lo + hi + 1 >> 1;
    if (check(mi) >= k + 1) lo = mi;
    else hi = mi - 1;
  }
  cout << lo;
}