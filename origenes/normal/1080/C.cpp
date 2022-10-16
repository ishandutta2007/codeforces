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

ll get(ll x1, ll y1, ll x2, ll y2, bool black) {
  if (x1 > x2 || y1 > y2) return 0;
  ll ret = (x2 - x1 + 1) * (y2 - y1 + 1) / 2;
  if (!(((x2 ^ x1) | (y2 ^ y1) | (x1 ^ y1 ^ black)) & 1)) ret++;
  return ret;
}

ll x[5], y[5];

int main() {
  int t;
  ll n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &n, &m);
    FOR(i, 1, 4) scanf("%lld%lld", x + i, y + i);
    ll white = get(1, 1, m, n, false) + get(x[1], y[1], x[2], y[2], true) - get(x[3], y[3], x[4], y[4], false);
    white -= get(max(x[1], x[3]), max(y[1], y[3]), min(x[2], x[4]), min(y[2], y[4]), true);
    printf("%lld %lld\n", white, n * m - white);
  }
}