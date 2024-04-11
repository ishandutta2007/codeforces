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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 1123456;

int a[maxn], lo[maxn], hi[maxn];
int n, x, L, R;

int main() {
  scanf("%d%d", &n, &x);
  reset(lo, 0x3f);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    chkmin(lo[a[i]], i);
    chkmax(hi[a[i]], i);
  }
  int pre = hi[0];
  L = x - 1, R = 2;
  FOR(i, 1, x) {
    if (lo[i] < pre) {
      L = i - 1;
      break;
    }
    chkmax(pre, hi[i]);
  }
  pre = lo[x + 1];
  ROF(i, x, 1) {
    if (hi[i] > pre) {
      R = i + 1;
      break;
    }
    chkmin(pre, lo[i]);
  }
  FOR(i, 1, x) chkmax(hi[i], hi[i - 1]);
  ROF(i, x - 1, 0) chkmin(lo[i], lo[i + 1]);
  ll ans = 0;
  int r = R;
  REP(l, L + 1) {
    while (r < l + 2 || lo[r] < hi[l]) r++;
    ans += x + 2 - r;
  }
  printf("%lld", ans);
}