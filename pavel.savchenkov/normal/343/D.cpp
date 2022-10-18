#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define all(A) A.begin(), A.end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int INF = int(1e9);
const int MAXN = 5 * int(1e5) + 10;

struct segm_tree {
  vi t;
  vi func;
  int sz;

  segm_tree (int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    t.assign(sz * 2 + 10, -1);
    func.assign(sz * 2 + 10, -1);
  }

  void push (int v, int tl, int tr) {
    if  (tl == tr || t[v] == -1)
      return;

    t[v * 2] = t[v * 2 + 1] = t[v];
    func[v * 2] = func[v * 2 + 1] = t[v];
  }

  void recalc (int v) {
    if  (t[v * 2] == t[v * 2 + 1])
      t[v] = t[v * 2];
    else
      t[v] = -1;

    func[v] = max(func[v * 2], max(func[v * 2 + 1], (t[v] == -1) ? -INF : t[v]));
  }

  void ass (int v, int tl, int tr, int l, int r, int val) {
    push(v, tl, tr);

    l = max(l, tl);
    r = min(r, tr);

    if  (l > r)
      return;

    if  (l == tl && r == tr) {
      t[v] = val;
      func[v] = val;
      return;
    }

    int tm = (tl + tr) / 2;
    ass(v * 2, tl, tm, l, r, val);
    ass(v * 2 + 1, tm + 1, tr, l, r, val);

    recalc(v);
  }

  void ass (int l, int r, int val) {
    ass(1, 0, sz - 1, l, r, val);
  }

  int get_max (int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);

    l = max(l, tl);
    r = min(r, tr);

    if  (l > r)
      return -INF;

    if  (tl == l && tr == r)
      return func[v];

    int tm = (tl + tr) / 2;
    int ret = max(get_max(v * 2, tl, tm, l, r), get_max(v * 2 + 1, tm + 1, tr, l, r));
    recalc(v);
    return ret;
  }

  int get_max (int l, int r) {
    return get_max(1, 0, sz - 1, l, r);
  }
};

segm_tree time_1;
segm_tree state;
segm_tree time_0;
int tin[MAXN];
int tout[MAXN];
vi g[MAXN];
int n, q;
int timer = 0;

void dfs (int v, int p = -1) {
  tin[v] = timer++;

  forn(i, sz(g[v])) {
    int to = g[v][i];

    if  (to == p)
      continue;

    dfs(to, v);
  }

  tout[v] = timer;
}

int main() {
  scanf("%d", &n);
  forn(i, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  dfs(0);

  state = segm_tree(n);
  time_1 = segm_tree(n);
  time_0 = segm_tree(n);
  state.ass(0, n - 1, 0);
  time_1.ass(0, n - 1, -1);
  time_0.ass(0, n - 1, -1);

  scanf("%d", &q);
  timer = 0;
  while (q--) {
    int c, v;   
    scanf("%d%d", &c, &v);
    v--;
    int l = tin[v];
    int r = tout[v] - 1;

    if  (c == 1) {
      time_1.ass(l, r, timer);
      state.ass(l, r, 1);    
    } else if  (c == 2) {
      time_0.ass(l, l, timer);
    } else {
      assert(c == 3);
      int res = -1;
      
      if  (state.get_max(l, l) == 0) {
        res = 0;
      } else {
        int t_1 = time_1.get_max(l, l);
        int t_0 = time_0.get_max(l, r);

        if  (t_1 == -1) {
          res = 0;
        } else if  (t_0 == -1) {
          res = 1;
        } else if  (t_1 > t_0)
          res = 1;
        else
          res = 0;
      }

      printf("%d\n", res);
    }    
    timer++;
  }

  return 0;
}