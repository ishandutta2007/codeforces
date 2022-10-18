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
const int MAXN = 2e5 + 10;
const int INF = 2e9;

struct SegmTree {
  vi t;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    t.assign(sz * 2, -1);
  }

  void put(int pos, int val) {
    int v = sz + pos;
    t[v] = max(t[v], val);
    v /= 2;
    while (v) {
      t[v] = max(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  int get_max(int l, int r) {
    int res = -1;
    l += sz;
    r += sz;
    while (l <= r) {
      if  (l & 1) {
        res = max(res, t[l]);
      }
      if  (~r & 1) {
        res = max(res, t[r]);
      }
      l = (l + 1) / 2;
      r = (r - 1) / 2;
    }
    return res;
  }
};

int n, m;
int l[MAXN];
int r[MAXN];

int a[MAXN];
int b[MAXN];
int c[MAXN];

vi x;

int get_id(int val) {
  return lower_bound(all(x), val) - x.begin();
}

void read() {
  scanf("%d%d", &n, &m);
  forn(i, n) {
    scanf("%d%d", &l[i], &r[i]);
  }
  forn(i, m) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
  }
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  read();

  forn(i, n) {
    x.pb(l[i]);
    x.pb(r[i]);
  }

  forn(i, m) {
    x.pb(a[i]);
    x.pb(b[i]);
  }

  sort(all(x));
  x.resize(unique(all(x)) - x.begin());

  ll res = 0;
  int who = -1;

  vi max_r(sz(x), -1);
  forn(i, n) {
    int id = get_id(l[i]);
    max_r[id] = max(max_r[id], r[i]);
  }
  forn(i, sz(x)) {
    if  (i) {
      max_r[i] = max(max_r[i - 1], max_r[i]);
    }
  }

  vi min_l(sz(x), INF);
  forn(i, n) {
    int id = get_id(r[i]);
    min_l[id] = min(min_l[id], l[i]);
  }
  ford(i, sz(x) - 1) {
    min_l[i] = min(min_l[i], min_l[i + 1]);
  }

  forn(i, m) {
    int id_l = get_id(a[i]);
    int id_r = get_id(b[i]);

    int R = max_r[id_l];
    R = min(R, b[i]);
    if  (R >= a[i] && (R - a[i]) * 1ll * c[i] > res) {
      res = (R - a[i]) * 1ll * c[i];
//      printf("i=%d, R=%d, cur=%I64d\n", i, R, res);
      who = i;
    }

    int L = min_l[id_r];
    L = max(L, a[i]);
    if  (L <= b[i] && (b[i] - L) * 1ll * c[i] > res) {
      res = (b[i] - L) * 1ll * c[i];
//      printf("i=%d, L=%d, cur=%I64d\n", i, L, res);
      who = i;
    }
  }

  vector<vi> add_l(sz(x));
  forn(i, n) {
    add_l[get_id(r[i])].pb(i);
  }
  vector<vi> who_consider(sz(x));
  forn(i, m) {
    who_consider[get_id(b[i])].pb(i);
  }

  SegmTree T(sz(x)); // -1;
  forn(k, sz(x)) {
    for (int i : add_l[k]) {
      int id_l = get_id(l[i]);
      T.put(id_l, r[i] - l[i]);
    }

    for (int i : who_consider[k]) {
      int id_l = get_id(a[i]);
      int len = T.get_max(id_l, sz(x) - 1);
      if  (len > -1 && len * 1ll * c[i] > res) {
        res = len * 1ll * c[i];
        who = i;
      }
    }
  }                    

  cout << res << endl;

  if  (res == 0) {
    return 0;
  }

  assert(who != -1);
  forn(i, n) {
    int L = max(l[i], a[who]);
    int R = min(r[i], b[who]);

    if  ((R - L) * 1ll * c[who] == res) {
      printf("%d %d\n", i + 1, who + 1);
      return 0;
    }
  }

  assert(false);

  return 0;
}