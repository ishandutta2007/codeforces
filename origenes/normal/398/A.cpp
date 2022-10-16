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

ll a, b;

int main() {
  scanf("%lld%lld", &a, &b);
  if (a == 0) {
    printf("%lld\n", -sqr(b));
    REP(i, b) putchar('x');
    return 0;
  }
  if (b <= 1) {
    printf("%lld\n", sqr(a) - sqr(b));
    REP(i, a) putchar('o');
    if (b) putchar('x');
    return 0;
  }
  ll ans = sqr(a) - sqr(b);
  int best = 0;
  FOR(i, 1, a) {
    ll now = sqr(a - i + 1) + i - 1;
    ll lo = b / (i + 1), d = b - lo * (i + 1), c = i + 1 - d;
    now -= sqr(lo) * c + sqr(lo + 1) * d;
    if (now > ans) {
      ans = now;
      best = i;
    }
  }
  printf("%lld\n", ans);
  int lo = b / (best + 1), d = b - lo * (best + 1), c = best + 1 - d;
  REP(i, lo) putchar('x');
  c--;
  REP(i, a - best) putchar('o');
  while (c--) {
    putchar('o');
    REP(i, lo) putchar('x');
  }
  while (d--) {
    putchar('o');
    REP(i, lo + 1) putchar('x');
  }
}