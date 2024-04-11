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
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;

int x1[9];
int y1[9];
int x2[9];
int y2[9];
int n;

int main() {
  scanf("%d", &n);

  int maxx = -1, maxy = -1, minx = int(1e9), miny = int(1e9);
  ll S = 0ll;

  forn(i, n) {
    scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
    maxx = max(maxx, max(x1[i], x2[i]));
    minx = min(minx, min(x1[i], x2[i]));
    maxy = max(maxy, max(y1[i], y2[i]));
    miny = min(miny, min(y1[i], y2[i]));

    S += ll(abs(x1[i] - x2[i])) * ll(abs(y1[i] - y2[i]));
  }

  if  (maxx - minx != maxy - miny) {
    puts("NO");
    return 0;
  }

  ll nS = ll(maxx - minx) * ll(maxy - miny);

  puts(S == nS ? "YES" : "NO");
  return 0;
}