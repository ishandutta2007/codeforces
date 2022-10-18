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
const int MAXN = 1e7 + 10;

bool have[MAXN];
vi a;
int n, k;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d", &n, &k);
  a.resize(n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  sort(all(a));
//  have[0] = true;
  for (int x : a) have[x] = true;

  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);

    int mn = MAXN;
    for (int x1 : a) {
      for (int k1 = 1; x1 * k1 <= x && k1 <= k; ++k1) {
        if  (k1 * x1 == x) {
          mn = min(mn, k1);
          continue;
        }
        for (int k2 = 1; k1 + k2 <= k; ++k2) {
          int rest = x - x1 * k1;
          if  (rest % k2 != 0) {
            continue;
          }
          if  (rest / k2 < MAXN && have[rest / k2]) {
            mn = min(mn, k1 + k2);
          }
        }
      }
    }

    if  (mn == MAXN) mn = -1;
    printf("%d\n", mn);
  }
  
  return 0;
}