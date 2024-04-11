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
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

inline void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

int dp[2][MAXN];
int r, g;

int sum(int level) {
  return level * (level + 1) / 2;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> r >> g;

  int c = 0;
  dp[c][r] = 1;
  int ans = 0;
  for (int level = 1; ; ++level, c ^= 1) {
    for (int rest_r = 0; rest_r <= r; ++rest_r) {
      if  (!dp[c][rest_r]) {
        continue;
      }

      int rest_g = g - (sum(level - 1) - (r - rest_r));

      // put r
      if  (level <= rest_r) {
        add(dp[c ^ 1][rest_r - level], dp[c][rest_r]);
      }

      // put g
      if  (level <= rest_g) {
        add(dp[c ^ 1][rest_r], dp[c][rest_r]);
      }
    }

    bool was = false;
    for (int rest_r = 0; rest_r <= r; ++rest_r) {
      was |= dp[c ^ 1][rest_r];
    }

    if  (!was) {
      break;
    }

    memset (dp[c], 0, sizeof dp[c]);
    ans = 0;
    for (int rest_r = 0; rest_r <= r; ++rest_r) {
      add(ans, dp[c ^ 1][rest_r]);
    }
  }

  printf("%d\n", ans);
  return 0;
}