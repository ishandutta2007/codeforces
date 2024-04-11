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
const int MAXN = 1010;

int next[MAXN];
int prev[MAXN];

vector <int> sz;
int n, x;

bool dp[MAXN][MAXN];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset (prev, -1, sizeof prev);

  scanf("%d %d", &n, &x); x--;
  forn(i, n) {
    scanf("%d", &next[i]);
    next[i]--;
    
    if  (next[i] != -1)
      prev[next[i]] = i;
  }

  forn(i, n)
    if  (prev[i] == -1) {
      bool bad = false;
      int v = i;
      int cnt = 0;
      while (v != -1) {
        cnt++;
        if  (v == x)
          bad = true;
        v = next[v];
      }

      if  (!bad)
        sz.pb(cnt);
//      printf("%d %d\n", cnt, i);
    }

  memset (dp, false, sizeof dp);
  dp[0][0] = true;
  for (int i = 0; i < sz(sz); i++)
    for (int w = 0; w <= n; w++) {
      int nw = w + sz[i];
      dp[i + 1][nw] |= dp[i][w];
      dp[i + 1][w] |= dp[i][w];
    }

  int pos = 0;
  forn(i, n)
    if  (next[i] == -1) {
      int v = i;
      pos = 0; bool ok = false;
      while (v != -1) {
        if  (v == x) {
          ok = true;
          break;
        }
        pos++;
        v = prev[v];
      }
      
      if  (ok)
        break;
    }

  for (int i = 1; i <= n; i++)
    if  (i - 1 - pos >= 0 && dp[sz(sz)][i - 1 - pos])
      printf("%d\n", i);             
  return 0;
}