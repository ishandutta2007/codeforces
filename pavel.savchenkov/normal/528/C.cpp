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
#include <complex>
#include <bitset>

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
#define hash kjfdkljkdhgjdkfhgurehg
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
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

const double EPS = 1e-9;
const int MAXN = 2e5 + 10;

vi g[MAXN];
vii ans;
int n, m;
int in[MAXN];
int out[MAXN];
bool was[MAXN];
int tin[MAXN];
int timer;
int deg[MAXN];

void addE(int a, int b) {
  g[a].pb(b);
  if  (a != b) {
    g[b].pb(a);
  }
  ++deg[a];
  ++deg[b];
}

void put(int v, int to) {
//  printf("%d -> %d\n", v + 1, to + 1);
  out[v]++;
  in[to]++;
  ans.pb(mp(v, to));
}

void dfs(int v, int par) {
//  printf("in %d\n", v + 1);

  tin[v] = timer++;
  was[v] = true;

  bool was_par = false;
  for (int to : g[v]) {
    if  (to == par && !was_par) {
      was_par = true;
      continue;  
    } 

    if  (!was[to]) {
      dfs(to, v);
      continue;
    }

    if  (tin[to] <= tin[v]) {
      put(v, to);
    }
  }

  if  (par == -1) {
    if  (in[v] % 2 == 1) {
      assert(out[v] % 2 == 1);
      put(v, v);
    }
  } else {
    assert((in[v] + out[v]) % 2 == 1);

    if  (in[v] & 1) {
      put(par, v);
    } else {
      put(v, par);
    }
  }
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  forn(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;

    addE(a, b);
  }

  vi odd;
  forn(v, n) {
    if  (deg[v] & 1) {
      odd.pb(v);
    }
  }

  assert(sz(odd) % 2 == 0);

  for (int i = 0; i < sz(odd); i += 2) {
    addE(odd[i], odd[i + 1]);
  }

  timer = 0;
  dfs(0, -1);

  printf("%d\n", sz(ans));
  forn(i, sz(ans)) {
    printf("%d %d\n", ans[i].fst + 1, ans[i].snd + 1);
  }

  return 0;
}