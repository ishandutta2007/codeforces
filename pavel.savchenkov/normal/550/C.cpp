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
const int MAXN = 100 + 10;

char s[MAXN];
int a[MAXN];
int n;

bool dp[MAXN][8 + 2][2];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  gets(s);
  n = strlen(s);
  forn(i, n) a[i] = s[i] - '0';

  dp[0][0][0] = true;
  forn(i, n) forn(r, 8) forn(alive, 2) {
    if  (!dp[i][r][alive]) {
      continue;
    }
    dp[i + 1][(r * 10 + a[i]) % 8][1] = true;
    dp[i + 1][r][alive] = true;
  }
  
  if  (!dp[n][0][1]) {
    puts("NO");
    return 0;
  }

  vi ans;
  int i = n;
  int r = 0;
  int alive = 1;
  while (i > 0) {
    bool found = false;
    int pi = i - 1;
    forn(pr, 8) forn(palive, 2) {
      if  (!dp[pi][pr][palive] || found) {
        continue;
      }
      if  ((pr * 10 + a[pi]) % 8 == r && alive) {
        found = true;
        ans.pb(a[pi]);
      } else if  (pr == r && palive == alive) {
        found = true;
      }
      if  (found) {
        i = pi;
        r = pr;
        alive = palive;
      }
    }  
  }

  puts("YES");
  ford(i, sz(ans)) {
    printf("%d", ans[i]);
  }
  return 0;
}