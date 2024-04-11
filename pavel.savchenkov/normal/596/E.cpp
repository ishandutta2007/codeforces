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
const int MAXN = 200 + 10;
const int MAXLEN = 1e6 + 10;

int c[MAXN][MAXN];
int a[10];
int b[10];
int n, m, q;
int was[MAXN][MAXN];

bool read() {
  if  (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  forn(i, n) forn(j, m) {
    scanf("%1d", &c[i][j]);
  }
  forn(d, 10) {
    scanf("%d%d", &a[d], &b[d]);
  //  swap(a[d], b[d]);
  }
  return true;
}

char s[MAXLEN];
int suff_mask[MAXLEN];
int len;

void read_s() {
  string ss;
  getline(cin, ss);
  forn(i, sz(ss)) s[i] = ss[i];
  s[sz(ss)] = 0;
}

struct Path {
  vi digs;
  int mask;

  Path() {
    mask = 0;
  }

  bool check() {
    int ptr = 0;
    forn(i, sz(digs)) {
      if  (ptr < len && digs[i] == s[ptr] - '0') {
        ++ptr;
      }
    } 
    //assert(ptr == 0);
    /*
    if  (ptr == len) {
      return true;
    }
    */
    return (suff_mask[ptr] & mask) == suff_mask[ptr];
  }
};

vector<Path> paths;

bool on(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j, vii& top) {
  assert(!was[i][j]);
  was[i][j] = true;
  int d = c[i][j];
  int ni = i + a[d];
  int nj = j + b[d];
  if  (on(ni, nj) && !was[ni][nj]) {
    dfs(ni, nj, top);  
  }
  top.pb(mp(i, j));
}

Path build_path(int i, int j) {
  int w = i * m + j + 123;
  vii elems;
  elems.pb(mp(i, j));
  was[i][j] = w;
  while (1) {
    tie(i, j) = elems.back();
    int d = c[i][j];
    int ni = i + a[d];
    int nj = j + b[d];
    if  (!on(ni, nj)) {
      ni = i;
      nj = j;
    }
    if  (was[ni][nj] == w) {
      Path path;
      int e = -1;
      for (int k = sz(elems) - 1; k >= 0; --k) {
        int ii, jj;
        tie(ii, jj) = elems[k];
        path.mask |= 1 << c[ii][jj];
        if  (elems[k] == mp(ni, nj)) {
          e = k - 1;
          break;
        } 
      }
      for (int k = 0; k <= e; ++k) {
        int ii, jj;
        tie(ii, jj) = elems[k];
        path.digs.pb(c[ii][jj]);
      }
      return path;
    }
    was[ni][nj] = w;
    elems.pb(mp(ni, nj)); 
  }
  assert(false);
  return Path();
}

void precalc() {
  paths.clear();
  memset (was, false, sizeof was);
  vii top;
  forn(i, n) forn(j, m) {
    if  (!was[i][j]) {
      dfs(i, j, top);
    }
  } 

  reverse(all(top));
  memset (was, false, sizeof was);
  for (auto p : top) {
    int i, j;
    tie(i, j) = p;
    if  (!was[i][j]) {
      paths.pb(build_path(i, j));
    }
  }
}
 
bool solve() {
  len = strlen(s);
//  puts(s);
  suff_mask[len] = 0;
  ford(i, len) {
    int d = s[i] - '0';
    suff_mask[i] = (1 << d) | suff_mask[i + 1];
  }

  forn(i, sz(paths)) {
    if  (paths[i].check()) {
      return true;
    }
  } 
  return false;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    /*
    forn(i, n) {
      forn(j, m) {
        printf("%d ", c[i][j]);
      }
      puts("");
    }
    puts("");
    */

    precalc();
    //return 0;

    getchar();
    //scanf("\n");
    forn(i, q) {
      read_s();
      puts(solve() ? "YES" : "NO");
    }

    break;
  }

  return 0;
}