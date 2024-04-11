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

int h[maxn];
ll s[maxn];
int n, a, r, m;

ll calc(ll H) {
  ll need = 0, extra = 0;
  FOR(i, 1, n) {
    if (h[i] < H) need += H - h[i];
    else extra += h[i] - H;
  }
  if (need >= extra) return (need - extra) * a + extra * m;
  return (extra - need) * r + need * m;
}

int main() {
  scanf("%d%d%d%d", &n, &a, &r, &m);
  FOR(i, 1, n) scanf("%d", h + i);
  sort(h + 1, h + n + 1);
  FOR(i, 1, n) s[i] = s[i - 1] + h[i];
  chkmin(m, a + r);
  ll ans = s[n] * r;
  FOR(i, 1, n) {
    ll need = i * ll(h[i]) - s[i], extra = s[n] - s[i] - (n - i) * ll(h[i]);
    if (need >= extra) chkmin(ans, (need - extra) * a + extra * m);
    else chkmin(ans, (extra - need) * r + need * m);
    ll dis = h[i] - h[i - 1];
    ll pneed = (i - 1) * ll(h[i - 1]) - s[i - 1], pextra = s[n] - s[i - 1] - (n - i + 1) * ll(h[i - 1]);
    if (extra < need && pextra > pneed) {
      ll delta = need - extra + pextra - pneed;
      ll h1 = h[i] - dis * (need - extra) / delta, h2 = h1 - 1;
      chkmin(ans, calc(h1));
      chkmin(ans, calc(h2));
    }
  }
  printf("%lld", ans);
}