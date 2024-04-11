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

ll f[maxn], g[maxn], h[maxn], suf[maxn], a[maxn];
int r1, r2, r3, d, n;

int main() {
  scanf("%d%d%d%d%d", &n, &r1, &r2, &r3, &d);
  FOR(i, 1, n) scanf("%lld", a + i);
  reset(f, 0x3f);
  FOR(i, 1, n) {
    g[i] = min(r1 * (a[i] + 2), ll(r1) + r2);
    h[i] = min(g[i] + 2 * d, r1 * a[i] + r3);
    g[i] += d;
  }
  suf[n] = h[n];
  ROF(i, n - 1, 1) suf[i] = suf[i + 1] + g[i];
  f[0] = 0;
  ll ans = 1e18;
  REP(i, n) {
    chkmin(ans, f[i] + suf[i + 1]);
    chkmin(f[i + 1], f[i] + h[i + 1]);
    if (i + 2 <= n) chkmin(f[i + 2], f[i] + g[i + 1] + g[i + 2]);
  }
  chkmin(ans, f[n]);
  printf("%lld", ans + ll(n - 1) * d);
}