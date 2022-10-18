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
typedef complex<double> cd;
typedef vector<cd> vcd;

const double EPS = 1e-9;
const ld PI = acos(-1.0);
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
  ((x += y) >= MOD && (x -= MOD));
}

int k;
int dp[MAXN][2];
int sum_dp[MAXN];

void precalc() {
  dp[0][0] = 1;
  for (int i = 0; i < MAXN; ++i) {
    // place 1
    if  (i + k < MAXN) add(dp[i + k][1], dp[i][0]), add(dp[i + k][1], dp[i][1]);
 
    // place 0
    add(dp[i + 1][0], dp[i][0]);
    add(dp[i + 1][0], dp[i][1]);
  }

  for (int i = 0; i < MAXN; ++i) {
    if  (i > 0) add(sum_dp[i], sum_dp[i - 1]);
    forn(j, 2) add(sum_dp[i], dp[i][j]);
  }
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif

  int t;
  scanf("%d%d", &t, &k);
  precalc();

  while (t--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int res = sum_dp[r];
    add(res, -sum_dp[l - 1] + MOD);
    printf("%d\n", res);
  }  

  return 0;
}