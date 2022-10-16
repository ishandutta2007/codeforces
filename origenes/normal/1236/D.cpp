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

int n, m, k;
set<int> X[maxn], Y[maxn];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  REP(i, k) {
    int x, y;
    scanf("%d%d", &x, &y);
    X[x].emplace(y);
    Y[y].emplace(x);
  }
  int lx = 1, ly = 1, rx = n, ry = m, x = 1, y = 1, dir = 0;
  ll cnt = 1;
  bool fi = true;
  while (true) {
    if (dir == 0) {
      int py = y;
      chkmax(y, ry);
      if (X[x].upper_bound(py) != X[x].end()) chkmin(y, *X[x].upper_bound(py) - 1);
      cnt += y - py;
      if (y == py && !fi) break;
      lx = x + 1;
      fi = false;
    } else if (dir == 1) {
      int px = x;
      chkmax(x, rx);
      if (Y[y].upper_bound(px) != Y[y].end()) chkmin(x, *Y[y].upper_bound(px) - 1);
      cnt += x - px;
      if (x == px) break;
      ry = y - 1;
    } else if (dir == 2) {
      int py = y;
      chkmin(y, ly);
      if (!X[x].empty() && X[x].upper_bound(py) != X[x].begin()) chkmax(y, *(--X[x].upper_bound(py)) + 1);
      cnt += py - y;
      if (y == py) break;
      rx = x - 1;
    } else {
      int px = x;
      chkmin(x, lx);
      if (!Y[y].empty() && Y[y].upper_bound(px) != Y[y].begin()) chkmax(x, *(--Y[y].upper_bound(px)) + 1);
      cnt += px - x;
      if (x == px) break;
      ly = y + 1;
    }
    dir = (dir + 1) % 4;
  }
  puts(cnt == ll(n) * m - k ? "Yes" : "No");
}