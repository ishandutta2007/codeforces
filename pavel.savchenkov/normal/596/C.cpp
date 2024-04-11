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

struct cmp {
  bool operator()(const pii& a, const pii& b) const {
    int da = a.snd - a.fst;
    int db = b.snd - b.fst;
    if  (da != db) {
      return da < db;
    }
    return a < b;
  }
};

vi was[MAXN];
set<pii, cmp> cands;
int w[MAXN];
int n;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return false;
  }
  forn(i, MAXN) was[i].clear();
  forn(i, n) {
    int x, y;
    scanf("%d%d", &x, &y);
    was[x].pb(0);
  }
  forn(i, n) scanf("%d", &w[i]);
  return true;
}

bool exist(int x, int y) {
  return sz(was[x]) > y;
}

bool solve() {
  cands.clear();
  cands.insert(mp(0, 0));
  int i = 0;
  vii ans;
  while (!cands.empty()) {
    auto it = cands.upper_bound(mp(-1, w[i] - 1));
    if  (it == cands.end() || it->snd - it->fst != w[i]) {
      return false;
    }
    int x, y;
    tie(x, y) = *it;
    ans.pb(mp(x, y));
    was[x][y] = true;
    cands.erase(it);
    if  (exist(x + 1, y) && !was[x + 1][y]) {
      cands.insert(mp(x + 1, y));
    }
    if  (exist(x, y + 1) && !was[x][y + 1]) {
      cands.insert(mp(x, y + 1));
    }
    ++i;
  }
  puts("YES");
  forn(i, n) {
    printf("%d %d\n", ans[i].fst, ans[i].snd);
  }
  return true;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    if  (!solve()) {
      puts("NO");
    }
  }

  return 0;
}