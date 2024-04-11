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
const int MAXN = 2e3 + 10;
const int INF = 1e9;

char s[MAXN];
int ns;

char p[MAXN];
int np;

int min_x[MAXN][MAXN];
int r[MAXN];
int min_l[MAXN]; // { l | r[l] == min }

int ans[MAXN];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  gets(s);
  ns = strlen(s);

  gets(p);
  np = strlen(p);

  forn(l, ns) {
    r[l] = INF;
    int i = 0;
    for (int j = l; j < ns && i < np; ++j) {
      if  (s[j] == p[i]) {
        ++i;
      }
      if  (i == np) {
        r[l] = j;
        break;
      }
    }
  }

  r[ns] = INF;
  min_l[ns] = ns;
  ford(l, ns) {
    min_l[l] = l;
    if  (r[min_l[l + 1]] < r[min_l[l]]) {
      min_l[l] = min_l[l + 1];
    }
  }

  forn(i, ns + 1) forn(cnt, ns + 1) min_x[i][cnt] = INF;
  min_x[0][0] = 0;

  forn(i, ns + 1) {
    forn(cnt, ns + 1) {
      int& cur = min_x[i][cnt];
      if  (cur >= INF) {
        continue;
      }

      int& nxt1 = min_x[i + 1][cnt];
      nxt1 = min(nxt1, cur);

//      printf("min_x[%d][%d] = %d\n", i, cnt, cur);

      ans[cur] = max(ans[cur], cnt);
      
      int next_l = min_l[i];
      if  (r[next_l] >= INF) {
        continue;
      }

      int& nxt = min_x[r[next_l] + 1][cnt + 1];
      nxt = min(nxt, cur + (r[next_l] - next_l + 1) - np);
    }
  }

  forn(x, ns) {
    ans[x + 1] = max(ans[x + 1], ans[x]);
    while (ns - (x + 1) - ans[x + 1] * np < 0) --ans[x + 1];
  }

  forn(x, ns + 1) {
    printf("%d ", ans[x]);
  }

  return 0;
}