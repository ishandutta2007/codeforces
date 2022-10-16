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

const int maxn = 503;
const char C[] = "RGBY";

int n, m, q;
char G[maxn][maxn];
int s[4][maxn][maxn], f[maxn][maxn][maxn];

inline bool check(int r1, int c1, int r2, int c2, int c) {
  return (c2 - c1 + 1) * (r2 - r1 + 1) == s[c][r2][c2] + s[c][r1 - 1][c1 - 1] - s[c][r2][c1 - 1] - s[c][r1 - 1][c2];
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  FOR(i, 1, n) scanf("%s", G[i] + 1);
  FOR(i, 1, n) FOR(j, 1, m) REP(k, 4) {
    s[k][i][j] = s[k][i - 1][j] + s[k][i][j - 1] - s[k][i - 1][j - 1];
    if (G[i][j] == C[k]) s[k][i][j]++;
  }
  int up = min(n, m);
  FOR(len, 2, up) FOR(i, 1, n - len + 1) FOR(j, 1, m - len + 1) {
    f[len][i][j] = max(max(f[len - 1][i][j], f[len - 1][i + 1][j]), max(f[len - 1][i][j + 1], f[len - 1][i + 1][j + 1]));
    if (len % 2 == 0) {
      int ox = i + len / 2, oy = j + len / 2;
      if (check(i, j, ox - 1, oy - 1, 0) && check(i, oy, ox - 1, j + len - 1, 1) && check(ox, oy, i + len - 1, j + len - 1, 2) && check(ox, j, i + len - 1, oy - 1, 3))
        chkmax(f[len][i][j], sqr(len));
    }
  }
  while (q--) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int ans = 0, dr = r2 - r1 + 1, dc = c2 - c1 + 1;
    if (dr >= dc) FOR(i, r1, r2 - dc + 1) chkmax(ans, f[dc][i][c1]);
    else FOR(i, c1, c2 - dr + 1) chkmax(ans, f[dr][r1][i]);
    printf("%d\n", ans);
  }
}