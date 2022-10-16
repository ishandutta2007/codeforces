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

int n, m, k, q, en;
int pre[maxn], suf[maxn], lo[maxn], hi[maxn];

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  fill(lo + 1, lo + n + 1, m + 1);
  while (k--) {
    int x, y;
    scanf("%d%d", &x, &y);
    chkmax(hi[x], y);
    chkmin(lo[x], y);
    chkmax(en, x);
  }
  ll ans = en - 1;
  while (q--) {
    int x;
    scanf("%d", &x);
    pre[x] = suf[x] = x;
  }
  FOR(i, 1, m) if (!pre[i]) pre[i] = pre[i - 1];
  ROF(i, m, 1) if (!suf[i]) suf[i] = suf[i + 1];
  int pl = 1, pr = 1;
  ll pL = 0, pR = 0;
  FOR(i, 1, en) if (hi[i]) {
    int l = lo[i], r = hi[i];
    ll L = 1e18, R = 1e18;
    ans += r - l;
    if (i == 1) {
      L = r - 1;
      R = l - 1;
    } else {
      if (pre[pl]) {
        chkmin(L, pL + pl - pre[pl] + abs(pre[pl] - r));
        chkmin(R, pL + pl - pre[pl] + abs(pre[pl] - l));
      }
      if (suf[pl]) {
        chkmin(L, pL + suf[pl] - pl + abs(suf[pl] - r));
        chkmin(R, pL + suf[pl] - pl + abs(suf[pl] - l));
      }
      if (pre[pr]) {
        chkmin(L, pR + pr - pre[pr] + abs(pre[pr] - r));
        chkmin(R, pR + pr - pre[pr] + abs(pre[pr] - l));
      }
      if (suf[pr]) {
        chkmin(L, pR + suf[pr] - pr + abs(suf[pr] - r));
        chkmin(R, pR + suf[pr] - pr + abs(suf[pr] - l));
      }
    }
    pl = l, pr = r;
    pL = L, pR = R;
  }
  printf("%lld", ans + min(pL, pR));
}