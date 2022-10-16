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

const int maxn = 1123456;

int n;
ll a[maxn];

ll go(int l, int r, int mi, bool eq) {
  ll ret = 0;
  vector<int> cnt(64);
  int lo = mi, hi = mi;
  ll lmn = 2e18, lmx = -2e18, rmn = 2e18, rmx = -2e18, smn = 2e18;
  ROF(i, mi, l) {
    chkmin(lmn, a[i]); chkmax(lmx, a[i]);
    while (hi + 1 <= r && (eq ? max(rmx, a[hi + 1]) <= lmx : max(rmx, a[hi + 1]) < lmx)) {
      chkmax(rmx, a[hi + 1]); chkmin(rmn, a[hi + 1]);
      cnt[__builtin_popcountll(rmn)]++;
      hi++;
    }
    while (lo < hi && min(smn, a[lo + 1]) > lmn) {
      chkmin(smn, a[lo + 1]);
      cnt[__builtin_popcountll(smn)]--;
      lo++;
    }
    ret += cnt[__builtin_popcountll(lmx)];
    if (__builtin_popcountll(lmx) == __builtin_popcountll(lmn)) ret += lo - mi;
  }
  return ret;
}

ll solve(int l, int r) {
  if (l == r) return 1;
  int mi = l + r >> 1;
  ll ret = solve(l, mi) + solve(mi + 1, r);
  ret += go(l, r, mi, false);
  reverse(a + l, a + r + 1);
  ret += go(l, r, l + r - mi - 1, true);
  reverse(a + l, a + r + 1);
  return ret;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  cout << solve(1, n);
}