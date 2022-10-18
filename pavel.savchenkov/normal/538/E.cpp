#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const ld EPS = 1e-9;
const int MAXN = 2e5 + 10;

int depth[MAXN];
int order[MAXN];
vi g[MAXN];
int n;
int root;
int sz[MAXN];

void dfs_max(int v) {
  sz[v] = g[v].empty();
  for (int to : g[v]) {
    depth[to] = depth[v] ^ 1;
    dfs_max(to);
    sz[v] += sz[to];
  } 

  if  (depth[v]) {
    order[v] = 0;
    for (int to : g[v]) {
      order[v] += order[to];
    } 
  } else {
    order[v] = 0;
    for (int to : g[v]) {
      order[v] = max(order[v], sz[v] - 1 - (sz[to] - order[to] - 1));
    }     
  }

//  printf("order[%d] = %d\n", v, order[v]);
}

int solve_max() {
  depth[root] = 0;
  dfs_max(root);    
  return order[root] + 1;
}

void dfs_min(int v) {
  sz[v] = g[v].empty();
  for (int to : g[v]) {
    depth[to] = depth[v] ^ 1;
    dfs_min(to);
    sz[v] += sz[to];
  }

  if  (depth[v]) {
    order[v] = sz[v] - 1;
    for (int to : g[v]) {
      order[v] = min(order[v], order[to]);
    }
  } else {
    order[v] = 0;
    int lost = 0;
    for (int to : g[v]) {
      lost += sz[to] - order[to] - 1;
    }
    order[v] = sz[v] - lost - 1;
  }

//  printf("order[%d] = %d\n", v, order[v]);
}

int solve_min() {
  depth[root] = 0;
  dfs_min(root);
  return order[root] + 1;
}

int in_deg[MAXN];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d\n", &n);
  forn(i, n - 1) {
    int v, to;
    scanf("%d%d", &v, &to);
    --v;
    --to;
    g[v].pb(to);
//    printf("%d -> %d\n", v, to);
    in_deg[to]++;
  }

  root = -1;
  forn(v, n) {
    if  (in_deg[v] == 0) {
      root = v;
    }
  }

  assert(root != -1);

  printf("%d ", solve_max());
  printf("%d\n", solve_min());
  return 0;
}