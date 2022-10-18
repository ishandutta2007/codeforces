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
const int MAXN = 310;
const int MAXVAL = (int) 1e5 + 10;
const int MOD = (int) 1e9 + 7;

int madd (int a, int b) {
  a += b;
  while (a >= MOD) a -= MOD;
  while (a < 0) a += MOD;

  return a;
}               

int d[MAXVAL][MAXN];
int to[MAXN];
int from[MAXN];
int n, q, t;
int a[MAXN];

int add[MAXN];

vector <int> top;

int color[MAXN];

ll calc (int v) {
  top.pb(v);

  if  (to[v] != -1) {
    ll ret = calc(to[v]);
    add[v] = add[to[v]] + a[to[v]];
    return ret + 1ll * add[v];
  }

  add[v] = 0;
  return 0;
}


void dfs (int v) {
  if  (color[v] == 1) {
    puts("0");
    exit(0);
  }

  color[v] = 1;

  if  (to[v] != -1) dfs(to[v]);

  color[v] = 2;
}

void check () {
  memset (color, 0, sizeof color);

  for (int i = 0; i < n; i++)
    if  (color[i] == 0) dfs(i);
}


int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset (d, 0, sizeof d);
  memset (to, -1, sizeof to);
  memset (from, -1, sizeof from);

  scanf("%d %d %d", &n, &q, &t);

  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (int i = 0; i < q; i++) {
    int b, c; scanf("%d %d", &b, &c);
    b--; c--;
    to[c] = b;
    from[b] = c;
  }

  check();

  ll T = 1ll * t;
  for (int i = 0; i < n; i++)
    if  (from[i] == -1) {
      T -= calc(i);
      if  (T < 0) {
        puts("0");
        return 0;
      }
    }

/*  for (int i = 0; i < n; i++)
    printf("%d ", top[i]);
  puts("");

  for (int i = 0; i < n; i++)
    printf("%d ", add[i]);
  puts("");  */

  t = (int) T;

//  printf("t = %d\n", t);

  
  d[0][0] = 1;

  for (int i = 0; i < n; i++)
    for (int c = 0; c <= t; c++) {
      if  (d[c][i] == 0) continue;

      int pos = top[i];

      d[c][i + 1] = madd(d[c][i + 1], d[c][i]);

      int nc = c + a[pos] + add[pos];
      
      if  (nc > t) continue;

      d[nc][i] = madd(d[nc][i], d[c][i]);
    }

  printf("%d\n", d[t][n]);
  return 0;
}