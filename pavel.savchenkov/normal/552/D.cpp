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
#include <unordered_map>

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

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

struct Point {
  int x, y;

  Point() {}

  Point(int x, int y) : x(x), y(y) {}

  bool read() {
    if  (scanf("%d%d", &x, &y) < 2) {
      return false;
    }
    return true;
  }

  bool operator < (const Point& p) const {
    if  (x != p.x) {
      return x < p.x;
    }
    return y < p.y;
  }

  bool operator == (const Point& p) const {
    return x == p.x && y == p.y;
  }

  Point operator - (const Point& p) const {
    return Point{ x - p.x, y - p.y };
  }

  void norm() {
    if  (x == 0 && y == 0) {
      return;
    } 
    int g = gcd(abs(x), abs(y));
    x /= g;
    y /= g; 
    if  (x == 0) y = 1;
    if  (y == 0) x = 1;
    if  ((x == 0 && y < 0) || x < 0) {
      x = -x;
      y = -y;
    }
  }

  void print() const {
    cout << x << " " << y << endl;
  }
};

struct HHH {
  uint operator()(const Point& p) const {
    return p.x * 1000000007 + p.y;
  }
};

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  vector<Point> points(n);
  forn(i, n) assert(points[i].read());

  ll ans = 0;
  forn(i, n) {
    unordered_map<Point, int, HHH> cnt;
    forn(j, n) {
      if  (i != j) {
        auto p = points[j] - points[i];
        p.norm();
        ++cnt[p];
      }
    } 

    for (auto& it : cnt) {
      ans += it.snd * 1ll * (it.snd - 1) / 2;
//      it.fst.print();
    }
//    puts("");
  }
                                            
  cout << (n * 1ll * (n - 1) * 1ll * (n - 2) / 6) - ans / 3 << endl;
  return 0;
}