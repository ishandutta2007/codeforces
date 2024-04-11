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

int a[110];
int n;

int main() {
  scanf("%d", &n);
  forn(i, n) scanf("%d", &a[i]);

  int ans = 0;
  for (int l = 0; l < n; l++)
    for (int r = l; r < n; r++) {
      int cur = 0;
      
      for (int i = l; i <= r; i++)
        a[i] = 1 - a[i];

      forn(i, n)
        cur += a[i];
      ans = max(ans, cur);

      for (int i = l; i <= r; i++)
        a[i] = 1 - a[i];
    }

  printf("%d\n", ans);
  return 0;
}