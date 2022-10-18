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
const int MAXN = 100 + 5;

ld dp[MAXN][MAXN][MAXN];

int lose(int c1, int c2) {
  assert(c1 != c2);
  if  ((c1 + 1) % 3 == c2) {
    return c2;
  }
  return c1;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  vi cnt(3);    
  forn(n1, MAXN) forn(n2, MAXN) forn(n3, MAXN) {
    if  (n1 == 0) {
      dp[n1][n2][n3] = 0.0;
      continue;
    }

    if  (n2 == 0 && n3 == 0) {
      dp[n1][n2][n3] = 1.0;
      continue;
    }

    
    dp[n1][n2][n3] = 0;
    cnt[0] = n1;
    cnt[1] = n2;
    cnt[2] = n3;
    int all = n1 * n2 + n1 * n3 + n2 * n3;
    forn(w1, 3) forn(w2, 3) {
      if  (!cnt[w1] || !cnt[w2] || w1 >= w2) {
        continue;
      } 
      ld prob = (ld) (cnt[w1] * cnt[w2]) / all;

      --cnt[lose(w1, w2)];
      dp[n1][n2][n3] += prob * dp[cnt[0]][cnt[1]][cnt[2]];
      ++cnt[lose(w1, w2)];
    }
  }

  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  printf("%.15f %.15f %.15f\n", (double) dp[n1][n2][n3], (double) dp[n2][n3][n1], (double) dp[n3][n1][n2]);
  return 0;
}