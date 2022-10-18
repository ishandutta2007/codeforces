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
const int MOD = 1e9 + 7;

inline void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

inline int mul(int x, int y) {
  return x * 1ll * y % MOD;
} 

struct Matr {
  vvi a;

  Matr() {}

  Matr(int n) {
    a.assign(n, vi(n, 0));
  }

  vi& operator[](int i) {
    return a[i];
  }

  const vi& operator[](int i) const  {
    return a[i];
  }

  Matr& operator *= (const Matr& b) {
    int n = sz(a);
    vvi c(n, vi(n, 0));
    forn(i, n) forn(j, n) {
      forn(k, n) {
        add(c[i][j], mul(a[i][k], b[k][j]));
      }
    }
    a.swap(c);
    return *this;
  }
};

Matr operator * (const Matr& a, const Matr& b) {
  return Matr(a) *= b;
}
 
const int MAXD = 103;

Matr mpow(Matr a, int p) {
  int n = sz(a.a);
  Matr res(n);
  forn(i, n) res[i][i] = 1;
  for (; p > 0; p /= 2, a *= a)
    if  (p & 1) {
      res = a * res;  
    }
  return res;
}

int n, x;
int c[MAXD];

int brut() {
  vi s(x + 1);
  s[0] = 1;
  for (int i = 1; i <= x; ++i) {
    s[i] = 0;
    for (int k = 1; k <= 100; ++k) {
      if  (i - k >= 0) {
        add(s[i], mul(c[k], s[i - k]));
      }
    }
  }

  int ans = 0;
  forn(i, x + 1) add(ans, s[i]);
  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d%d", &n, &x);
  forn(i, n) {
    int d;
    scanf("%d", &d);
    ++c[d];
  }

  n = 101;
  Matr a(n);
  forn(j, n - 1) {
    a[0][j] = c[j + 1];
  }
  forn(j, n - 1) {
    a[n - 1][j] = c[j + 1];  
  }
  a[n - 1][n - 1] = 1;
  for (int i = 1; i + 1 < n; ++i) {
    a[i][i - 1] = 1;
  }

  // x <= 99
  vi s(n);
  s[0] = 1;
  for (int i = 1; i < n; ++i) {
    s[i] = 0;
    for (int k = 1; k <= n; ++k) {
      if  (i - k >= 0) {
        add(s[i], mul(c[k], s[i - k]));
      }
    }
  }

  if  (x <= 99) {
    int ans = 0;
    forn(i, x + 1) add(ans, s[i]);
    printf("%d\n", ans);
    return 0;
  }

  a = mpow(a, x - 99);
  vi vec(n);
  forn(i, n - 1) {
    vec[i] = s[99 - i];
  }
  vec[n - 1] = 0;
  for (int i = 0; i <= 99; ++i) add(vec[n - 1], s[i]);
  
  int ans = 0;
  forn(j, n) {
    add(ans, mul(vec[j], a[n - 1][j]));  
  }

  printf("%d\n", ans);
//  printf("brut = %d\n", brut());
  return 0;
}