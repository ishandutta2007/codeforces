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
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int) 1e5 + 10;

struct segm_tree {
  vector <LL> ma;
  vector <LL> val;
  int sz;

  segm_tree() {};

  segm_tree(const vector <int> & a) {
    sz = 1;
    while (sz < sz(a)) sz *= 2;
    ma.assign(sz * 2 + 10, 0);
    val.assign(sz * 2 + 10, 0);
    build(1, 0, sz - 1, a);
  }

  void build(int v, int tl, int tr, const vector <int> & a) {
    if  (tl == tr) {
      ma[v] = val[v] = tl < sz(a) ? 1LL * a[tl] : -100LL;
      return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    ma[v] = max(ma[v * 2], ma[v * 2 + 1]);
    val[v] = -1LL;
  }

  void push(int v) {
    if  (val[v] == -1LL) return;
    val[v * 2] = val[v * 2 + 1] = ma[v * 2] = ma[v * 2 + 1] = val[v];
    ma[v] = val[v];
    val[v] = -1LL;
  }

  LL getmax(int v, int tl, int tr, int l, int r) {
    r = min(r, tr);
    l = max(l, tl);

    if  (l > r) return -100LL;

    if  (l == tl && r == tr) return ma[v];

    push(v);

    int tm = (tl + tr) / 2;
    return max(getmax(v * 2, tl, tm, l, r), getmax(v * 2 + 1, tm + 1, tr, l, r));
  }

  LL getmax(int l, int r) {
    return getmax(1, 0, sz - 1, l, r);
  }

  void put(int v, int tl, int tr, int l, int r, LL x) {
    r = min(r, tr);
    l = max(l, tl);

    if  (l > r) return;

    if  (l == tl && r == tr) { 
      val[v] = ma[v] = x;
      return;
    }

    push(v);

    int tm = (tl + tr) / 2;
    put(v * 2, tl, tm, l, r, x);
    put(v * 2 + 1, tm + 1, tr, l, r, x);
    ma[v] = max(ma[v * 2], ma[v * 2 + 1]);
  }

 void put(int l, int r, LL x) {
   put(1, 0, sz - 1, l, r, x);
 } 
};

segm_tree t;
vector <int> a;
int n, m;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n); a.assign(n, 0);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  t = segm_tree(a);

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int w; LL h; scanf("%d%I64d", &w, &h);
    LL ans = t.getmax(0, w - 1);
    printf("%I64d\n", ans);
    t.put(0, w - 1, ans + h);
  }

  return 0;
}