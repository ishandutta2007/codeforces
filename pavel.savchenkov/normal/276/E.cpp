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
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int) 1e5 + 10;

struct segm_tree {
  vector <int> t;
  int sz;

  segm_tree(int Sz = 0) {
    sz = 1;
    while (sz < Sz) sz *= 2;
    t.assign(sz * 2, 0);
  }

  void put(int v, int tl, int tr, int l, int r, int x) {
    l = max(l, tl);
    r = min(r, tr);

    if  (l > r) return;

    if  (l == tl && tr == r) {
      t[v] += x;
      return;
    }

    int tm = (tl + tr) / 2;
    put(v * 2, tl, tm, l, r, x);
    put(v * 2 + 1, tm + 1, tr, l, r, x); 
  }

  void put(int l, int r, int x) {
    l = max(l, 0);
    put(1, 0, sz - 1, l, r, x);
  }

  int get(int v, int tl, int tr, int pos) {
    if  (pos < tl || tr < pos) return 0;

    if  (tl == tr)
      return t[v];

    int tm = (tl + tr) / 2;
    return t[v] + get(v * 2, tl, tm, pos) + get(v * 2 + 1, tm + 1, tr, pos);
  }

  int get(int pos) {
    return get(1, 0, sz - 1, pos);
  }
};

vector <int> g[MAXN];
int id[MAXN];
int idt[MAXN];
int depth[MAXN];
vector <segm_tree> t;
segm_tree T;
int n, q;

void dfs(int v, int p, int de) {
  depth[v] = de;

  for (int i = 0; i < sz(g[v]); i++) {
    int to = g[v][i];
    if  (to != p) {
      dfs(to, v, de + 1);
      id[v] = id[to] + 1;
      idt[v] = idt[to];
      return;
    }
  }

  idt[v] = sz(t);
  t.pb(segm_tree(de + 1));
  id[v] = 0; 
}

void go(int v, int x, int d) {
  int len = d - depth[v];

  if  (len >= 0)
    T.put(0, len, x);
                        
  if  (len >= 0) {
    int need = id[v] - d;
    int has = id[v] + depth[v] - len;
    if  (need <= has - 1)
      t[idt[v]].put(need, has - 1, x);
  } else 
    t[idt[v]].put(id[v] - d, id[v] + d, x);
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n - 1; i++) {
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }

  T = segm_tree(n);

  depth[0] = 0;
  for (int i = 0; i < sz(g[0]); i++)
    dfs(g[0][i], 0, 1);     
              
  for (int i = 0; i < q; i++) {
    int c; scanf("%d", &c);
    if  (c == 0) {
      int v, x, d;
      scanf("%d %d %d", &v, &x, &d);
      v--;
      go(v, x, d);  
    } else {
      int v; scanf("%d", &v); v--;
      int ans = T.get(depth[v]);
      if  (v > 0)
        ans += t[idt[v]].get(id[v]);
                    
      printf("%d\n", ans);
    }
  }

  return 0;
}