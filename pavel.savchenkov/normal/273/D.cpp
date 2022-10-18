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
const int MAXN = (int) 150 + 10;
const int MOD = (int) 1e9 + 7;

void add(int & a, int b) {
  while (b < 0) b += MOD;
  while (b >= MOD) b -= MOD;
  a += b;
  if  (a >= MOD) a -= MOD;
}

int mul(int a, int b) {
  LL M = 1LL * a * b;
  M %= 1LL * MOD;
  return (int)M;
}

int d[MAXN][MAXN][2][2][2];
int toadd[MAXN][MAXN][2][2][2];
int n, m;

void goadd(int l1, int l2, int r1, int r2, int fl, int fr, int c, int val) {
  if  (l1 > l2 || r1 > r2) return;

  add(toadd[l1][r2][fl][fr][c], val);

  if  (l1 == r1 && l2 == r2) return;

  if  (l2 < r1) {
    if  (l1 <= r1 - 1)
      add(toadd[l1][r1 - 1][fl][fr][c], -val);
    if  (l2 + 1 <= r2)
      add(toadd[l2 + 1][r2][fl][fr][c], -val);
    if  (l2 + 1 <= r1 - 1)
      add(toadd[l2 + 1][r1 - 1][fl][fr][c], val);
  } else {
    if  (l2 + 1 <= r2)
      add(toadd[l2 + 1][r2][fl][fr][c], -val);
    if  (l1 <= r1 - 1)
      add(toadd[l1][r1 - 1][fl][fr][c], -val);
  }
}

void clear(int c) {
  for (int l = 0; l < m; l++)
    for (int r = l; r < m; r++)
      for (int fl = 0; fl < 2; fl++)
        for (int fr = 0; fr < 2; fr++)
          d[l][r][fl][fr][c] = toadd[l][r][fl][fr][c] = 0;
}

void putadd(int c) {
  for (int len = m; len >= 1; len--)
    for (int l = 0; l <= m - len; l++)
      for (int fl = 0; fl < 2; fl++)
        for (int fr = 0; fr < 2; fr++) 
        {
          int r = l + len - 1;
          add(d[l][r][fl][fr][c], toadd[l][r][fl][fr][c]);
          if  (l == r) continue;

          add(toadd[l + 1][r][fl][fr][c], toadd[l][r][fl][fr][c]);
          add(toadd[l][r - 1][fl][fr][c], toadd[l][r][fl][fr][c]);
          if  (l + 1 <= r - 1)
            add(toadd[l + 1][r - 1][fl][fr][c], -toadd[l][r][fl][fr][c]); 
        }
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d%d", &n, &m);

  memset(d, 0, sizeof d);
  memset(toadd, 0, sizeof toadd);

  int c = 0;
  for (int l = 0; l < m; l++)
    for (int r = l; r < m; r++)
      d[l][r][0][0][c] = 1;

  int ans = 0;

  for (int i = 0; i < n; i++, c = 1 - c) {
    clear(1 - c);

    for (int l = 0; l < m; l++)
      for (int r = l; r < m; r++)
        for (int fl = 0; fl < 2; fl++)
          for (int fr = 0; fr < 2; fr++)
            add(ans, mul(d[l][r][fl][fr][c], n - i));

    for (int l = 0; l < m; l++)
      for (int r = l; r < m; r++) {

        goadd(0, l, r, m - 1, 0, 0, 1 - c, d[l][r][0][0][c]);
        goadd(l + 1, r, r, m - 1, 1, 0, 1 - c, d[l][r][0][0][c]);
        goadd(0, l, l, r - 1, 0, 1, 1 - c, d[l][r][0][0][c]);
        goadd(l + 1, r - 1, l + 1, r - 1, 1, 1, 1 - c, d[l][r][0][0][c]);

        goadd(l, r, r, m - 1, 1, 0, 1 - c, d[l][r][1][0][c]);
        goadd(l, r - 1, l, r - 1, 1, 1, 1 - c, d[l][r][1][0][c]);

        goadd(0, l, l, r, 0, 1, 1 - c, d[l][r][0][1][c]);
        goadd(l + 1, r, l + 1, r, 1, 1, 1 - c, d[l][r][0][1][c]);

        goadd(l, r, l, r, 1, 1, 1 - c, d[l][r][1][1][c]);

      }

    putadd(1 - c);
  }

  printf("%d\n", ans);
  return 0;
}