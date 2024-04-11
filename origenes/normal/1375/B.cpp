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

const int maxn = 312;

int n, m;
int a[maxn][maxn];

void solve() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) FOR(j, 1, m) scanf("%d", &a[i][j]);
  if (a[1][1] > 2 || a[1][m] > 2 || a[n][1] > 2 || a[n][m] > 2) {
    puts("NO");
    return;
  }
  a[1][1] = a[1][m] = a[n][1] = a[n][m] = 2;
  FOR(i, 2, n - 1) {
    if (a[i][1] > 3 || a[i][m] > 3) {
      puts("NO");
      return;
    }
    a[i][1] = a[i][m] = 3;
  }
  FOR(j, 2, m - 1) {
    if (a[1][j] > 3 || a[n][j] > 3) {
      puts("NO");
      return;
    }
    a[1][j] = a[n][j] = 3;
  }
  FOR(i, 2, n - 1) FOR(j, 2, m - 1) {
    if (a[i][j] > 4) {
      puts("NO");
      return;
    }
    a[i][j] = 4;
  }
  puts("YES");
  FOR(i, 1, n) {
    FOR(j, 1, m) printf("%d ", a[i][j]);
    putchar('\n');
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}