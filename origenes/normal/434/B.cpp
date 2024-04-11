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

int n, m, q;
int a[maxn][maxn];
int u[maxn][maxn], d[maxn][maxn], l[maxn][maxn], r[maxn][maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> q;
  FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
  FOR(i, 1, n) {
    l[i][1] = a[i][1] ? 1 : 2;
    FOR(j, 2, m) l[i][j] = a[i][j] ? l[i][j - 1] : j + 1;
    r[i][m] = a[i][m] ? m : m - 1;
    ROF(j, m - 1, 1) r[i][j] = a[i][j] ? r[i][j + 1] : j - 1;
  }
  FOR(j, 1, m) {
    u[1][j] = a[1][j] ? 1 : 2;
    FOR(i, 2, n) u[i][j] = a[i][j] ? u[i - 1][j] : i + 1;
    d[n][j] = a[n][j] ? n : n - 1;
    ROF(i, n - 1, 1) d[i][j] = a[i][j] ? d[i + 1][j] : i - 1;
  }
  while (q--) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      a[x][y] = 1 - a[x][y];
      l[x][1] = a[x][1] ? 1 : 2;
      FOR(j, 2, m) l[x][j] = a[x][j] ? l[x][j - 1] : j + 1;
      r[x][m] = a[x][m] ? m : m - 1;
      ROF(j, m - 1, 1) r[x][j] = a[x][j] ? r[x][j + 1] : j - 1;
      u[1][y] = a[1][y] ? 1 : 2;
      FOR(i, 2, n) u[i][y] = a[i][y] ? u[i - 1][y] : i + 1;
      d[n][y] = a[n][y] ? n : n - 1;
      ROF(i, n - 1, 1) d[i][y] = a[i][y] ? d[i + 1][y] : i - 1;
    } else {
      if (!a[x][y]) {
        cout << "0\n";
        continue;
      }
      int ans = x - u[x][y] + 1;
      int lo = y - 1, hi = y + 1, best = u[x][y];
      while (a[x][lo] || a[x][hi]) {
        if (!a[x][lo] || (a[x][hi] && u[x][lo] > u[x][hi])) chkmax(best, u[x][hi++]);
        else chkmax(best, u[x][lo--]);
        chkmax(ans, (x - best + 1) * (hi - lo - 1));
      }
      lo = y - 1, hi = y + 1, best = d[x][y];
      chkmax(ans, d[x][y] - x + 1);
      while (a[x][lo] || a[x][hi]) {
        if (!a[x][lo] || (a[x][hi] && d[x][lo] < d[x][hi])) chkmin(best, d[x][hi++]);
        else chkmin(best, d[x][lo--]);
        chkmax(ans, (best - x + 1) * (hi - lo - 1));
      }
      lo = x - 1, hi = x + 1, best = l[x][y];
      chkmax(ans, y - l[x][y] + 1);
      while (a[lo][y] || a[hi][y]) {
        if (!a[lo][y] || (a[hi][y] && l[lo][y] > l[hi][y])) chkmax(best, l[hi++][y]);
        else chkmax(best, l[lo--][y]);
        chkmax(ans, (y - best + 1) * (hi - lo - 1));
      }
      lo = x - 1, hi = x + 1, best = r[x][y];
      chkmax(ans, r[x][y] - y + 1);
      while (a[lo][y] || a[hi][y]) {
        if (!a[lo][y] || (a[hi][y] && r[lo][y] < r[hi][y])) chkmin(best, r[hi++][y]);
        else chkmin(best, r[lo--][y]);
        chkmax(ans, (best - y + 1) * (hi - lo - 1));
      }
      cout << ans << '\n';
    }
  }
}