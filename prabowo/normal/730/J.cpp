#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl
#define SIZE(a) ((int) a.size())

#define PI acos(-1)

#define maxn 1000111

typedef pair<int, int> pii;

int n, a[111], b[111];
pii f[111][11111];

int main() {
  cin >> n;
  int s = 0;
  FOR (i, 1, n) {
    cin >> a[i];
    s += a[i];
  }

  FOR (i, 1, n) cin >> b[i];

  f[0][0] = make_pair(0, 0);
  FOR (sumb, 1, 10000) 
    f[0][sumb] = make_pair(n + 1, 0);

  FOR (i, 1, n)
    FOR (sumb, 0, 10000) {
      f[i][sumb] = f[i - 1][sumb];
      if (sumb >= b[i]) {
        pii last = f[i - 1][sumb - b[i]];
        f[i][sumb] = min(f[i][sumb], make_pair(last.first + 1, last.second - a[i]));
      }
    }

  pii res = make_pair(n + 1, 0);
  FORD(sumb, 10000, 0)
    if (f[n][sumb].first <= n && sumb >= s) res = min(res, f[n][sumb]);

  cout << res.first << " " << s + res.second;
  return 0;
}