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
const int maxm = 1123;

char G[maxn][maxm];
int n, m, x, y;

void solve() {
  scanf("%d%d%d%d", &n, &m, &x, &y);
  chkmin(y, 2 * x);
  FOR(i, 1, n) scanf("%s", G[i] + 1);
  int ans = 0;
  FOR(i, 1, n) {
    int now = 0;
    FOR(j, 1, m) {
      if (G[i][j] == '*') {
        ans += now / 2 * y + now % 2 * x;
        now = 0;
      } else now++;
    }
    ans += now / 2 * y + now % 2 * x;
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}