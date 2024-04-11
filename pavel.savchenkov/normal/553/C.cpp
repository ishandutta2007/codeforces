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

const ld EPS = 1e-9;
const int MAXN = 1e5 + 10;

vii g[MAXN];
int n, m;
bool was[MAXN];
int pref[MAXN];
int depth[MAXN];

void dfs(int v, int p = -1) {
//  printf("in %d, pref=%d, de=%d\n", v + 1, pref[v], depth[v]);
  was[v] = true;
  for (auto e : g[v]) {
    int to, c;
    tie(to, c) = e;
    if  (to == p) {
      continue;
    }
    if  (was[to]) {
      int even = (depth[v] - depth[to]) % 2 == 0;
      int sum = pref[v] ^ pref[to];
//      printf("v=%d, to=%d, even=%d, sum=%d\n", v + 1, to + 1, even, sum);
      if  ((even && c != (sum ^ 1)) || (!even && c != sum)) {
        puts("0");
        exit(0);
      } 
      continue;
    }
    pref[to] = pref[v] ^ c;
    depth[to] = depth[v] + 1;
    dfs(to, v);
  }
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  cin >> n >> m;
  forn(i, m) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    g[a].pb(mp(b, c));
    g[b].pb(mp(a, c));
  }

  int comps = 0;
  forn(v, n) {
    if  (!was[v]) {
      depth[v] = 0;
      pref[v] = 0;
      dfs(v);
      ++comps;
    }
  }

  const int MOD = 1e9 + 7;
  int ans = 1;
  forn(i, comps - 1) {
    ans = (ans * 2) % MOD;
  }
  cout << ans << endl;

  return 0;
}