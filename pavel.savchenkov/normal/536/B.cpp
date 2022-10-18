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

const ld EPS = 1e-9;
const int MAXN = 1e6 + 10;

char p[MAXN];
int n, m;

int sum[MAXN];

int z[MAXN];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d\n", &n, &m);
  gets(p);

  int lp = strlen(p);

  z[0] = 0;
  int l = 0;
  int r = 0;
  for (int i = 1; i < lp; ++i) {
    if  (i <= r) {
      z[i] = min(z[i - l], r - i + 1);
    } 

    while (i + z[i] < lp && p[z[i]] == p[i + z[i]]) ++z[i];

    if  (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  vii segs;
  forn(i, m) {
    int x;
    scanf("%d", &x);
    --x;

    ++sum[x];
    --sum[x + lp];

    segs.pb(mp(x, x + lp - 1));
  }


  const int MOD = 1e9 + 7;
  int res = 1;
  int s = 0;
  forn(i, n) {
    s += sum[i];

    if  (s == 0) {
      res = (res * 1ll * 26) % MOD;
    }
  }

  for (int i = 1; i < sz(segs); ++i) {
    int l, r;
    tie(l, r) = segs[i - 1];

    int l1, r1;
    tie(l1, r1) = segs[i];

    if  (z[l1 - l] < r - l1 + 1) {
      res = 0;
    } 
  }

  printf("%d\n", res);

  return 0;
}