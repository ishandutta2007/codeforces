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

const int maxn = 112345;

ll f(ll a, ll b, ll c) {
  return sqr(a - b) + sqr(a - c) + sqr(b - c);
}

int nr, ng, nb;
ll r[maxn], g[maxn], b[maxn];

void solve() {
  scanf("%d%d%d", &nr, &ng, &nb);
  FOR(i, 1, nr) scanf("%lld", r + i);
  FOR(i, 1, ng) scanf("%lld", g + i);
  FOR(i, 1, nb) scanf("%lld", b + i);
  sort(r + 1, r + nr + 1);
  sort(g + 1, g + ng + 1);
  sort(b + 1, b + nb + 1);
  ll ans = 4e18;
  FOR(i, 1, nr) {
    int x = r[i];
    int ri = lower_bound(g + 1, g + ng + 1, x) - g, rj = lower_bound(b + 1, b + nb + 1, x) - b;
    if (ri != ng + 1 && rj != nb + 1) {
      if (g[ri] < b[rj]) {
        ll tar = (b[rj] + x) / 2;
        int y1 = lower_bound(g + ri, g + ng + 1, tar) - g, y2 = y1 - 1;
        if (y1 != ng + 1) chkmin(ans, f(x, g[y1], b[rj]));
        if (y2) chkmin(ans, f(x, g[y2], b[rj]));
      } else {
        ll tar = (g[ri] + x) / 2;
        int z1 = lower_bound(b + rj, b + nb + 1, tar) - b, z2 = z1 - 1;
        if (z1 != nb + 1) chkmin(ans, f(x, g[ri], b[z1]));
        if (z2) chkmin(ans, f(x, g[ri], b[z2]));
      }
    }
    int li = lower_bound(g + 1, g + ng + 1, x) - g - 1, lj = lower_bound(b + 1, b + nb + 1, x) - b - 1;
    if (li && lj) {
      if (g[li] < b[lj]) {
        ll tar = (g[li] + x) / 2;
        int z1 = lower_bound(b + 1, b + lj + 1, tar) - b, z2 = z1 - 1;
        if (z1 != lj + 1) chkmin(ans, f(x, g[li], b[z1]));
        if (z2) chkmin(ans, f(x, g[li], b[z2]));
      } else {
        ll tar = (b[lj] + x) / 2;
        int y1 = lower_bound(g + 1, g + li + 1, tar) - g, y2 = y1 - 1;
        if (y1 != li + 1) chkmin(ans, f(x, g[y1], b[lj]));
        if (y2) chkmin(ans, f(x, g[y2], b[lj]));
      }
    }
    if (ri != ng + 1 && lj) chkmin(ans, f(x, g[ri], b[lj]));
    if (rj != nb + 1 && li) chkmin(ans, f(x, g[li], b[rj]));
  }
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}