#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const ld EPS = 1e-9;
const int MAXN = 500 + 10;

struct Item {
  int a, l;

  bool read() {
    if  (scanf("%d%d", &a, &l) < 2) {
      return false;
    }
    return true;
  }

  bool operator < (const Item& i) const {
    return a < i.a;
  }
};

int dp[MAXN][MAXN];
Item ls[MAXN];
int n;
vector<int> ps;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return false;
  }
  forn(i, n) {
    assert(ls[i].read());
  }
  return true;
}

pii cover(int start, int not_touch, int l, int r) {
  int i = start;
  for (; i >= 0; --i) {
    if  (i == not_touch) {
      continue;
    }
    if  (ls[i].a < l) {
      break;
    }
    l = min(l, ls[i].a - ls[i].l);
  }
  return mp(i, r - l);
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  assert(read());

  sort(ls, ls + n);

  forn(i, n) {
    ps.pb(ls[i].a - ls[i].l);
    ps.pb(ls[i].a + ls[i].l);
    ps.pb(ls[i].a);
  }

  sort(all(ps));
  ps.resize(unique(all(ps)) - ps.begin());

  forn(i, n) {
    forn(ii, i + 1) {
      int x = ls[ii].a + ls[ii].l;
      if  (x < ls[i].a) {
        continue;
      }
      int posx = lower_bound(all(ps), x) - ps.begin();
      auto cc = cover(i, ii, ls[ii].a, x);
      int len = cc.snd;
      int j = cc.fst;
//      if  (i == 2 && x == 6) {
//        printf("ii=%d, j=%d, len=%d\n", ii, j, len);
//      }
      if  (j <= -1) {
        dp[i][posx] = len;
        continue;  
      }
      forn(posx2, sz(ps)) {
        int x2 = ps[posx2];
        if  (x2 > x) {
          continue;
        }
        if  (x2 < x - len) {
          dp[i][posx] = max(dp[i][posx], len + dp[j][posx2]);
        } else {
          dp[i][posx] = max(dp[i][posx], len + dp[j][posx2] - (x2 - (x - len)));
        }
      }
    }

    int x = ls[i].a;
    int posx = lower_bound(all(ps), x) - ps.begin();
    auto cc = cover(i, i, ls[i].a - ls[i].l, x);
    int len = cc.snd;
    int j = cc.fst;
    if  (j <= -1) {
      dp[i][posx] = len;
      continue;
    }
    forn(posx2, sz(ps)) {
      int x2 = ps[posx2];
      if  (x2 < x - len) {
        dp[i][posx] = max(dp[i][posx], len + dp[j][posx2]);
      } else {
        dp[i][posx] = max(dp[i][posx], len + dp[j][posx2] - (x2 - (x - len)));
      }
    }
  }
/*   
  puts("ps:");
  for (int x : ps) {
    printf("%d ", x);
  }
  puts("");
*/
  int mx = 0;
  forn(i, n) forn(j, sz(ps)) {
//    printf("dp[%d][%d] = %d\n", i, ps[j], dp[i][j]);
    mx = max(mx, dp[i][j]);
  }

  cout << mx << endl;

  return 0;
}