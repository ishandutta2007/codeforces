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

const double EPS = 1e-9;
const int MAXN = 1e3 + 10;

bool g[MAXN][MAXN];
vi c;
int m, k;

int coord(int x) {
  return lower_bound(all(c), x) - c.begin();
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d", &m, &k);
  vii es;
  forn(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    es.pb(mp(a, b));
    c.pb(a);
    c.pb(b);
  }

  sort(all(c));
  c.resize(unique(all(c)) - c.begin());

  forn(i, m) {
    int a, b;
    tie(a, b) = es[i];

    a = coord(a);
    b = coord(b);

//    printf("%d %d\n", a, b);
    g[a][b] = g[b][a] = true;
  }

  for (int x : c) {
    printf("%d: ", x);
    vi ans;
    int cx = coord(x);
    forn(cy, sz(c)) {
      if  (g[cx][cy]) {
        continue;
      }
      
      int all = 0;
      int good = 0;
      forn(cz, sz(c)) {
        if  (!g[cx][cz]) {
          continue;
        }
        ++all;
        if  (g[cz][cy]) {
          ++good;
        }
      }

      if  (cy != cx && good * 100 >= k * all) {
        ans.pb(c[cy]);
      }
    } 

    printf("%d ", sz(ans));
    for (int y : ans) {
      printf("%d ", y);
    }
    puts("");
  }

  return 0;
}