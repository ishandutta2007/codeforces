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

char mat[maxn][maxn];
int up[maxn][maxn], down[maxn][maxn];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%s", mat[i] + 1);
  FOR(j, 1, m) FOR(i, 1, n) {
    if (i != 1 && mat[i][j] == mat[i - 1][j]) {
      up[i][j] = up[i - 1][j];
      down[i][j] = down[i - 1][j];
      continue;
    }
    up[i][j] = i;
    FOR(k, i + 1, n + 1) if (mat[i][j] != mat[k][j]) {
      down[i][j] = k - 1;
      break;
    }
  }
  int ans = 0;
  FOR(i, 1, n) {
    int pre = 1;
    FOR(j, 1, m) {
      if (up[i][j] == i) {
        if (mat[i][pre] != mat[i][j] || down[i][pre] != down[i][j]) pre = j;
        if (i > 1 && up[i - 1][j] <= 2 * i - down[i][j] - 1 && down[i][j] < n && down[down[i][j] + 1][j] >= 2 * down[i][j] - i + 1) {
          if (mat[i - 1][j] != mat[i - 1][pre] || mat[down[i][j] + 1][j] != mat[down[i][j] + 1][pre]) pre = j;
          ans += j - pre + 1;
        } else pre = j + 1;
      } else {
        pre = j + 1;
      }
    }
  }
  printf("%d", ans);
}