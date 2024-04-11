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

const int maxn = 1123;

int n, m, q, a[maxn][maxn];
char s[maxn][maxn];

inline int check(int x, int y) {
  return __builtin_parity(x ^ y);
}

ll get(int x) {
  if (x <= 1) return 0;
  int pw = __lg(x);
  return (1LL << pw - 1) + (x ^ (1 << pw)) - get(x ^ (1 << pw));
}

ll get(int x, int y) {
  ll xx = get(x), yy = get(y);
  return (x - xx) * yy + (y - yy) * xx;
}

ll solve(ll x, ll y) {
  ll ret = 0;
  if (!check(x / n, y / m)) ret += a[x % n][y % m];
  else ret += (x % n) * (y % m) - a[x % n][y % m];
  ll one = get(x / n), zero = x / n - one;
  if (check(0, y / m)) swap(one, zero);
  ret += zero * a[n][y % m] + one * (y % m * n - a[n][y % m]);
  one = get(y / m), zero = y / m - one;
  if (check(x / n, 0)) swap(one, zero);
  ret += zero * a[x % n][m] + one * ((x % n) * m - a[x % n][m]);
  one = get(x / n, y / m), zero = (x / n) * (y / m) - one;
  ret += zero * a[n][m] + one * (n * m - a[n][m]);
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  REP(i, n) scanf("%s", s[i]);
  REP(i, n) REP(j, m)
    a[i + 1][j + 1] = s[i][j] - '0' + a[i + 1][j] + a[i][j + 1] - a[i][j];
  while (q--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--, y1--;
    printf("%lld\n", solve(x2, y2) + solve(x1, y1) - solve(x1, y2) - solve(x2, y1));
  }
}