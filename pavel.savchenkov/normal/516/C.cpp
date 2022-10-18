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

#define merge jslkdjflkdslkf

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

const double EPS = 1e-9;
const ll INF = (ll) 1e17;

struct Node {
  ll sum_d;
  ll pref;
  ll suff;
  ll ans;
  int l, r;

  Node() {
//    l = r = 0;
//    sum_d = pref = suff = ans = -INF;
  }
};

struct SegmTree {
  vector<Node> t;
  int sz;
  vll d;
  vll h;

  Node merge(Node a, Node b) {
    Node c;
    c.l = a.l;
    c.r = b.r;
    ll D = 0 <= a.r && a.r < sz(d) ? d[a.r] : -INF;
    c.pref = max(a.pref, a.sum_d + D + b.pref);
    c.suff = max(b.suff, a.suff + D + b.sum_d);
    c.sum_d = a.sum_d + D + b.sum_d;
    c.ans = max(b.ans, max(a.ans, a.suff + D + b.pref));
    return c;
  }

  SegmTree() {}

  SegmTree(vll d_, vll h_) {
    d = d_;
    h = h_;

    sz = 1;
    while (sz < sz(d)) sz *= 2;

    while (sz(d) < sz) d.pb(-INF);
    while (sz(h) < sz) h.pb(-INF);

    t.resize(2 * sz);

    init(1, 0, sz - 1);
  }

  void init(int v, int tl, int tr) {
    if  (tl == tr) {
      t[v].pref = 2ll * h[tl];
      t[v].suff = 2ll * h[tl];
      t[v].ans = -INF;
      t[v].l = tl;
      t[v].r = tl;
      t[v].sum_d = 0;
      return;
    }

    int tm = (tl + tr) / 2;
    init(v * 2, tl, tm);
    init(v * 2 + 1, tm + 1, tr);

    t[v] = merge(t[v * 2], t[v * 2 + 1]);
  }

  Node get(int v, int tl, int tr, int l, int r) {
    l = max(l, tl);
    r = min(r, tr);

    if  (tl == l && tr == r) {
      return t[v];
    }

    if  (2 * v >= sz(t)) {
      while (1) {}
    }

    int tm = (tl + tr) / 2;
    
    if  (r <= tm) {
      return get(v * 2, tl, tm, l, r);
    }

    if  (tm < l) {
      return get(v * 2 + 1, tm + 1, tr, l, r);
    }

    return merge(get(v * 2, tl, tm, l, tm), get(v * 2 + 1, tm + 1, tr, tm + 1, r));
  }

  ll get(int l, int r) {
    if  (!(0 <= l && l <= r && r < sz)) {
      return -INF;
    }
    return get(1, 0, sz - 1, l, r).ans;
  }
};

SegmTree T;
vll h;
vll d;
int n, m;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  
  d.resize(2 * n);
  forn(i, n) {
    scanf("%I64d", &d[i]);
    d[i + n] = d[i];
  }

  h.resize(2 * n);
  forn(i, n) {
    scanf("%I64d", &h[i]);
    h[i + n] = h[i];
  }

  T = SegmTree(d, h);

  forn(i, m) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    --r;

    ll ans = -INF;

    if  (l <= r) {
      int l1 = l;
      int r1 = r;
      int l2 = l1 + n;
      int r2 = r1 + n;

      ans = max(T.get(0, l1 - 1), T.get(r1 + 1, l2 - 1));
      ans = max(ans, T.get(r2 + 1, 2 * n - 1));
    } else {
//      assert(r + 2 <= l - 1);
      ans = T.get(r + 1, l - 1);
    }

    printf("%I64d\n", ans);
  }

  return 0;
}