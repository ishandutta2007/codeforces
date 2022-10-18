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

typedef unsigned long long ll;
//typedef unsigned long long ull;
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

ll n, k;
int l, m;

int mul(int x, int y) {
  return x * 1ll * y % m;
}

void add(int& x, int y) {
  ((x += y) >= m) && (x -= m);
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

  const vi& operator[](int i) const {
    return a[i];
  }

  size_t size() const {
    return a.size();
  }

  Matr& operator *= (const Matr& b) {
    int n = sz(b);
    vvi c(n, vi(n));
    forn(i, n) forn(j, n) {
      c[i][j] = 0;
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

Matr mpow(Matr a, ll p) {
  int n = sz(a);
  Matr res(n);
  forn(i, n) res[i][i] = 1;
  for (; p > 0; p /= 2, a *= a)
    if  (p & 1)
      res = a * res;
   return res;
}

int mpow(int a, ll p) {
  int res = 1;
  for (; p > 0; p /= 2, a = mul(a, a))
    if  (p & 1)
      res = mul(res, a);
  return res % m;
}

int dp(ll i) {
  if  (i == 0) {
    return 1;
  }
  if  (i == 1) {
    return 2; 
  }
  Matr a(2);
  a[0][0] = a[0][1] = 1;
  a[1][0] = 1;
  a = mpow(a, i - 1);

  int ans = 0;
  add(ans, mul(a[0][0], 2));
  add(ans, mul(a[0][1], 1));
  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  cin >> n >> k >> l >> m;

  if  (l < 64 && k >= (1ull << l)) {
    printf("%d\n", 0);
    return 0;
  }

  int ans = 1;
  forn(i, l) {
    int cur = 0;
    if  ((k >> i) & 1) {
      cur = mpow(2, n);
      add(cur, -dp(n) + m);
    } else {
      cur = dp(n);
    }
    ans = mul(ans, cur);
  }

  cout << ans % m << endl;

  return 0;
}