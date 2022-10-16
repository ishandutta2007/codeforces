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

int a[maxn], n, f[maxn][maxn][maxn][2];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  int even = n / 2, odd = (n + 1) / 2;
  FOR(i, 1, n) if (a[i]) {
    if (a[i] % 2 == 0) even--;
    else odd--;
  }
  reset(f, 0x3f);
  if (a[1]) {
    f[1][even][odd][a[1] % 2] = 0;
  } else {
    if (even) f[1][even - 1][odd][0] = 0;
    if (odd) f[1][even][odd - 1][1] = 0;
  }
  FOR(i, 2, n) REP(j, even + 1) REP(k, odd + 1) REP(par, 2) {
    if (a[i]) {
      if (par != a[i] % 2) continue;
      f[i][j][k][par] = min(f[i - 1][j][k][0] + (par != 0), f[i - 1][j][k][1] + (par != 1));
    } else {
      if (par == 0) {
        chkmin(f[i][j][k][0], f[i - 1][j + 1][k][0]);
        chkmin(f[i][j][k][0], f[i - 1][j + 1][k][1] + 1);
      } else {
        chkmin(f[i][j][k][1], f[i - 1][j][k + 1][0] + 1);
        chkmin(f[i][j][k][1], f[i - 1][j][k + 1][1]);
      }
    }
  }
  printf("%d", min(f[n][0][0][0], f[n][0][0][1]));
}