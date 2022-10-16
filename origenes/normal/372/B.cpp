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

const int maxn = 45;

int n, m, q;
char s[maxn][maxn];
int f[maxn][maxn][maxn][maxn], last[maxn][maxn];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  FOR(i, 1, n) scanf("%s", s[i] + 1);
  FOR(i, 1, n) FOR(j, 1, m) last[i][j] = s[i][j] == '1' ? j : last[i][j - 1];
  FOR(a, 1, n) FOR(b, 1, m) FOR(c, a, n) FOR(d, b, m) {
    f[a][b][c][d] = f[a][b][c - 1][d] + f[a][b][c][d - 1] - f[a][b][c - 1][d - 1];
    int pre = b - 1;
    ROF(i, c, a) {
      chkmax(pre, last[i][d]);
      f[a][b][c][d] += d - pre;
    }
  }
  while (q--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", f[a][b][c][d]);
  }
}