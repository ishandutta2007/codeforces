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
const int MAXN = 24;
const int INF = 1e9;

char a[MAXN][MAXN];
int c[MAXN][MAXN];
int n, m;

int ch_mask[MAXN][30]; // col, ch
int ch_sum[MAXN][30];
int ch_mx[MAXN][30];

int dp[(1 << 20) + 10];
 
int dfs(int mask) {
  if  (!mask) {
    return 0;
  }

  int& d = dp[mask];
  if  (d != -1) {
    return d;
  }

  d = INF;

  int i = 0;
  while (!(mask & (1 << i))) ++i;

  assert(mask & (1 << i));

  forn(j, m) {
    int ch = a[i][j] - 'a';
    d = min(d, dfs(mask & (~ch_mask[j][ch])) + ch_sum[j][ch] - ch_mx[j][ch]);
    d = min(d, dfs(mask ^ (1 << i)) + c[i][j]);
  }                                          

  return d;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d%d\n", &n, &m);
  forn(i, n) {
    gets(a[i]);
  }
  forn(i, n) {
    forn(j, m) {
      scanf("%d", &c[i][j]);
    }
  }

/*
  forn(i, n) {
    puts(a[i]);
  }      

  forn(i, n) {
    forn(j, m) {
      printf("%d ", c[i][j]);
    }
    puts("");
  }
*/

  forn(j, m) {
    forn(i, n) {
      int ch = a[i][j] - 'a';
      ch_mask[j][ch] |= 1 << i;
      ch_sum[j][ch] += c[i][j];
      ch_mx[j][ch] = max(ch_mx[j][ch], c[i][j]);
    }
  }

  memset (dp, -1, sizeof dp);
  cout << dfs((1 << n) - 1) << endl;
  return 0;
}