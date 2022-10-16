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

const int maxn = 312345;

int n, q;
int a[maxn], d[maxn];

void solve() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) d[i] = a[i] - a[i - 1];
  ll ans = 0;
  FOR(i, 1, n) if (d[i] > 0) ans += d[i];
  printf("%lld\n", ans);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l == r) {
      printf("%lld\n", ans);
      continue;
    }
    if (d[l] > 0) ans -= d[l];
    if (d[l + 1] > 0) ans -= d[l + 1];
    if (r != l + 1 && d[r] > 0) ans -= d[r];
    if (d[r + 1] > 0) ans -= d[r + 1];
    swap(a[l], a[r]);
    d[l] = a[l] - a[l - 1];
    if (d[l] > 0) ans += d[l];
    d[l + 1] = a[l + 1] - a[l];
    if (d[l + 1] > 0) ans += d[l + 1];
    d[r] = a[r] - a[r - 1];
    if (r != l + 1 && d[r] > 0) ans += d[r];
    if (r != n) {
      d[r + 1] = a[r + 1] - a[r];
      if (d[r + 1] > 0) ans += d[r + 1];
    }
    printf("%lld\n", ans);
  }
  FOR(i, 1, n) d[i] = a[i] = 0;
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}