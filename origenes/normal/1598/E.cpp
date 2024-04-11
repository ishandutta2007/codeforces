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
ll f[maxn][maxn][2];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> q;
  ll ans = 0;
  FOR(i, 1, n) FOR(j, 1, m) {
    f[i][j][0] = f[i - 1][j][1] + 1;
    f[i][j][1] = f[i][j - 1][0] + 1;
    ans += f[i - 1][j][1] + f[i][j - 1][0] + 1;
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (f[x][y][0] == 0) {
      f[x][y][0] = f[x - 1][y][1] + 1;
      f[x][y][1] = f[x][y - 1][0] + 1;
      ans += f[x - 1][y][1] + f[x][y - 1][0] + 1;
    } else {
      f[x][y][0] = f[x][y][1] = 0;
      ans -= f[x - 1][y][1] + f[x][y - 1][0] + 1;
    }
    while (x <= n && y <= m) {
      if (x + 1 <= n && f[x + 1][y][0] != 0) {
        ans -= f[x + 1][y][0];
        f[x + 1][y][0] = f[x][y][1] + 1;
        ans += f[x + 1][y][0];
      }
      if (y + 1 <= m && f[x][y + 1][1] != 0) {
        ans -= f[x][y + 1][1];
        f[x][y + 1][1] = f[x][y][0] + 1;
        ans += f[x][y + 1][1];
      }
      if (x + 1 <= n && y + 1 <= m && f[x + 1][y + 1][0] != 0) {
        ans -= f[x + 1][y + 1][0] + f[x + 1][y + 1][1];
        f[x + 1][y + 1][0] = f[x][y + 1][1] + 1;
        f[x + 1][y + 1][1] = f[x + 1][y][0] + 1;
        ans += f[x + 1][y + 1][0] + f[x + 1][y + 1][1];
      }
      x++, y++;
    }
    cout << ans << '\n';
  }
}