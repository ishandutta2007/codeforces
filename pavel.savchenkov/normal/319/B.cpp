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

int a[MAXN];
int prev[MAXN];
int next[MAXN];
bool used[MAXN];
int n;

vector <int> v[2];

int main() {
  scanf("%d", &n);
  forn(i, n) {
    scanf("%d", &a[i]);
    prev[i] = i - 1;
    next[i] = i + 1;
  }

  prev[0] = -1;
  next[n - 1] = -1;
  memset (used, false, sizeof used);

  int c = 0;
  foran(i, 1, n)
    if  (a[i] < a[i - 1])
      v[c].pb(i);
  
  int ans = 0;
  while (!v[c].empty()) {
    v[1 - c].clear();
    ans++;
    
    forn(j, sz(v[c])) {
      used[v[c][j]] = true;
    }
    
    forn(j, sz(v[c])) {
      int i = v[c][j];
     
      if  (next[i] != -1)
        prev[next[i]] = prev[i];
      if  (prev[i] != -1)
        next[prev[i]] = next[i];

      if  (next[i] != -1 && prev[i] != -1 && !used[next[i]] && !used[prev[i]] && a[prev[i]] > a[next[i]])
        v[1 - c].pb(next[i]); 
    }

    c = 1 - c;
  }

  printf("%d\n", ans); 
  return 0;
}