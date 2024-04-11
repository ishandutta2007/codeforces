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
const int MAXN = 1e5 + 10;

struct DSU {
  vi who;
  vi par;
  vi Sz;

  DSU() {}

  void push(int v) {
    who.pb(v);
  }

  void init() {
    sort(all(who));
    who.resize(unique(all(who)) - who.begin());
    par.assign(sz(who), 0);
    forn(i, sz(par)) par[i] = i;
    Sz.assign(sz(who), 1);
  }

  int id(int x) {
    return lower_bound(all(who), x) - who.begin();
  }

  int get_set_public(int x) {
    return get_set(id(x));
  }

  int get_set(int x) {
    return par[x] == x ? x : par[x] = get_set(par[x]); 
  }

  bool union_set_public(int x, int y) {
    return union_set(id(x), id(y));
  }

  bool union_set(int x, int y) {
    x = get_set(x);
    y = get_set(y);

    if  (x == y) return false;

    if  (Sz[x] > Sz[y]) swap(x, y);

    Sz[y] += Sz[x];
    par[x] = y;
    return true;
  }
};

DSU dsu[MAXN];
vii g[MAXN];
int n, m;

vi ids[MAXN];
vi colors[MAXN];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> m;
  forn(i, m) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    --c;

    g[a].pb(mp(b, c));
    g[b].pb(mp(a, c));

    dsu[c].push(a);
    dsu[c].push(b);

    colors[a].pb(c);
    colors[b].pb(c);
  }             

  forn(c, m) {
    dsu[c].init();
  }

  forn(v, n) {
    sort(all(colors[v]));
    colors[v].resize(unique(all(colors[v])) - colors[v].begin());
  }

  forn(v, n) {
    for (int c : colors[v]) {
      ids[v].pb(dsu[c].id(v));  
    }
  }

  forn(v, n) {
    for (auto& it : g[v]) {
      int to = it.fst;
      int c = it.snd;

      dsu[c].union_set_public(to, v);
    }
  }

  int q;
  scanf("%d", &q);

  map<pii, int> ans;

  forn(i, q) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;

    if  (ans.count(mp(a, b))) {
      printf("%d\n", ans[mp(a, b)]);
      continue;
    }

    if  (sz(colors[a]) > sz(colors[b])) {
      swap(a, b);
    }

    int res = 0;
    forn(i, sz(colors[a])) {
      int c = colors[a][i];

      int pos_b = lower_bound(all(colors[b]), c) - colors[b].begin();

      if  (pos_b < sz(colors[b]) && colors[b][pos_b] == c) {
        res += dsu[c].get_set(ids[a][i]) == dsu[c].get_set(ids[b][pos_b]);
      } 
    }

    ans[mp(a, b)] = ans[mp(b, a)] = res;

    printf("%d\n", res);
  }

  return 0;
}