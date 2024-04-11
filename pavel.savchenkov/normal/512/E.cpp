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
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr(T x) {
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

struct Triag {
  vector<set<int> > g;
  int n;
  vii order1;
  vii order2;

  Triag(int n) : n(n) {
    g.resize(n);
  }

  void read() {
    forn(i, n - 3) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a;
      --b;

      addE(a, b);
    }

    forn(i, n) {
      addE(i, (i + 1) % n);
    }
  }

  void addE(int a, int b) {
    g[a].insert(b);
    g[b].insert(a);
  }

  void delE(int a, int b) {
    g[a].erase(b);
    g[b].erase(a);
  }

  bool haveE(int v, int to) const {
    if  (sz(g[v]) > sz(g[to])) {
      swap(v, to);
    }
    auto it = g[v].lower_bound(to);
    return it != g[v].end() && *it == to;
  }

  void change(int v, int a, int b) {
    order1.pb(mp(a, b));
    int mid = get_mid(a, b);
    order2.pb(mp(v, mid));
    delE(a, b);
    addE(v, mid);    
  }

  int get_mid(int l, int r) {
    for (int v = l + 1; v < r; ++v) {
      if  (haveE(v, l) && haveE(v, r)) {
        return v;
      }
    }
    printf("not found mid, l = %d, r = %d\n", l, r);
    assert(false);
    return -1;
  }

  void to_base(int l, int r) {
//    printf("to_base [%d, %d]\n", l, r);
    
    if  (l + 1 >= r) {
      return;
    }

    assert(haveE(0, l));

    int v = *g[0].upper_bound(l);
    
    if  (v == l + 1) {
      to_base(l + 1, r);
      return;
    }

    int mid = get_mid(l, v);
    change(0, l, v);
    to_base(l, mid);
    to_base(mid, v);
    to_base(v, r);
  }

  void to_base() {
    to_base(1, n - 1);
//    puts("end base");
  }
};

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  int n;
  scanf("%d\n", &n);
  Triag start(n);
  start.read();

  Triag final(n);
  final.read();

  start.to_base();
  final.to_base();

  auto r1 = start.order1;
  auto r2 = final.order2;
  reverse(all(r2));

  auto r = r1;
  for (auto it : r2) {
    r.pb(it);
  }

  printf("%d\n", sz(r));  
  for (auto it : r) {
    printf("%d %d\n", it.fst + 1, it.snd + 1);
  }
  
  return 0;
}