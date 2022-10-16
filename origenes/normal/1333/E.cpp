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

const int maxn = 512;

int n, ans[maxn][maxn];

int main() {
  scanf("%d", &n);
  if (n < 3) {
    puts("-1");
    return 0;
  }
  int off = sqr(n) - 9;
  ans[1][1] = 4; ans[1][2] = 5; ans[1][3] = 9;
  ans[2][1] = 3; ans[2][2] = 2; ans[2][3] = 6;
  ans[3][1] = 1; ans[3][2] = 8; ans[3][3] = 7;
  FOR(i, 1, 3) FOR(j, 1, 3) ans[i][j] += off;
  int rem = n, cnt = 0;
  while (rem > 3) {
    if (rem & 1) {
      FOR(i, 1, rem) ans[rem][i] = ++cnt;
      ROF(i, rem - 1, 1) ans[i][rem] = ++cnt;
    } else {
      FOR(i, 1, rem) ans[i][rem] = ++cnt;
      ROF(i, rem - 1, 1) ans[rem][i] = ++cnt;
    }
    rem--;
  }
  FOR(i, 1, n) {
    FOR(j, 1, n) printf("%d ", ans[i][j]);
    putchar('\n');
  }
}