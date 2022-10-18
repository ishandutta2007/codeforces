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

int MOD;

void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

int dp[2][MAXN][MAXN];
int n, m, b;
int a[MAXN];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  cin >> n >> m >> b >> MOD;
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  dp[0][0][0] = 1;
  int c = 0;
  forn(i, n) {
    forn(B, b + 1) {
      forn(M, m + 1) {
        if  (!dp[c][B][M]) {
          continue;
        }
        add(dp[c ^ 1][B][M], dp[c][B][M]);
        if  (M + 1 <= m && B + a[i] <= b) {
          add(dp[c][B + a[i]][M + 1], dp[c][B][M]);
        }
      } 
    }

    memset (dp[c], 0, sizeof dp[c]);
    c ^= 1;
  }

  int ans = 0;
  forn(B, b + 1) {
    add(ans, dp[c][B][m]);  
  }

  cout << (ans % MOD) << endl;
  return 0;
}