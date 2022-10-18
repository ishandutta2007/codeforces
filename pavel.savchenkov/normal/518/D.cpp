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
typedef long double ld;

const double EPS = 1e-9;
const int MAXN = 2e3 + 10;

int n, t;
ld dp[MAXN][MAXN];
ld p;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> p >> t;

  forn(i, MAXN) forn(j, MAXN) dp[i][j] = 0.0;

  dp[0][n] = 1.0;
  for (int was = 0; was < t; ++was) {
    for (int stand = 1; stand <= n; ++stand) {
      dp[was + 1][stand - 1] += dp[was][stand] * p;
      dp[was + 1][stand] += dp[was][stand] * (1.0 - p);
    }
    dp[was + 1][0] += dp[was][0];
  }

  ld res = 0.0;
  for (int stand = 1; stand <= n; ++stand) {
    res += dp[t][n - stand] * stand;
  }

  printf("%.15f\n", (double) res);
  return 0;
}