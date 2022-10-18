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
#include <fstream>
#include <unordered_map>
#include <unordered_set>

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
const int MAXN = 1e5 + 10;

struct Point {
  ll x, y;

  Point(ll x, ll y) : x(x), y(y) {}

  Point() {}

  void read() {
    int X, Y;
    scanf("%d%d", &X, &Y);
    x = X;
    y = Y;
  }
};

ll operator * (const Point& a, const Point& b) {
  return a.x * b.x + a.y * b.y;
}

ll operator % (const Point& a, const Point& b) {
  return a.x * b.y - a.y * b.x;
}

Point operator - (const Point& a, const Point& b) {
  return Point(a.x - b.x, a.y - b.y);
}

Point p[MAXN];
int n;

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n) {
    p[i].read();
  }

  forn(i, n - 1) {
    p[i] = p[i] - p[n - 1];
  }
  --n;

  int b = 0;
  forn(i, n) {
    if  (p[i] % p[b] != 0) {
      continue;
    } 
    if  (p[i] * p[b] < 0) {
      continue;
    }
    if  (p[i] * p[i] < p[b] * p[b]) {
      b = i;
    }
  }

  int c1 = -1;
  int c2 = -1;
  forn(i, n) {
    if  (p[i] % p[b] == 0) {
      continue;
    }
    if  (p[b] % p[i] < 0) {
      if  (c1 == -1) {
        c1 = i;
      } else if  (p[i] % p[c1] < 0 || (p[i] % p[c1] == 0 && p[i] * p[i] < p[c1] * p[c1])) {
        c1 = i;
      }
    } else {
      if  (c2 == -1) {
        c2 = i;
      } else if  (p[c2] % p[i] < 0 || (p[c2] % p[i] == 0 && p[i] * p[i] < p[c2] * p[c2])) {
        c2 = i;
      }
    }
  }

  printf("%d %d %d\n", n + 1, b + 1, c1 == -1 ? c2 + 1 : c1 + 1);
  return 0;
}