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
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

vi g[MAXN];
int n;

void addE(int a, int b) {
  g[a].pb(b);
  g[b].pb(a);
}         

int dp[2][MAXN];

void dfs1(int v, int p) {
  forn(i, 2) dp[i][v] = 1;

  for (int to : g[v]) {
    if  (to == p) {
      continue;
    }
    dfs1(to, v);
  
    int cur = dp[0][to];
    dp[0][v] = mul(dp[0][v], cur);

    cur = dp[0][to];
    add(cur, dp[1][to]);
    dp[1][v] = mul(dp[1][v], cur);
  }
}

int ans[MAXN];

void dfs(int v, int p, int up0, int up1) {
  ans[v] = up1;

  vi G;
  for (int to : g[v]) {
    if  (to != p) {
      G.pb(to);

      int cur = dp[1][to];
      add(cur, dp[0][to]);
      ans[v] = mul(ans[v], cur);

      add(dp[1][to], dp[0][to]);
    }
  }

  vvi pref_dp(2, vi(sz(G) + 1));
  vvi suff_dp(2, vi(sz(G) + 1));
  forn(c, 2) {
    pref_dp[c][0] = 1;
    forn(i, sz(G)) {
      int to = G[i];
      pref_dp[c][i + 1] = mul(pref_dp[c][i], dp[c][to]);
    } 

    suff_dp[c][sz(G)] = 1;
    ford(i, sz(G)) {
      int to = G[i];
      suff_dp[c][i] = mul(suff_dp[c][i + 1], dp[c][to]);
    }
  }

  forn(i, sz(G)) {
    int to = G[i];

    int nup0 = mul(up0, mul(pref_dp[0][i], suff_dp[0][i + 1]));
    int nup1 = mul(up1, mul(pref_dp[1][i], suff_dp[1][i + 1]));
    add(nup1, nup0);

    dfs(to, v, nup0, nup1);
  }
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d", &n);         
  forn(i, n - 1) {
    int p;
    scanf("%d", &p);
    addE(p - 1, i + 1);
  }

  dfs1(0, -1);
  dfs(0, -1, 1, 1);

  forn(v, n) printf("%d ", ans[v]);
  return 0;
}