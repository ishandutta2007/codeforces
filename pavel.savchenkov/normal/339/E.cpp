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
const int MAXN = 1010;

int a[MAXN];
int n;
vi vals;
vector <pii> ans;
int pos[3][MAXN];

void output () {
  printf("%d\n", sz(ans));

  ford(i, sz(ans))
    printf("%d %d\n", ans[i].f, ans[i].s);

  exit(0);
}

bool good () {
  forn(i, n - 1)
    if  (a[i] > a[i + 1])
      return false;

  return true;
}

void go (int done) {
  if  (good())
    output();

  if  (done == 3) {
    return;
  }

  forn(i, n)
    pos[done][a[i]] = i;

  forn(i, sz(vals))
    foran(j, i + 1, sz(vals)) {
      int l = pos[done][vals[i]];
      int r = pos[done][vals[j]];

      if  (l > r)
        swap(l, r);

      ans.pb(mp(l + 1, r + 1));
      reverse(a + l, a + r + 1);

      go(done + 1);

      ans.pop_back();
      reverse(a + l, a + r + 1);
    }
}

int main() {
  scanf("%d", &n);

  forn(i, n)
    scanf("%d", &a[i]);

  vals.pb(a[0]);
  vals.pb(a[n - 1]);

  foran(i, 1, n - 1)
    if  (abs(a[i - 1] - a[i]) != 1 || abs(a[i + 1] - a[i]) != 1)
      vals.pb(a[i]);

  go(0);

  return 0;
}