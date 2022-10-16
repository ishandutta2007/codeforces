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
const int MOD = 1e9 + 7;

int n, m;
int mark[maxn][maxn];

int main() {
  scanf("%d%d", &n, &m);
  reset(mark, -1);
  FOR(i, 1, n) {
    int r; scanf("%d", &r);
    FOR(j, 1, r) mark[i][j] = 1;
    mark[i][r + 1] = 0;
  }
  FOR(j, 1, m) {
    int c; scanf("%d", &c);
    FOR(i, 1, c) {
      if (!mark[i][j]) {
        puts("0");
        return 0;
      }
      mark[i][j] = 1;
    }
    if (mark[c + 1][j] == 1) {
      puts("0");
      return 0;
    }
    mark[c + 1][j] = 0;
  }
  int ans = 1;
  FOR(i, 1, n) FOR(j, 1, m) if (!~mark[i][j]) ans = ans * 2 % MOD;
  printf("%d", ans);
}