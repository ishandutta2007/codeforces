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

#define FILE_NAME ""

const ld EPS = 1e-11;
const int MAXN = 1e5 + 10;

vi g[MAXN];
bool can[MAXN];
int n, m, k;

struct cmp {
  bool operator()(const pair<ld, int>& p1, const pair<ld, int>& p2) {
    if  (fabs(p1.fst - p2.fst) < EPS) {
      return p1.snd < p2.snd;
    } 
    return p1.fst < p2.fst;
  }
};

set<pair<ld, int>, cmp> S;

ld val[MAXN];
bool in[MAXN];

void turn_on(int v) {
  if  (in[v]) {
    return;
  }
  val[v] = 0;
  in[v] = true;
//  printf("turn on %d\n", v);
  for (int to : g[v]) {
    if  (!in[to]) {
      continue;  
    }
    assert(in[to]);
    assert(can[to]);
    assert(to != v);
    /*
    puts("S:");
    for (auto it : S) {
      printf("%.5f %d\n", (double) it.fst, it.snd);
    }
    printf("val[%d]=%.5f\n", to, (double) val[to]);
    */
    S.erase(mp(val[to], to));
    val[to] += 1.0 / sz(g[to]);
    S.insert(mp(val[to], to));
    val[v] += 1;
  } 
  val[v] /= sz(g[v]);
  S.insert(mp(val[v], v));
//  printf("sz(S) = %d\n", sz(S));
}

void turn_off(int v) {
  if  (!in[v]) {
    return;   
  }
  in[v] = false;
//  printf("turn off %d\n", v);
//  printf("before sz=%d\n", sz(S));
  assert(S.erase(mp(val[v], v)));
  for (int to : g[v]) {
    if  (!in[to]) {
      continue;
    }
    assert(can[to]);
    assert(to != v);
    S.erase(mp(val[to], to));
    val[to] -= 1.0 / sz(g[to]);
    S.insert(mp(val[to], to));
  }
//  printf("after sz=%d\n", sz(S));
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  memset (can, true, sizeof can);
  cin >> n >> m >> k;
  forn(i, k) {
    int v;
    scanf("%d", &v);
    --v;
    can[v] = false;
  }
  forn(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].pb(b);
    g[b].pb(a);
  }

  ld mx = 0;
  memset (in, false, sizeof in);
  forn(v, n) {
    if  (can[v]) {
      turn_on(v);
    }
  }

  forn(it, n - k) {
//    printf("sz = %d\n", sz(S));
    assert(!S.empty());
    auto mn = *S.begin();
    int v = mn.snd;
    mx = fmax(mx, mn.fst);
    assert(in[v]);
    turn_off(v);
//    printf("mn = %.10f\n", (double) mn.fst);
  }

//  return 0;

  assert(S.empty());

  forn(v, n) {
    if  (can[v]) {
      turn_on(v);
    }
  }

  forn(it, n - k) {
    auto mn = *S.begin();
    int v = mn.snd;
    if  (fabs(mx - mn.fst) < EPS) {
      break;
    }
    turn_off(v);
//    printf("mn = %.10f\n", (double) mn.fst);
  }

  vi ans;
  forn(v, n) if  (in[v]) ans.pb(v);

  printf("%d\n", sz(ans));
  for (int v : ans) {
    printf("%d ", v + 1);
  }
  puts("");


  return 0;
}