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

int q, n;

int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    if (n <= 5) {
      printf("%d\n", n - 1);
      continue;
    }
    int lo = 3, hi = n;
    while (lo < hi) {
      int mi = (hi - lo + 1) / 2 + lo;
      if (n - mi >=  mi * ll(mi - 1) / 2) lo = mi;
      else hi = mi - 1;
    }
    printf("%lld\n", max(2 * ll(n - lo - 1), n - lo + lo * ll(lo - 1) / 2));
  }
}