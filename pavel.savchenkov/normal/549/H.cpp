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
typedef vector<ld> vld;

#define FILE_NAME ""

const ld EPS = 1e-20;

ld get_min(int a, int b, ld delta) {
  vld f;
  f.pb(a - delta);
  f.pb(a + delta);
  if  (a - delta < EPS && a + delta + EPS > 0) {
    f.pb(0);
  }

  vld s;
  s.pb(b - delta);
  s.pb(b + delta);
  if  (b - delta < EPS && b + delta + EPS > 0) {
    s.pb(0);
  }

  ld mn = f[0] * s[0];
  forn(i, sz(f)) forn(j, sz(s)) {
    mn = fmin(mn, f[i] * s[j]);
  }

  return mn;
}

ld get_max(int a, int b, ld delta) {
  vld f;
  f.pb(a - delta);
  f.pb(a + delta);
  if  (a - delta < EPS && a + delta + EPS > 0) {
    f.pb(0);
  }

  vld s;
  s.pb(b - delta);
  s.pb(b + delta);
  if  (b - delta < EPS && b + delta + EPS > 0) {
    s.pb(0);
  }

  ld mx = f[0] * s[0];
  forn(i, sz(f)) forn(j, sz(s)) {
    mx = fmax(mx, f[i] * s[j]);
  }

  return mx;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  ld L = 0;
  ld R = 2e9;
  forn(it, 5000) {
    ld M = (L + R) * 0.5;

    ld mn1 = get_min(a, d, M);
    ld mx1 = get_max(a, d, M);

    ld mn2 = get_min(b, c, M);
    ld mx2 = get_max(b, c, M);

    ld mn = fmax(mn1, mn2);
    ld mx = fmin(mx1, mx2);

    if  (mn < mx + EPS) {
      R = M;
    } else {
      L = M;
    }
  }

  printf("%.20f\n", (double) R);
  return 0;
}