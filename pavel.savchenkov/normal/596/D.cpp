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
#include <fstream>
#include <unordered_map>
#include <unordered_set>

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
const int MAXN = 2e3 + 10;

ld dp[MAXN][MAXN][2][2];
int n, h;
int x[MAXN];
int go_left[MAXN];
int go_right[MAXN];
ld p;

bool read() {
  double _p;
  if  (scanf("%d%d%lf", &n, &h, &_p) < 2) {
    return false;
  }
  p = _p;
  forn(i, n) {
    scanf("%d", &x[i]);
  }
  return true;
}

void precalc() {
  sort(x, x + n);

  go_left[0] = 0;
  for (int i = 1; i < n; ++i) {
    if  (x[i] - x[i - 1] < h) {
      go_left[i] = go_left[i - 1];
    } else {
      go_left[i] = i;
    }
  }

  go_right[n - 1] = n - 1;
  ford(i, n - 1) {
    if  (x[i + 1] - x[i] < h) {
      go_right[i] = go_right[i + 1];
    } else {
      go_right[i] = i;
    }
  }
}

ld solve() {
  for (int len = 1; len <= n; ++len) {
    forn(l, n) {
      int r = l + len - 1;
      if  (r >= n) {
        break;
      }
      forn(wasl, 2) forn(wasr, 2) {
        int lx = l > 0 ? (wasl ? x[l - 1] + h : x[l - 1]) : - (int) 5e8;
        int rx = r < n - 1 ? (wasr ? x[r + 1] - h : x[r + 1]) : + (int) 5e8;
        
        ld right = (1 - p) * ((min(rx, x[r] + h) - x[r]) + (l <= r - 1 ? dp[l][r - 1][wasl][0] : 0));
        int rr = max(l, go_left[r]);
        if  (rr == l) {
          right += p * (x[r] - x[l] + (x[l] - max(lx, x[l] - h)));
        } else {
          right += p * (x[r] - x[rr] + h + dp[l][rr - 1][wasl][1]);
        }

        ld left = p * (x[l] - max(lx, x[l] - h) + (l + 1 <= r ? dp[l + 1][r][0][wasr] : 0));
        int ll = min(r, go_right[l]);
        if  (ll == r) {
          left += (1 - p) * (x[r] - x[l] + min(rx, x[r] + h) - x[r]);
        } else {
          left += (1 - p) * (x[ll] - x[l] + h + dp[ll + 1][r][1][wasr]);
        }

        dp[l][r][wasl][wasr] = (left + right) * 0.5;
      }
    }
  }

  return dp[0][n - 1][0][0];
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    precalc();
    printf("%.15f\n", (double) solve());
  }

  return 0;
}