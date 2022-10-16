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

const int maxn = 2123;
const int MOD = 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int n, m;
char s[maxn][maxn];
int f[maxn][maxn][2], r_rock[maxn][maxn], c_rock[maxn][maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%s", s[i] + 1);
  if (n == 1 && m == 1) {
    printf("%d", s[1][1] == '.');
    return 0;
  }
  FOR(i, 1, n) ROF(j, m, 1) r_rock[i][j] = r_rock[i][j + 1] + (s[i][j] == 'R');
  FOR(j, 1, m) ROF(i, n, 1) c_rock[j][i] = c_rock[j][i + 1] + (s[i][j] == 'R');
  f[1][1][0] = f[1][1][1] = 1;
  f[1][2][0] = f[2][1][1] = MOD - 1;
  FOR(i, 1, n) FOR(j, 1, m) {
    f[i][j][0] = add(f[i][j - 1][0], f[i][j][0]);
    f[i][j][1] = add(f[i - 1][j][1], f[i][j][1]);
    int reach = n - c_rock[j][i] + (s[i][j] == 'R');
    if (reach > i) {
      f[i + 1][j][1] = add(f[i + 1][j][1], f[i][j][0]);
      f[reach + 1][j][1] = add(f[reach + 1][j][1], MOD - f[i][j][0]);
    }
    reach = m - r_rock[i][j] + (s[i][j] == 'R');
    if (reach > j) {
      f[i][j + 1][0] = add(f[i][j + 1][0], f[i][j][1]);
      f[i][reach + 1][0] = add(f[i][reach + 1][0], MOD - f[i][j][1]);
    }
  }
  printf("%d", add(f[n][m][0], f[n][m][1]));
}