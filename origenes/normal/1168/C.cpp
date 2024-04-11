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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 312345;

int nxt[maxn][19], now[19], a[maxn];
int n, q;

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) scanf("%d", a + i);
  REP(i, 19) now[i] = n + 1;
  ROF(i, n, 1) {
    REP(j, 19) nxt[i][j] = n + 1;
    REP(j, 19) if (a[i] & (1 << j)) {
      int pre = now[j];
      now[j] = i;
      if (pre != n + 1) {
        chkmin(nxt[i][j], pre);
        REP(k, 19) chkmin(nxt[i][k], nxt[pre][k]);
      }
    }
  }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    bool ans = false;
    REP(i, 19) if ((a[y] & (1 << i)) && nxt[x][i] <= y) ans = true;
    puts(ans ? "Shi" : "Fou");
  }
}