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
const int MAXN = 1e3 + 10;

int mul(int x, int y, int mod) {
  return x * 1ll * y % mod;
}

int add(int x, int y, int mod) {
  return (x + y) % mod;
}

int mpow(int a, int p, int mod) {
  int res = 1;
  for (; p > 0; p /= 2, a = mul(a, a, mod))
    if  (p & 1)
      res = mul(res, a, mod);

  return res;
}

int dp[MAXN][110][2];
int n, k, mod;

int solve() {
  if  (n == 1) {
    return (9 / k) % mod;
  }

  memset (dp, 0, sizeof dp);
  dp[0][0][1] = 1;
  forn(i, n + 1) {
    forn(rest, k) {
      forn(zero, 2) {                                                                                     
        if  (i > 0 && rest == 0 && !zero) continue;
        if  (!dp[i][rest][zero]) continue;
        forn(d, 10) {
          int nrest = add(rest, mul(mpow(10, i, k), d, k), k);
          dp[i + 1][nrest][zero && d == 0] = add(dp[i + 1][nrest][zero && d == 0], dp[i][rest][zero], mod);
        }
      }  
    }
  }

  int ans = 0;
  for (int len = 1; len < n; ++len) {
    int cnt = dp[len][0][0];
    int coef = mul(9, mpow(10, n - len - 1, mod), mod);
    ans = add(ans, mul(cnt, coef, mod), mod);
  }

  for (int d = 1; d < 10; ++d) {
    int rest = mul(d, mpow(10, n - 1, k), k);
    rest = (-rest + k) % k;
    if  (rest) {
      ans = add(ans, dp[n - 1][rest][0], mod);
    } else {
      ans = add(ans, 1, mod);
    }
  }

  return ans;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> k >> mod; 
  printf("%d\n", solve());

  return 0;
}