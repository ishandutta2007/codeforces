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

#define pb push_back
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define f first
#define s second
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int)1e5 + 10;
const int INF = (int)1e9 + 10;

using namespace std;

struct segm_tree {
  vector < vector <int> > t;
  int sz;

  segm_tree() {};

  segm_tree(const vector <int> & a) {
    sz = 1;
    while (sz < sz(a)) sz *= 2;
    t.assign(sz + sz, vector <int> ());

    build(1, 0, sz - 1, a);
  }

  void build(int v, int tl, int tr, const vector <int> & a) {
    if  (tl == tr) {
      if  (tl < sz(a)) 
        t[v].pb(a[tl]);
      else
        t[v].pb(INF + 1);
      return;
    }
   
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);

    int l = 0; int r = 0;
    while (l != sz(t[v * 2]) || r != sz(t[v * 2 + 1]))
      if  (r == sz(t[v * 2 + 1]) || (l < sz(t[v * 2]) && t[v * 2][l] < t[v * 2 + 1][r]))
        t[v].pb(t[v * 2][l++]);
      else
        t[v].pb(t[v * 2 + 1][r++]);
  }

  int get(int v, int tl, int tr, int l, int r, int d, int u) {
    if  (r < tl || tr < l) return 0;

    if  (l <= tl && tr <= r) {
      int ly = lower_bound(t[v].begin(), t[v].end(), d) - t[v].begin();
      int ry = upper_bound(t[v].begin(), t[v].end(), u) - t[v].begin();
      return max(0, ry - ly);
    }

    int tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, r, d, u) + get(v * 2 + 1, tm + 1, tr, l, r, d, u);
  }

  int get(int l, int r, int ly, int ry) {
  //  printf("%d %d\n", l, r);
    if  (l > r || ly > ry) return 0;
    return get(1, 0, sz - 1, l, r, ly, ry);
  }
};

segm_tree t;

int n;
int a[20];
pii xy[MAXN];
vector <int> y;
vector <int> x;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", &xy[i].f, &xy[i].s);

  sort(xy, xy + n);  

  y.assign(n, 0); x.assign(n, 0);
  for (int i = 0; i < n; i++)
    y[i] = xy[i].s, x[i] = xy[i].f;
                                
  t = segm_tree(y);        

  for (int i = 0; i < 9; i++)
    scanf("%d", &a[i]);

  sort(a, a + 9);
  sort(y.begin(), y.end());

  do {
    int x1 = x[a[0] + a[1] + a[2]];
    x1 = lower_bound(x.begin(), x.end(), x1) - x.begin(); 
    int x2 = x[a[0] + a[1] + a[2] + a[3] + a[4] + a[5] - 1];
    x2 = upper_bound(x.begin(), x.end(), x2) - x.begin() - 1;

    int y1 = y[a[2] + a[5] + a[8]];
    y1 = y[lower_bound(y.begin(), y.end(), y1) - y.begin()]; 
    int y2 = y[a[2] + a[5] + a[8] + a[1] + a[4] + a[7] - 1];
    y2 = y[upper_bound(y.begin(), y.end(), y2) - y.begin() - 1];

    if  (t.get(0, x1 - 1, y2 + 1, INF) != a[0]) continue;  
    if  (t.get(0, x1 - 1, y1, y2) != a[1]) continue;       
    if  (t.get(0, x1 - 1, -INF, y1 - 1) != a[2]) continue;
    if  (t.get(x1, x2, y2 + 1, INF) != a[3]) continue;
    if  (t.get(x1, x2, y1, y2) != a[4]) continue;
    if  (t.get(x1, x2, -INF, y1 - 1) != a[5]) continue;
    if  (t.get(x2 + 1, n - 1, y2 + 1, INF) != a[6]) continue;
    if  (t.get(x2 + 1, n - 1, y1, y2) != a[7]) continue;
    if  (t.get(x2 + 1, n - 1, -INF, y1 - 1) != a[8]) continue;

    printf("%.10lf %.10lf\n%.10lf %.10lf\n", (double)x[x1] - 0.5, (double)x[x2] + 0.5, (double)y1 - 0.5, (double)y2 + 0.5);
    return 0;
  } while (next_permutation(a, a + 9));

  puts("-1");

  return 0;
}