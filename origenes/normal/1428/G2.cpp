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

const int base[] = {1, 10, 100, 1000, 10000, 100000};
const int maxn = 1123456;

int k, q;
ll F[6], f[maxn];

int main() {
  scanf("%d", &k);
  REP(i, 6) scanf("%lld", F + i);
  reset(f, 0xc0);
  f[0] = 0;
  REP(pos, 6) {
    int rem = 3 * (k - 1), x = 1;
    while (rem > 0) {
      chkmin(x, rem);
      ll v = x * F[pos], w = 3LL * x * base[pos];
      ROF(i, 999999, w) chkmax(f[i], f[i - w] + v);
      rem -= x;
      x <<= 1;
    }
  }
  REP(pos, 6) ROF(i, 999999, 0) FOR(d, 1, 9) {
    ll w = base[pos] * d;
    if (i < w) break;
    ll v = d % 3 ? 0 : d / 3 * F[pos];
    chkmax(f[i], f[i - w] + v);
  }
  scanf("%d", &q);
  while (q--) {
    int n; scanf("%d", &n);
    printf("%lld\n", f[n]);
  }
}