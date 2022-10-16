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

const int maxn = 55;

bool ask(int x1, int y1, int x2, int y2) {
  cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
  bool ret;
  cin >> ret;
  return ret;
}

int n;
bool a[maxn][maxn];

int main() {
  cin >> n;
  a[1][1] = true;
  FOR(i, 1, n) {
    if (i & 1) {
      if (i != 1) a[i][1] = !(a[i - 2][1] ^ ask(i - 2, 1, i, 1));
      for (int j = 3; j <= n; j += 2) {
        if (i == n && j == n) continue;
        a[i][j] = !(a[i][j - 2] ^ ask(i, j - 2, i, j));
      }
    } else {
      for (int j = 2; j <= n; j += 2)
        a[i][j] = !(a[i - 1][j - 1] ^ ask(i - 1, j - 1, i, j));
    }
  }
  a[1][2] = false;
  for (int i = 4; i <= n; i += 2) a[1][i] = !(a[1][i - 2] ^ ask(1, i - 2, 1, i));
  for (int i = 3; i <= n; i += 2) a[2][i] = !(a[1][i - 1] ^ ask(1, i - 1, 2, i));
  a[2][1] = !(a[2][3] ^ ask(2, 1, 2, 3));
  FOR(i, 3, n) {
    if (i & 1) {
      for (int j = 2; j <= n; j += 2) a[i][j] = !(a[i - 2][j] ^ ask(i - 2, j, i, j));
    } else {
      for (int j = 1; j <= n; j += 2) a[i][j] = !(a[i - 2][j] ^ ask(i - 2, j, i, j));
    }
  }
  vector<bool> consider;
  FOR(i, 1, n) consider.eb(a[i][1]);
  FOR(i, 2, n) consider.eb(a[n][i]);
  int xl, yl, xr, yr;
  FOR(i, 3, 2 * n - 2) if (!(consider[i] ^ consider[i - 1] ^ consider[i - 2] ^ consider[i - 3])) {
    xl = i - 3 < n ? i - 2 : n;
    yl = i - 3 < n ? 1 : i - n - 1;
    xr = i < n ? i + 1 : n;
    yr = i < n ? 1 : i - n + 2;
    break;
  }
  bool flip = a[xl][yl] ^ a[xr][yr] ^ !ask(xl, yl, xr, yr);
  cout << "!" << endl;
  FOR(i, 1, n) {
    FOR(j, 1, n) cout << ((i + j) & 1 ? a[i][j] ^ flip : a[i][j]);
    cout << endl;
  }
}