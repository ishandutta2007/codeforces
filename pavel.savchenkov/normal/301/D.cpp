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
const int MAXN = 2 * int(1e5) + 10;

struct fenw_tree {
  vector <int> t;

  fenw_tree (int n = 0) {
    t.assign(n, 0);
  }

  void add (int i, int val) {
    for (; i < sz(t); i = i | (i + 1))
      t[i] += val;
  }

  int get (int r) {
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ans += t[r];
    return ans;
  }

  int get (int l, int r) {
    return get(r) - get(l - 1);
  }
};

fenw_tree t;
int n, m;
int pos[MAXN];
vector <int> divs[MAXN];
vector <int> l[MAXN];
vector <int> id[MAXN];
int ans[MAXN];
 
int main() {
  scanf("%d %d", &n, &m);
  forn(i, n) {
    int p;
    scanf("%d", &p);
    pos[p] = i;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + i; j <= n; j += i) {
      divs[pos[j]].pb(pos[i]);
      divs[pos[i]].pb(pos[j]);
    }

    divs[pos[i]].pb(pos[i]);
  }

  forn(i, m) {
    int L, R; scanf("%d %d", &L, &R); L--; R--;
    l[R].pb(L);
    id[R].pb(i);
  }

  t = fenw_tree(n);

  forn(i, n) {
    forn(j, sz(divs[i]))
      if  (divs[i][j] <= i)
        t.add(divs[i][j], 1);

    forn(j, sz(l[i]))   
      ans[id[i][j]] = t.get(l[i][j], i);
  }

  forn(i, m)
    printf("%d\n", ans[i]);
  return 0;
}