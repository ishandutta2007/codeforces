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

int n, m;
char G[maxn][maxn];
int lu[maxn][maxn], ru[maxn][maxn], ld[maxn][maxn], rd[maxn][maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%s", G[i] + 1);
  FOR(i, 1, n) FOR(j, 1, m) {
    if (G[i - 1][j] == G[i][j - 1] && G[i][j] == G[i - 1][j]) lu[i][j] = min(lu[i - 1][j], lu[i][j - 1]) + 1;
    else lu[i][j] = 1;
  }
  FOR(i, 1, n) ROF(j, m, 1) {
    if (G[i - 1][j] == G[i][j + 1] && G[i][j] == G[i - 1][j]) ru[i][j] = min(ru[i - 1][j], ru[i][j + 1]) + 1;
    else ru[i][j] = 1;
  }
  ROF(i, n, 1) FOR(j, 1, m) {
    if (G[i + 1][j] == G[i][j - 1] && G[i][j] == G[i + 1][j]) ld[i][j] = min(ld[i + 1][j], ld[i][j - 1]) + 1;
    else ld[i][j] = 1;
  }
  ROF(i, n, 1) ROF(j, m, 1) {
    if (G[i + 1][j] == G[i][j + 1] && G[i][j] == G[i + 1][j]) rd[i][j] = min(rd[i + 1][j], rd[i][j + 1]) + 1;
    else rd[i][j] = 1;
  }
  ll ans = 0;
  FOR(i, 1, n) FOR(j, 1, m) ans += min({lu[i][j], ru[i][j], ld[i][j], rd[i][j]});
  printf("%lld", ans);
}