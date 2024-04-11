#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <cassert>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fst first
#define snd second

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;

#define FNAME "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#endif

int n, m;
vvi a;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return 0;
  }
  scanf("%d\n", &m);
  a.assign(n, vi(m));
  forn(i, n) {
    static char buf[1000];
    scanf("%s\n", buf);
    forn(j, m) {
      a[i][j] = buf[j] == '#';
    }
  }
  return 1;
}

struct DSU {
  vi par;

  DSU(int s = 0) {
    par.assign(s, -1);
  }

  int get(int x) {
    return par[x] < 0 ? x : par[x] = get(par[x]);
  }

  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if  (x == y) {
      return 0;
    }
    if  (-par[x] < -par[y]) {
      swap(x, y);
    }
    par[x] += par[y];
    par[y] = x;
    return 1;
  }
};

bool solve() {
  forn(it, 2) {
    DSU dsu(n);
    forn(j, m) {
      forn(i1, n) {
        forn(i2, n) {
          if  (a[i1][j] && a[i2][j]) {
            dsu.unite(i1, i2);
          }
        }
      }
    } 

    forn(i, n) {
      int r = dsu.get(i);
      if  (a[i] != a[r]) {
        return 0;
      }
    }

    vvi na(m, vi(n));
    forn(i, n) {
      forn(j, m) {
        na[j][i] = a[i][j];
      }
    }
    a = na;
    swap(n, m);
  }
  return 1;
}

int main() {
#ifdef LOCAL
  freopen(FNAME ".in", "r", stdin);
  freopen(FNAME ".out", "w", stdout);
#endif

  while (read()) {
    puts(solve() ? "YES" : "NO");
  }

  return 0;
}