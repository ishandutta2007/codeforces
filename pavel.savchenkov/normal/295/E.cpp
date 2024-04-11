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
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MAXN = (int) 1e5 + 10;

int mrand() {
  return rand() * RAND_MAX + rand();
}

struct item {
  int cnt, x, prior;
  ll sum, ans;
  item *l, *r;

  item() {}

  item (int x) : x(x) {
    cnt = 1;
    prior = mrand();
    sum = 1ll * x;
    ans = 0;
    l = r = NULL;
  }
};

typedef item* pitem;

int cnt (pitem t) {
  return t ? t->cnt : 0;
}

ll ans (pitem t) {
  return t ? t->ans : 0;
}

ll sum (pitem t) {
  return t ? t->sum : 0;
}

void upd (pitem & t) {
  if  (!t) return;

  t->sum = 1ll * t->x + sum(t->l) + sum(t->r);
  t->ans = ans(t->l) + ans(t->r) + sum(t->r) * 1ll * cnt(t->l) - sum(t->l) * 1ll * cnt(t->r) + 1ll * cnt(t->l) * t->x - sum(t->l) - 1ll * cnt(t->r) * t->x + sum(t->r);
  t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void merge (pitem & t, pitem l, pitem r) {
  if  (!l || !r) return void( t = l ? l : r );

  if  (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;

  upd(t); 
}

void split (pitem t, pitem & l, pitem & r, int pos) {
  if  (!t) return void( l = r = 0 );

  int cur_pos = cnt(t->l);

  if  (pos <= cur_pos)
    split(t->l, l, t->l, pos), r = t;
  else
    split(t->r, t->r, r, pos - cur_pos - 1), l = t;

  upd(l);
  upd(r);
}

ll calc (pitem t, int l, int r) {
  if  (l > r) return 0;
  
  pitem t1, t2;
  split(t, t1, t2, r + 1);
  split(t1, t1, t, l);

  ll res = ans(t);


  merge(t, t1, t);
  merge(t, t, t2);

  return res;
}

int my_lower_bound(pitem t, int x) {
  if  (!t) return 0;

  if  (t->x == x) return cnt(t->l);

  if  (x < t->x)
    return my_lower_bound(t->l, x);

  return my_lower_bound(t->r, x) + cnt(t->l) + 1;
}

void move (pitem & t, int pos, int d) {
  pitem t1, t2;
    
  split(t, t, t2, pos + 1);
  split(t, t1, t, pos);

  int x = t->x + d;    
    
  merge(t, t1, t2);   

  pos = my_lower_bound(t, x);
   
  split(t, t1, t2, pos);
  merge(t1, t1, new item(x));
  merge(t, t1, t2);
}

pitem t;
int n, m;
int x[MAXN];
int X[MAXN];

int main() {
  t = NULL;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]); X[i] = x[i];
  }

  sort(x, x + n);

  for (int i = 0; i < n; i++)
    merge(t, t, new item(x[i]));

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int type; scanf("%d", &type);

    if  (type == 1) {
      int pos, d;
      scanf("%d %d", &pos, &d); pos--;
      
      move(t, my_lower_bound(t, X[pos]), d); 
      X[pos] += d;      
    } else {
      int l, r;
      scanf("%d %d", &l, &r); 
                
      int L = my_lower_bound(t, l);
      int R = my_lower_bound(t, r + 1) - 1;
                                  
      printf("%I64d\n", calc(t, L, R));   
    }
  }

  return 0;
}