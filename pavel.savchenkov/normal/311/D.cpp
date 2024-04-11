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

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;
const int MOD = 95542721;
const int P = 48;

int mul (int a, int b) {
  ll M = 1ll * a * b;
  M %= ll(MOD);
  return int(M);
}

int add (int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int a[MAXN][P + 3];
int n, q, sz;
int t[MAXN * 4][P + 3];
int cnt[MAXN * 4];

int tmp[50];

void shift (int v, int c) {
  forn(i, P)
    tmp[i] = t[v][i];

  forn(i, P)
    t[v][i] = tmp[(i + c) % P];
}

void upd (int v) {
  forn(i, P)
    t[v][i] = add(t[v * 2][i], t[v * 2 + 1][i]);
}

void build (int v, int tl, int tr) {
  cnt[v] = 0;

  if  (tl == tr) {
    if  (tl < n) {
      forn(i, P)
        t[v][i] = a[tl][i];
    } else memset (t[v], 0, sizeof t[v]); 
    return; 
  }

  int tm = (tl + tr) / 2;
  build(v * 2, tl, tm);
  build(v * 2 + 1, tm + 1, tr);

  upd(v);
}

void build () {
  build(1, 0, sz - 1);
}

void push (int v, int tl, int tr) {
  shift(v, cnt[v]);

  if  (tl != tr) {
    cnt[v * 2] += cnt[v];
    cnt[v * 2 + 1] += cnt[v];
  }

  cnt[v] = 0;
}                             

int get (int v, int tl, int tr, int l, int r) {
  l = max(l, tl);
  r = min(r, tr);

  push(v, tl, tr);

  if  (l > r) return 0;

  if  (tl == l && tr == r) {
    return t[v][0];
  }

  int tm = (tl + tr) / 2;
  return add(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
}

int get (int l, int r) {
  return get(1, 0, sz - 1, l, r);
}

void go (int v, int tl, int tr, int l, int r) {
  l = max(l, tl);
  r = min(r, tr);

  push(v, tl, tr);

  if  (l > r) return;

  if  (tl == l && tr == r) {
    cnt[v]++;
    push(v, tl, tr);
    return;
  }

  int tm = (tl + tr) / 2;
  go(v * 2, tl, tm, l, r);
  go(v * 2 + 1, tm + 1, tr, l, r);
  upd(v);
}

void go (int l, int r) {
  go(1, 0, sz - 1, l, r);
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);
  forn(i, n) scanf("%d", &a[i][0]), a[i][0] %= MOD;

  foran(j, 1, P)
    forn(i, n)
      a[i][j] = mul(a[i][j - 1], mul(a[i][j - 1], a[i][j - 1]));

  sz = 1;
  while (sz < n) sz *= 2;

  build();

  scanf("%d", &q);
  forn(i, q) {
    int T, l, r;
    scanf("%d %d %d", &T, &l, &r);
    l--; r--;

    if  (T == 1)
      printf("%d\n", get(l, r));
    else
      go(l, r);
  }

  return 0;
}