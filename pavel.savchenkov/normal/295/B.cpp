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
const int MAXN = 510;
const int INF = (int) 1e9;

int n;
int d[MAXN][MAXN];
int a[MAXN][MAXN];
bool has[MAXN];

int x[MAXN];

vector <ll> res;

void add (int v) {

  for (int u = 0; u < n; u++) {
    if  (!has[u]) continue;

    d[v][u] = a[v][u];
    d[u][v] = a[u][v];

    for (int b = 0; b < n; b++) {
      if  (has[b] && d[b][u] + a[v][b] < d[v][u])
        d[v][u] = d[b][u] + a[v][b];

      if  (has[b] && d[u][b] + a[b][v] < d[u][v])
        d[u][v] = d[u][b] + a[b][v];
    } 
  }

  for (int b = 0; b < n; b++) {
    if  (!has[b]) continue;

    for (int c = 0; c < n; c++) {
      if  (has[c] && d[b][c] > d[b][v] + d[v][c])
        d[b][c] = d[b][v] + d[v][c];

      if  (has[c] && d[c][b] > d[c][v] + d[v][b])
        d[c][b] = d[c][v] + d[v][b];
    }
  }

  has[v] = true;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if  (!has[i]) continue;

    for (int j = i + 1; j < n; j++)
      if  (has[j]) ans += 1ll * d[i][j] + 1ll * d[j][i];
  }

  res.pb(ans);
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &a[i][j]);

  for (int i = 0; i < n; i++)
    scanf("%d", &x[i]), x[i]--;

  reverse(x, x + n);

  memset (has, false, sizeof has);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      d[i][j] = INF;


  for (int i = 0; i < n; i++)
    add(x[i]);

  for (int i = n - 1; i >= 0; i--)
    printf("%I64d ", res[i]);
  return 0;
}