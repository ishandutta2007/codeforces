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
const int MOD = 1e9 + 7;

void add(int& x, int y) {
  if  ((x += y) >= MOD)
    x -= MOD;
}

int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

vi g[MAXN];
int n;
int dp[MAXN][2][2];

void dfs(int v) {
  sort(g[v].begin(), g[v].end());

  for (int to : g[v]) {
    dfs(to);
  }

  forn(C1, 2) {
    forn(C2, 2) {
      int d[2][2];
      int nd[2][2];
      memset (d, 0, sizeof d);
      for (int to : g[v]) {
        memset (nd, 0, sizeof nd);

        // do not take
        forn(c1, 2) forn(c2, 2) nd[c1][c2] = d[c1][c2];

        // take and we are not first
        forn(c1, 2) forn(c2, 2) {
          add(nd[c1][c2], mul(d[c2][c1], dp[to][c1][c2]));
        } 
        
        // we are first
        add(nd[C1][C2], dp[to][C1][C2]);

        swap(d, nd);
      }

//      forn(c1, 2) forn(c2, 2) printf("v = %d, c1 = %d, c2 = %d, d = %d\n", v, c1, c2, d[c1][c2]);
      // d[c1][c2] -- in two directions

      int d_up[2];
      int nd_up[2];
      memset (d_up, 0, sizeof d_up);
      for (int to : g[v]) {
        memset (nd_up, 0, sizeof nd_up);

        // do not take
        forn(c, 2) nd_up[c] = d_up[c];

        // take, we are not first
        forn(c1, 2) forn(c2, 2) add(nd_up[c2], mul(d_up[c1], dp[to][c1][c2]));

        // take, we are first
        forn(c2, 2) add(nd_up[c2], dp[to][C1][c2]); 

        swap(d_up, nd_up);
      } 

      int d_down[2];
      int nd_down[2];
      memset (d_down, 0, sizeof d_down);
      for (int i = sz(g[v]) - 1; i >= 0; --i) {
        int to = g[v][i];

        memset (nd_down, 0, sizeof nd_down);

        // do not take
        forn(c, 2) nd_down[c] = d_down[c];

        // take, we are not first
        forn(c1, 2) forn(c2, 2) add(nd_down[c2], mul(d_down[c1], dp[to][c1][c2]));

        // take, we are first
        forn(c2, 2) add(nd_down[c2], dp[to][C1][c2]); 

        swap(d_down, nd_down);
      }

      dp[v][C1 ^ 1][C2] = 0;
      add(dp[v][C1 ^ 1][C2], d_up[C2]);
      add(dp[v][C1 ^ 1][C2], d_down[C2]);

      add(dp[v][C1 ^ 1][C2], - d[0][C2] + MOD);
      add(dp[v][C1 ^ 1][C2], - d[1][C2] + MOD);
    }
  }

  add(dp[v][0][1], 1);
  add(dp[v][1][0], 1);
/*
  forn(C1, 2) {
    forn(C2, 2) {
      printf("dp[%d][%d][%d] = %d\n", v, C1, C2, dp[v][C1][C2]);
    }
  }
*/
}

int main() {    
  scanf("%d", &n);
  forn(i, n - 1) {
    int par;
    scanf("%d", &par);
    --par;
    g[par].pb(i + 1);
  }

  dfs(0);

  int ans = 0;
  add(ans, dp[0][0][0]);
  add(ans, dp[0][0][1]);
  printf("%d\n", ans);
  return 0;
}