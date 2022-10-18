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
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr(T x) {
  return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;
const int MAXN = 300 + 10;
const int INF = 1e9;

int a[MAXN][MAXN];
int n;

int solve() {
  vvi dp(n, vi(n, -INF));
  dp[0][0] = a[0][0];

  forn(j, n) {
    forn(i1, n) { 
      for (int i2 = i1; i2 < n; ++i2) { 
        if  (i1 + 1 < n && i1 + 1 <= i2) {
          dp[i1 + 1][i2] = max(dp[i1 + 1][i2], dp[i1][i2] + a[i1 + 1][j] * (i1 + 1 < i2));
        }
      }
    }

    forn(i1, n) { 
      for (int i2 = i1; i2 < n; ++i2) { 
        if  (i2 + 1 < n) {
          dp[i1][i2 + 1] = max(dp[i1][i2 + 1], dp[i1][i2] + a[i2 + 1][j]);
        }
      }
    }

    vvi D(n, vi(n, -INF));
    forn(i1, n) D[i1][i1] = dp[i1][i1];

    forn(i1, n) {
      for (int i2 = i1; i2 < n; ++i2) {
        if  (i1 + 1 <= i2) {
          D[i1 + 1][i2] = max(D[i1 + 1][i2], D[i1][i2]);
        }
        if  (i2 + 1 < n) {
          D[i1][i2 + 1] = max(D[i1][i2 + 1], D[i1][i2] + a[i2 + 1][j]);
        }
      }
    }

    forn(i1, n) {
      for (int i2 = i1; i2 < n; ++i2) {
        dp[i1][i2] = max(dp[i1][i2], D[i1][i2]);
      }
    }
/*
    printf("j = %d\n", j);
    forn(i1, n) {
      forn(i2, n) {
        if  (i1 <= i2) {
          printf("dp[%d][%d] = %d\n", i1, i2, dp[i1][i2]);
        }
      }              
    }
*/
    if  (j == n - 1) {
      break;
    }

    vvi ndp(n, vi(n, -INF));

    forn(i1, n) {
      for (int i2 = i1; i2 < n; ++i2) { 
        ndp[i1][i2] = max(ndp[i1][i2], dp[i1][i2] + a[i1][j + 1] + a[i2][j + 1] * (i1 != i2));
      }
    }    
        
    dp.swap(ndp);
  }

  return dp[n - 1][n - 1];
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d\n", &n);
  forn(i, n) {
    forn(j, n) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("%d\n", solve());
  return 0;
}