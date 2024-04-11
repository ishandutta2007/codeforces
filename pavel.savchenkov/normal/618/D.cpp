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
#include <fstream>
#include <unordered_map>
#include <unordered_set>

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

int dp[MAXN][2];
vi g[MAXN];
int n, x, y;

bool read() {
  if  (scanf("%d%d%d", &n, &x, &y) < 1) {
    return false;
  }
  forn(i, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  return true;
}

void dfs(int v, int p) {
  int sum = 0;
  for (int to : g[v]) {
    if  (to == p) {
      continue;
    }
    dfs(to, v);
    int cur = max(dp[to][0], dp[to][1]);
    sum += cur;
  }

  dp[v][1] = sum;
  for (int to : g[v]) {
    if  (to == p) {
      continue;
    }
    int cur = max(dp[to][0], dp[to][1]);
    int other = sum - cur;
    dp[v][1] = max(dp[v][1], dp[to][1] + 1 + other);
  }

  dp[v][0] = max(sum, dp[v][1]);
  int mx1 = -n;
  int mx2 = -n;
  int sons = 0;
  for (int to : g[v]) {
    if  (to == p) {
      continue;
    }
    ++sons;
    int cur = dp[to][1] + 1 - max(dp[to][0], dp[to][1]);
    if  (cur > mx1) {
      mx2 = mx1;
      mx1 = cur;
    } else if  (cur > mx2) {
      mx2 = cur;
    }
  }

  if  (mx1 == -n) return;
  
  if  (mx2 == -n) {
    dp[v][0] = max(dp[v][0], mx1 + sum);
    return;
  }

  dp[v][0] = max(dp[v][0], mx1 + mx2 + sum);
}

ll solve() {
  if  (n == 2) {
    return x;
  }

  if  (n == 3) {
    return min(x + x, y + x);
  }

  if  (x >= y) {
    int leafs = 0;
    forn(i, n) {
      leafs += sz(g[i]) == 1;
    }
    if  (leafs == n - 1) {
      return x + y * 1ll * (n - 2);
    }
    return y * 1ll * (n - 1);  
  }

  dfs(0, -1);
  int cntx = max(dp[0][0], dp[0][1]);
//  printf("cntx = %d\n", cntx);
  return x * 1ll * cntx + y * 1ll * (n - 1 - cntx);
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    cout << solve() << '\n';
  }

  return 0;
}