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

vi d;
vi h;
int n, m;

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int ans = 0;

  scanf("%d%d", &n, &m);
  d.resize(m);
  h.resize(m);
  forn(i, m) {
    scanf("%d%d", &d[i], &h[i]);
    ans = max(ans, h[i]);
  }

  forn(i, m - 1) {
    int len = d[i + 1] - d[i] + 1;
    int val = len - 1 + h[i] + h[i + 1];
    if  (val < 0) {
      continue;
    }
    int max_h = val / 2;
    ans = max(ans, max_h);
  }

  ans = max(ans, h[0] + (d[0] - 1));
  ans = max(ans, h.back() + (n - d.back()));

  forn(i, m - 1) {
    if  (abs(h[i + 1] - h[i]) > d[i + 1] - d[i]) {
      puts("IMPOSSIBLE");
      return 0;
    }
  }

  printf("%d\n", ans);
  return 0;
}