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
const int MAXN = 110;
const ll INF = ll(1e17);

int a[MAXN];
vector <pii> g[MAXN];
int x[MAXN];
int y[MAXN];
int n, D;

ll d[MAXN];

void addE (int a, int b, int w) {
  g[a].pb(mp(b, w));
  g[b].pb(mp(a, w));
}

int dist (int i, int j) {
  return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

bool check (int W) {
  forn(i, n) d[i] = -INF;
  d[0] = W + 1;

  forn(it, n - 1) {  
    forn(v, n)
      forn(i, sz(g[v])) {
        int u = g[v][i].f;
        int w = g[v][i].s;
        
        if  (d[v] - ll(w) > 0 && d[u] < d[v] - ll(w) + ll(a[u]))
          d[u] = d[v] - ll(w) + ll(a[u]);
      } 
  }
       
  return d[n - 1] > 0;
}
 
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d", &n, &D);
  a[0] = a[n - 1] = 0;
  for (int i = 1; i < n - 1; i++)
    scanf("%d", &a[i]);

  forn(i, n) {
    scanf("%d %d", &x[i], &y[i]);

    forn(j, i) addE(j, i, D * dist(i, j));
  }
  
  int L = 0; int R = int(1e9);
  while (L != R - 1) {
    int M = (L + R) / 2;
    if  (check(M)) R = M; else L = M;
  }
  
  cout << R << '\n';
  return 0;
}