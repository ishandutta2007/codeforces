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
const int MAXN = 110;

struct state {
  int i, j, l;

  state (int i = 0, int j = 0, int l = 0) : i(i), j(j), l(l) {};
};

int dp[MAXN][MAXN][MAXN];
state prev[MAXN][MAXN][MAXN];
char s[2][MAXN];
char v[MAXN];
int lv;
int ls[2];
int pi[MAXN];
int to[MAXN][30];

void precalc () {
  pi[0] = 0;
  for (int i = 1; i < lv; i++) {
    int j = pi[i - 1];
    while (j > 0 && v[i] != v[j]) j = pi[j - 1];
    j += (v[i] == v[j]);

    pi[i] = j;
  }

  for (int i = 0; i < lv; i++)
    for (int c = 0; c < 30; c++) {
      char C = char(c + 'A');

      if  (v[i] == C) {
        to[i][c] = i + 1;
      } else if  (i > 0) {
        to[i][c] = to[pi[i - 1]][c];
      } else {
        to[i][c] = 0;
      }
    }
}

void remax (int i, int j, int l, state prv, int ndp) {
  if  (ndp <= dp[i][j][l])
    return;

  prev[i][j][l] = prv;
  dp[i][j][l] = ndp;
}

void restore (int i, int j, int l) {
  if  (dp[i][j][l] <= 0)
    return;

  int ni = prev[i][j][l].i;
  int nj = prev[i][j][l].j;
  int nl = prev[i][j][l].l;

  restore(ni, nj, nl);
  if  (dp[ni][nj][nl] == dp[i][j][l] - 1)
    printf("%c", s[0][i - 1]);
}

int main() {
  memset (dp, -1, sizeof dp);

  forn(i, 2) {
    gets(s[i]);
    ls[i] = strlen(s[i]);
  }

  gets(v);
  lv = strlen(v);

  precalc();

  dp[0][0][0] = 0;
  for (int i = 0; i < ls[0]; i++)
    for (int j = 0; j < ls[1]; j++)
      for (int l = 0; l < lv; l++)
        if  (dp[i][j][l] != -1) {
          int curDp = dp[i][j][l];

          remax(i, j + 1, l, state(i, j, l), curDp);
          remax(i + 1, j, l, state(i, j, l), curDp);

          if  (s[0][i] != s[1][j])
            continue;

          int nl = to[l][int(s[0][i] - 'A')];
          remax(i + 1, j + 1, nl, state(i, j, l), curDp + 1);
        }

  int mx = -1;
  for (int i = 0; i <= ls[0]; i++)
    for (int j = 0; j <= ls[1]; j++)
      for (int l = 0; l < lv; l++)
        mx = max(mx, dp[i][j][l]);

  if  (mx <= 0) {
    puts("0");
    return 0;
  }

  for (int i = 0; i <= ls[0]; i++)
    for (int j = 0; j <= ls[1]; j++)
      for (int l = 0; l < lv; l++)
        if  (dp[i][j][l] == mx) {
          restore(i, j, l);
          return 0;
        }
  return 0;
}