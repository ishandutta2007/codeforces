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

const int maxn = 2123;

ll k;
int n;
ll f[maxn], l[maxn], r[maxn], a[maxn];

int main() {
  scanf("%d%lld", &n, &k);
  FOR(i, 1, n) scanf("%lld%lld%lld", l + i, r + i, a + i);
  reset(f, 0x3f);
  f[1] = 0;
  ll ans = 1e18;
  FOR(i, 1, n) {
    ll now = k, s = f[i];
    FOR(j, i, n) {
      ll req = (max(0LL, a[j] - now) + k - 1) / k;
      if (req > r[j] - l[j]) break;
      now = now + req * k - a[j];
      s += a[j];
      if (j != n) {
        if (l[j] + req < l[j + 1]) chkmin(f[j + 1], s + now);
      } else chkmin(ans, s);
    }
  }
  if (ans > 5e17) ans = -1;
  printf("%lld", ans);
}