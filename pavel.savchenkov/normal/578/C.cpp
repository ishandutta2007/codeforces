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
const int MAXN = 2e5 + 10;

// a * x + b
struct Line {
  ll a, b;

  Line(ll a, ll b) : a(a), b(b) {}

  Line() {}

  void print() const {
    cout << a << " * x + " << b << endl;
  }

  ld inter(const Line& l) const {
    // a * x + b == l.a * x + l.b
    // x * (a - l.a) + b - l.b == 0
    // x == (l.b - b) / (a - l.a)
    return ld(l.b - b) / (a - l.a);
  }

  ld eval(ld x) const {
    return a * x + b;
  }
};

int a[MAXN];
ll s[MAXN];
int n;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return false;
  }
  forn(i, n) {
    scanf("%d", &a[i]);
  }
  return true;
}

void precalc() {
  s[0] = a[0];
  for (int i = 1; i < n; ++i) {
    s[i] = a[i] + s[i - 1];
  }
}

vector<Line> calc_max() {
  vector<Line> lines;
  lines.pb(Line(0, 0)); // fuck
  forn(i, n) {
    Line cur(i + 1, s[i]);
    while (sz(lines) > 1) {
      auto l1 = lines.back();
      auto l2 = lines[sz(lines) - 2];
      if  (cur.inter(l1) + EPS < l1.inter(l2)) {
        /*
        printf("pop_back()\n");
        lines.back().print();
        printf("%.10f\n", (double) cur.inter(l1));
        printf("%.10f\n", (double) l2.inter(l1));
        */
        lines.pop_back();  
      } else {
        break;
      }
    }
    lines.pb(cur);
  }
  return lines;
}

vector<Line> calc_min() {
  vector<Line> lines;
  for (int i = n - 1; i >= -1; --i) {
    Line cur = i >= 0 ? Line(i + 1, s[i]) : Line(0, 0);
    while (sz(lines) > 1) {
      auto l1 = lines.back();
      auto l2 = lines[sz(lines) - 2];
      if  (cur.inter(l1) + EPS < l1.inter(l2)) {
        lines.pop_back();
      } else {
        break;
      }
    }
    lines.pb(cur);
  }
  return lines;
}

ld solve() {
  if  (n == 1) {
    return 0;
  }

  precalc();

  vector<Line> mx = calc_max();
  vector<Line> mn = calc_min();

  /*
  puts("mx:");
  for (auto p : mx) p.print();

  puts("mn:");
  for (auto p : mn) p.print();
  */
  /*
  forn(i, sz(mx)) forn(j, sz(mx)) {
    if  (i >= j) {
      continue;
    }
    printf("%.10f\n", (double) mx[i].inter(mx[j]));
  }

  forn(i, sz(mn)) forn(j, sz(mn)) {
    if  (i >= j) {
      continue;
    }
    printf("%d, %d, -> %.10f\n", i, j, (double) mn[i].inter(mn[j]));
  }
  */

  ld ans = 0;
  forn(i, n) ans += fabs(a[i]);
  int i = 0;
  int j = 0;
  while (i + 1 < sz(mx) || j + 1 < sz(mn)) {
    ld x = 0;
    if  (i + 1 == sz(mx)) {
      x = mn[j].inter(mn[j + 1]);
      ++j;
    } else if  (j + 1 == sz(mn)) {
      x = mx[i].inter(mx[i + 1]);
      ++i;
    } else if  (mn[j].inter(mn[j + 1]) < mx[i].inter(mx[i + 1])) {
      x = mn[j].inter(mn[j + 1]);
      ++j;
    } else {
      x = mx[i].inter(mx[i + 1]);
      ++i;
    }

    auto v1 = mn[j].eval(x);
    auto v2 = mx[i].eval(x);
    ld cur_ans = max(fabs(v1 - v2), max(fabs(v1), fabs(v2)));
//    printf("x = %.10f, cur = %.10f, v1=%.5f, v2=%.5f\n", (double) x, (double) cur_ans, (double) v1, (double) v2);
    if  (cur_ans + EPS < ans) {
      ans = cur_ans;
    }
  }

  return ans;                  
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    printf("%.15f\n", (double) solve());
  }

  return 0;
}