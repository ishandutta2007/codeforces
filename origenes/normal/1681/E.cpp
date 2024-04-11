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

const int maxn = 112345;

int d[maxn][2];

struct Matrix {
  ll a[2][2];
  Matrix operator*(const Matrix &rhs) const {
    Matrix ret;
    REP(i, 2) REP(j, 2) ret.a[i][j] = min(a[i][0] + rhs.a[0][j], a[i][1] + rhs.a[1][j]);
    return ret;
  }
} f[maxn][17];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  FOR(i, 1, n - 1) {
    int x, y;
    cin >> x >> y; d[i][0] = y;
    cin >> x >> y; d[i][1] = i * 2 - x;
  }
  FOR(i, 1, n) REP(x, 2) REP(y, 2) f[i][0].a[x][y] = abs(d[i - 1][x] + 2 * x - d[i][y]) + 1;
  FOR(j, 1, 16) FOR(i, 1 << j, n) f[i][j] = f[i - (1 << j - 1)][j - 1] * f[i][j - 1];
  int m; cin >> m;
  while (m--) {
    int x1, y1, x2, y2;
    auto read = [](int &x, int &y) {
      int tx, ty; cin >> tx >> ty;
      if (tx > ty) {
        x = tx;
        y = ty;
      } else {
        x = ty;
        y = 2 * ty - tx;
      }
    };
    read(x1, y1); read(x2, y2);
    if (x1 > x2) {
      swap(x1, x2);
      swap(y1, y2);
    }
    if (x1 == x2) {
      cout << abs(y1 - y2) << '\n';
      continue;
    }
    x2--;
    Matrix ans;
    ans.a[0][0] = ans.a[0][1] = abs(d[x2][0] - y2) + 1;
    ans.a[1][0] = ans.a[1][1] = abs(d[x2][1] - y2 + 2) + 1;
    REP(i, 17) if ((x2 - x1) & (1 << i)) {
      ans = f[x2][i] * ans;
      x2 -= 1 << i;
    }
    cout << min(abs(d[x1][0] - y1) + ans.a[0][0], abs(d[x1][1] - y1) + ans.a[1][0]) << '\n';
  }
}