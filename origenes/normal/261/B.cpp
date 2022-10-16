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

const int maxn = 55;

int n, p;
int a[maxn];
double f[maxn][maxn][maxn], g[maxn];
// f[first][sel][rem]

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  scanf("%d", &p);
  g[0] = 1;
  FOR(i, 1, n) g[i] = g[i - 1] * i;
  double ans = 0;
  REP(l, n + 1) {
    reset(f, 0);
    f[0][0][0] = 1;
    FOR(i, 1, n) REP(j, i + 1) REP(k, p + 1) {
      f[i][j][k] = f[i - 1][j][k];
      if (l != i && j >= 1 && a[i] <= k) f[i][j][k] += f[i - 1][j - 1][k - a[i]];
    }
    FOR(j, 1, n - 1) FOR(k, 1, p) if (a[l] > p - k) ans += f[n][j][k] * j * (g[j] * g[n - 1 - j] / g[n]);
    FOR(k, 1, p) ans += f[n][n][k] * n;
  }
  printf("%.10lf", ans);
}