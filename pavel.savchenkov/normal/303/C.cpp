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
const int MAXN = int(1e6) + 5;

vector <pii> bad[MAXN];
int n, k;
int a[5010];

int par[5010];
int sz[5010];

int get (int x) {
  return par[x] == x ? x : par[x] = get(par[x]);
}

int union_set (int x, int y) {
  x = get(x);
  y = get(y);

  if  (x == y)
    return 0;

  if  (sz[x] > sz[y])
    swap(x, y);

  par[x] = y;
  return 1;
}

bool good (int m) {
  int cnt = 0;
  int J = m;

  for (int j = m; j < MAXN; j += m) {
    J = j;

    forn(i, sz(bad[j]))
      cnt += union_set(bad[j][i].f, bad[j][i].s);

    if  (cnt > k)
      break; 
  }

  for (int j = m; j <= J; j += m)
    forn(i, sz(bad[j])) {
      int x = bad[j][i].f;
      int y = bad[j][i].s;
      par[x] = x;
      par[y] = y;
      sz[x] = sz[y] = 1;
    }

  return cnt <= k;
}

int main() {
//  freopen("in.txt", "r", stdin);

  scanf("%d %d", &n, &k);

  if  (n - k <= 1) {
    puts("1");
    return 0;
  }      

  int ma = -1;
  forn(i, n) {
    scanf("%d", &a[i]);
    ma = max(a[i], ma);
             
    forn(j, i) {
      int id = abs(a[i] - a[j]);
      if  (bad[id].empty() || sz(bad[id]) <= k)
        bad[abs(a[i] - a[j])].pb(mp(i, j));
    }
  }

  forn(i, n) {
    par[i] = i;
    sz[i] = 1;
  }

  for (int i = 2; i < MAXN; i++)
    if  (good(i)) {
      printf("%d\n", i);
      return 0;
    }

  printf("%d\n", ma + 1);
  return 0;
}