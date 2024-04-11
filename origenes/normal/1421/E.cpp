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

const int maxn = 212345;

int n, a[maxn];
ll f[maxn][3][2][2];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  if (n == 1) {
    printf("%d", a[1]);
    return 0;
  }
  reset(f, 0xc0);
  f[1][1][0][1] = a[1], f[1][2][0][0] = -a[1];
  FOR(i, 1, n - 1) REP(j, 3) REP(k, 2) REP(x, 2) REP(y, 2) {
    int nj = (j + 2 - y) % 3, nk = k | (x == y);
    chkmax(f[i + 1][nj][nk][y], f[i][j][k][x] + (y == 1 ? a[i + 1] : -a[i + 1]));
  }
  printf("%lld", max(f[n][1][1][0], f[n][1][1][1]));
}