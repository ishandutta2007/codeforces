#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;
const int MAXN = 1e5 + 5;

struct DSU {
  vi par;
  vi sz;

  DSU(int n = 0) {
    par.assign(n, 0);
    sz.assign(n, 1);
    forn(i, n) par[i] = i;
  }

  int get_set(int x) {
    return x == par[x] ? x : par[x] = get_set(par[x]); 
  }

  void union_set(int x, int y) {
    x = get_set(x);
    y = get_set(y);

    if  (x == y) {
      return;
    }

    if  (sz[x] > sz[y]) {
      swap(x, y);
    }

    sz[y] += sz[x];
    par[x] = y;
  }
};

DSU dsu;
int p[MAXN];
int n, a, b;
map<int, int> pos;
vector<int> who[MAXN];
map<int, int> mark;

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

  scanf("%d%d%d", &n, &a, &b);

  forn(i, n) {
    scanf("%d", &p[i]);
    pos[p[i]] = i;
  }

  dsu = DSU(n);

  forn(i, n) {
    if  (pos.count(a - p[i])) {
      dsu.union_set(i, pos[a - p[i]]);
    }

    if  (pos.count(b - p[i])) {
      dsu.union_set(i, pos[b - p[i]]);
    }
  }

  forn(i, n) {
    who[dsu.get_set(i)].pb(p[i]);
  }

  forn(i, n)
    if  (!who[i].empty()) {
      set<int> s;
      for (int x : who[i]) {
        s.insert(x);
      }

      // can A
      bool can = true;
      for (int x : s) {
        if  (s.find(a - x) == s.end()) {
          can = false;
          break;
        }
      }

      if  (can) {
        for (int x : s) {
          mark[x] = 1;
        }
        continue;
      }

      // can B
      can = true;
      for (int x : s) {
        if  (s.find(b - x) == s.end()) {
          can = false;
          break;  
        }
      }

      if  (can) {
        for (int x : s) {
          mark[x] = 0;
        }
        continue;
      }

      puts("NO");
      return 0;
    }

  puts("YES");
  forn(i, n) {
    printf("%d ", 1 - mark[p[i]]);
  }

	return 0;
}