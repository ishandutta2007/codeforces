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

const int maxn = 112;

int n, val[maxn], x[maxn], y[maxn];
int f[maxn][maxn][4][4];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d%d%d", x + i, val + i, y + i);
    x[i]--, y[i]--;
  }
  reset(f, 0xc0);
  FOR(i, 1, n) f[i][i][x[i]][y[i]] = f[i][i][y[i]][x[i]] = val[i];
  FOR(l, 2, n) FOR(i, 1, n - l + 1) {
    int j = i + l - 1;
    FOR(k, i, j - 1) REP(c1, 4) REP(c2, 4) {
      chkmax(f[i][j][c1][c2], f[i][k][c1][c2]);
      chkmax(f[i][j][c1][c2], f[k + 1][j][c1][c2]);
      REP(c3, 4) {
        chkmax(f[i][j][c1][c2], f[i][k][c1][c3] + f[k + 1][j][c3][c2]);
        chkmax(f[i][j][c1][c2], f[i][k][c3][c2] + f[k + 1][j][c1][c3]);
      }
    }
  }
  int ans = 0;
  REP(c1, 4) REP(c2, 4) chkmax(ans, f[1][n][c1][c2]);
  printf("%d", ans);
}