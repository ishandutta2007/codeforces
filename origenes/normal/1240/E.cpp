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

const int maxn = 512345;

int n;
int a[maxn], cnt[maxn];

ll get(int l, int r) {
  if (l > r) return 0;
  if (!l) return cnt[r];
  return cnt[r] - cnt[l - 1];
}

bool check(int x, int y, ll now) {
  if (2 * x > a[n] && x > a[n - 1]) return false;
  ll f = now - 2 * (x / y), g = now - 2 * x / y;
  if (f - 2 >= x) return true;
  if (f < x) return false;
  ll cur[2] = {};
  for (int k = 0; k * y <= 5e5; k++) {
    int l = k * y, r = min(k * y + y - 1, int(5e5));
    if (2 * x <= r) cur[1] += get(max(2 * x, l + 2 * x % y), r);
    if (x <= r) cur[0] += get(max(x, l + x % y), r);
  }
  if (a[n - 1] >= x && f - 2 + min(2LL, cur[0]) >= x) return true;
  if (a[n] >= 2 * x && g - 1 + min(1LL, cur[1]) >= x) return true;
  return false;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  sort(a + 1, a + n + 1);
  FOR(i, 1, maxn - 1) cnt[i] = cnt[i - 1] + cnt[i];
  ll ans = 0;
  FOR(y, 2, int(5e5)) {
    ll now = 0;
    for (int k = 1; k * y <= 5e5; k++) now += get(k * y, min(k * y + y - 1, int(5e5))) * k;
    int lo = 2, hi = 5e5;
    if (!check(lo, y, now)) continue;
    while (lo < hi) {
      int mi = lo + hi + 1 >> 1;
      if (check(mi, y, now)) lo = mi;
      else hi = mi - 1;
    }
    chkmax(ans, lo * ll(y));
  }
  printf("%lld", ans);
}