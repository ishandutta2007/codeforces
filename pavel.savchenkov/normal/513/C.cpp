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
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr(T x) {
  return x * x;
}

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

const double EPS = 1e-9;
const int MAXC = 1e4 + 10;

int n;
int l[10];
int r[10];

ld prob_eq(int id, int x) {
  if  (x < l[id] || r[id] < x) {
    return 0.0;
  }
  return 1.0 / (r[id] - l[id] + 1);
}

ld prob_less(int id, int x) {
  if  (r[id] < x) {
    return 1.0;
  }
  if  (x <= l[id]) {
    return 0.0;
  }
  return (ld) (x - l[id]) / (r[id] - l[id] + 1);
}

ld prob_gr(int id, int x) {
  if  (r[id] <= x) {
    return 0.0;
  }
  if  (x < l[id]) {
    return 1.0;
  }
  return (ld) (r[id] - x) / (r[id] - l[id] + 1);
}      

bool bit(int mask, int i) {
  return (mask >> i) & 1;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n;
  forn(i, n) {
    cin >> l[i] >> r[i];
  }

  ld ans = 0;
  for (int x = 1; x < MAXC; ++x) {
    forn(who_gr, n) {
      ld P = prob_gr(who_gr, x);

      ld prob1 = 1.0;
      forn(i, n) {
        if  (i != who_gr) {
          prob1 *= prob_less(i, x + 1);
        }
      }

      ld prob2 = 1.0;
      forn(i, n) {
        if  (i != who_gr) {
          prob2 *= prob_less(i, x);
        }
      }

      P *= prob1 - prob2;

      ans += P * x;
    }

    forn(mask, 1 << n) {
      ld P = 1.0;

      if  (__builtin_popcount(mask) <= 1) {
        continue;
      }

      forn(i, n) {
        if  (bit(mask, i)) {
          P *= prob_eq(i, x);
        } else {
          P *= prob_less(i, x);
        }
      }

      ans += P * x;
    }
  }

  printf("%.15f\n", (double) ans);
  return 0;
}