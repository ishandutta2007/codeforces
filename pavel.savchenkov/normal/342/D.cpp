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
const int MAXN = int(1e4) + 10;
const int MOD = 1000000007;

void add (int & a, int b) {
  if  ((a += b) >= MOD)
    a -= MOD;
}

int dp[2][1 << 3][MAXN];
int n;
char a[5][MAXN];

bool field (int i, int j) {
  return 0 <= i && i < 3 && 0 <= j && j <= n;
}

bool on (int i, int j) {
  return 0 <= i && i < 3 && 0 <= j && j <= n && a[i][j] == '.';
}

bool check (int i1, int j1, int i2, int j2, int & was) {
  if  (!on(i1, j1) || !on(i2, j2))
    return false;

  if  (i1 == i2) {
    was |= field(i1, j2 + 1) && a[i1][j2 + 1] == 'O';
    was |= field(i1, j1 - 1) && a[i1][j1 - 1] == 'O';
  } else {
    was |= field(i1 - 1, j1) && a[i1 - 1][j1] == 'O';
    was |= field(i2 + 1, j1) && a[i2 + 1][j1] == 'O';
  }

  return true;
}

void go (int i, int j, int was, int mask, int curDp) {
  if  (j == 3) {
    add(dp[was][mask][i + 1], curDp);
    return;    
  }

  int nwas = was;
  if  (check(j, i, j, i + 1, nwas)) {
    go(i, j + 1, nwas, mask | (1 << j), curDp);
  }

  nwas = was;
  if  (check(j, i, j + 1, i, nwas)) {
    go(i, j + 2, nwas, mask, curDp);
  }

  if  (!on(j, i))
    go(i, j + 1, was, mask, curDp);
}

void recalc (int was, int mask, int i) {
  if  (dp[was][mask][i] == 0)
    return;

  char old[3];
  forn(j, 3)
    old[j] = a[j][i];

  forn(j, 3)
    if  ((1 << j) & mask)
      a[j][i] = 'X';

  go(i, 0, was, 0, dp[was][mask][i]);

  forn(j, 3)
    a[j][i] = old[j]; 
}

int main() {
  scanf("%d\n", &n);
  forn(i, 3) {
    gets(a[i]);
    a[i][n] = '.';
  }
  
  memset (dp, 0, sizeof dp);
  dp[0][0][0] = 1;

  for (int i = 0; i < n; i++)
    for (int was = 0; was <= 1; was++)
      for (int mask = 0; mask < (1 << 3); mask++) {
        recalc(was, mask, i);
      }

  printf("%d\n", dp[1][0][n]);
  return 0;
}