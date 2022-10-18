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

ll x, y, m;

ll solve () {
  if  (x >= m || y >= m)
    return 0;

  if  (x <= 0 && y <= 0)
    return -1;

  ll ans = 0;
  if  (x < y)
    swap(x, y);

  if  (y < 0) {
    ans = abs(y) / x;
    y += ans * x;
  }

  while (1) {
    if  (x >= m || y >= m)
      return ans;

    ll s = x + y;
    if  (x < y)
      x = s;
    else
      y = s;
    ans++;
  }
}

int main() {
  cin >> x >> y >> m;

  cout << solve() << '\n';
  return 0;
}