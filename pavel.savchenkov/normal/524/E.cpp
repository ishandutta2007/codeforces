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

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 2e5 + 10;

struct SegmTree {
  vi t;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    t.assign(sz * 2, INF);
  }

  void put(int pos, int val) {
    int v = sz + pos;
    t[v] = val;
    v /= 2;
    while (v) {
      t[v] = max(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  int get_max(int l, int r) {
    l += sz;
    r += sz;
    int res = 0;
    while (l <= r) {
      res = max(res, t[l]);
      res = max(res, t[r]);
      l = (l + 1) / 2;
      r = (r - 1) / 2;
    }
    return res;
  }
};

int n, m, k, q;
int x[MAXN];
int y[MAXN];
int x1[MAXN];
int y1[MAXN];
int x2[MAXN];
int y2[MAXN];
bool ok[MAXN];

const int SEG = 0;
const int DOT = 1;

struct Event {
  int type, id;

  bool operator < (const Event& e) const {
    int up = type == SEG ? x1[id] : x[id];
    int up2 = e.type == SEG ? x1[e.id] : x[e.id];

    if  (up != up2) {
      return up > up2;
    }

    if  (type != e.type) {
      return type == DOT;
    }

    return id < e.id;
  }
};

vector<Event> es;

void check_gor() {
  es.clear();
  SegmTree T(m);

  forn(i, k) {
    es.pb({ DOT, i });
  }

  forn(i, q) {
    es.pb({ SEG, i });
  }

  sort(all(es));

  for (auto& e : es) {
    if  (e.type == DOT) {
//      printf("put pos=%d, val=%d\n", y[e.id], x[e.id]);
      T.put(y[e.id], x[e.id]);
    } else {
      int mx = T.get_max(y1[e.id], y2[e.id]);
//      printf("id = %d, mx = %d, [%d, %d]\n", e.id, mx, y1[e.id], y2[e.id]);
      if  (mx <= x2[e.id]) {
        ok[e.id] = true;
      }
    }
  }
}

void check_ver() {
  swap(n, m);
  forn(i, k) {
    swap(x[i], y[i]);
  }
  forn(i, q) {
    swap(x1[i], y1[i]);
    swap(x2[i], y2[i]);
  }

  es.clear();
  SegmTree T(m);

  forn(i, k) {
    es.pb({ DOT, i });
  }

  forn(i, q) {
    es.pb({ SEG, i });
  }

  sort(all(es));

  for (auto e : es) {
    if  (e.type == DOT) {
      T.put(y[e.id], x[e.id]);
    } else {
      int mx = T.get_max(y1[e.id], y2[e.id]);
//      printf("id = %d, mx = %d\n", e.id, mx);
      if  (mx <= x2[e.id]) {
        ok[e.id] = true;
      }
    }
  }
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> m >> k >> q;
  
  forn(i, k) {
    scanf("%d%d", &x[i], &y[i]);
    --x[i];
    --y[i];
  }

  forn(i, q) {
    scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
    --x1[i];
    --y1[i];
    --x2[i];
    --y2[i];
  }

  memset (ok, false, sizeof ok);
  check_gor();
  check_ver();

  forn(i, q) {
    puts(ok[i] ? "YES" : "NO");
  }

  return 0;
}