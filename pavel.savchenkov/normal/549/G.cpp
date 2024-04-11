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

struct SegmTree {
  vii t;
  int sz;
  vi add;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    t.assign(sz * 2, mp(0, 0));
    add.assign(sz * 2, 0);

    for (int v = sz; v < 2 * sz; ++v) {
      t[v].snd = v - sz;
      t[v].fst = 0;
    }
  }

  void push(int v) {
    if  (add[v]) {
      t[v * 2].fst += add[v];
      add[v * 2] += add[v];
      t[v * 2 + 1].fst += add[v];
      add[v * 2 + 1] += add[v];
      add[v] = 0;
    }
  }

  void go_add(int v, int tl, int tr, int l, int r, int val) {
    l = max(l, tl);
    r = min(r, tr);

    if  (l > r) {
      return;
    }

    if  (l == tl && r == tr) {
      t[v].fst += val;
      add[v] += val;
      return;  
    }

    push(v);

    int tm = (tl + tr) / 2;
    go_add(v * 2, tl, tm, l, r, val);
    go_add(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
    t[v].fst += add[v];
  }

  void go_add(int l, int r, int val) {
//    printf("[%d, %d] += %d\n", l, r, val);
    go_add(1, 0, sz - 1, l, r, val);
  }

  pii get_max(int v, int tl, int tr, int l, int r) {
    l = max(l, tl);
    r = min(r, tr);

    if  (l > r) {
      return mp(-1, 0);
    }

    if  (l == tl && r == tr) {
      return t[v];
    }

    push(v);

    int tm = (tl + tr) / 2;
    auto res = max(get_max(v * 2, tl, tm, l, r), get_max(v * 2 + 1, tm + 1, tr, l, r));
    res.fst += add[v];
    t[v] = max(t[v * 2], t[v * 2 + 1]);
    t[v].fst += add[v];
    return res;
  }

  pii get_max(int l, int r) {
    return get_max(1, 0, sz - 1, l, r);
  }
};

const int MAXN = 2e5 + 10;

int a[MAXN];
int n;
int ans[MAXN];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  SegmTree T(n);
  forn(i, n) {
    T.go_add(i, i, a[i] - (n - i - 1));
  }

//  forn(i, n) {
//    printf("%d ", T.get_max(i, i).fst);
//  }

  vi used(n, 0);
  ford(i, n) {
    auto cur = T.get_max(0, n - 1);

//    printf("i=%d, (%d, %d)\n", i, cur.fst, cur.snd);

    if  (cur.fst < 0) {
      puts(":(");
      return 0;
    }

    int pos = cur.snd;
    assert(!used[pos]);
    used[pos] = true;
    T.go_add(pos, pos, min(cur.fst - (int) 2e9, -(int) 2e9));
    T.go_add(0, n - 1, +1);

    ans[i] = cur.fst;
  }


  forn(i, n - 1) {
    if  (ans[i] > ans[i + 1]) {
      puts(":(");
      return 0;
    }
  }

  forn(i, n) {
    printf("%d ", ans[i]);
  }
  puts("");

  return 0;
}