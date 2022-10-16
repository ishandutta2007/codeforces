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
  int l, n;
  cin >> l >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  auto check = [&](int mn, int mx) -> vector<int> {
    vector<pii> segs(n + 1);
    REP(i, n) {
      int b = a[i], nb;
      if (i == n - 1) nb = l;
      else nb = a[i + 1];
      segs[i + 1] = {segs[i]._1 + mn, segs[i]._2 + mx};
      if (segs[i + 1]._1 > nb || segs[i + 1]._2 < b) return {};
      chkmax(segs[i + 1]._1, b); chkmin(segs[i + 1]._2, nb);
    }
    if (segs[n]._2 < l) return {};
    segs[n] = {l, l};
    ROF(i, n - 1, 0) {
      chkmax(segs[i]._1, segs[i + 1]._1 - mx);
      chkmin(segs[i]._2, segs[i + 1]._2 - mn);
    }
    vector<int> ans(n + 1);
    REP(i, n + 1) ans[i] = segs[i]._1;
    return ans;
  };
  int mn, mx;
  {
    int lo = 1, hi = l;
    while (lo < hi) {
      int mi = lo + hi >> 1;
      if (!check(1, mi).empty()) hi = mi;
      else lo = mi + 1;
    }
    mx = lo;
  }
  {
    int lo = 1, hi = mx;
    while (lo < hi) {
      int mi = lo + hi + 1 >> 1;
      if (!check(mi, mx).empty()) lo = mi;
      else hi = mi - 1;
    }
    mn = lo;
  }
  auto ans = check(mn, mx);
  REP(i, n) cout << ans[i] << ' ' << ans[i + 1] << '\n';
}