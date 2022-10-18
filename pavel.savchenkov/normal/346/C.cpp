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
const int MAXN = int(1e5) + 10;
const int MAXVAL = int(1e6) + 10;
const int INF = int(1e9);

int a, b, n;
vi x[2];

int main() {
  scanf("%d", &n);
  x[0].assign(n, 0);
  forn(i, n) {
    scanf("%d", &x[0][i]);
  }
  scanf("%d%d", &a, &b);

  sort(all(x[0]));
  x[0].resize(unique(all(x[0])) - x[0].begin());

  int res = 0;
  int c = 0;
  while (b < a) {
    x[1 - c].clear();
    int besta = a - 1;

    forn(i, sz(x[c])) {
      int na = a - a % x[c][i];

      if  (na >= b) {
        besta = min(besta, na);
        x[1 - c].pb(x[c][i]);
      } 
    }

    a = besta;
    c = 1 - c;
    res++;
  }

  printf("%d\n", res);
  return 0;
}