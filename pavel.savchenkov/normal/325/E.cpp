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
const int MAXN = int(1e5) + 10;

bool was[MAXN];
int p[MAXN][2];
vi ans;
int n;

void go (int v) {
  was[v] = true;
  ans.pb(v);

  if  (!was[p[v][1]])
    go(p[v][1]);
  else if  (!was[p[v][0]])
    go(p[v][0]);
  else {
    if  (v == 1) {
      ans.pb(0);
      return;
    }

    puts("-1");
    exit(0);
  }
}

int main() {
  memset (was, false, sizeof was);
  scanf("%d", &n);

  forn(i, n) {
    p[i][0] = i / 2;

    if  ((i + n - 1) % 2 == 0)
      p[i][1] = (i + n - 1) / 2;
    else
      p[i][1] = (i + n) / 2;
  }

  go(0);

  ford(i, sz(ans))
    printf("%d%c", ans[i], " \n"[i == 0]);
  return 0;
}