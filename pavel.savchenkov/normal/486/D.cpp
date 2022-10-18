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
const int MAXN = 2000 + 5;
const int MOD = 1e9 + 7;

int add(int x, int y) {
  if  ((x += y) >= MOD) {
    x -= MOD;
  }
  return x;
}

int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

vi g[MAXN];
int n, d;
int a[MAXN];

int dfs(int v, int par, int a_root, int root) {
  if  (a[v] < a_root || a[v] > a_root + d || (a[v] == a_root && v < root)) {
    return 1;
  }

  int res = 1;
  for (int to : g[v]) {
    if  (to != par) {
      res = mul(res, dfs(to, v, a_root, root));
    } 
  }

//  printf("dfs(%d) = %d\n", v, add(res, 1));
  return add(res, 1);
}

int solve(int root) {
  return dfs(root, -1, a[root], root);
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

  scanf("%d%d", &d, &n);
  
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  forn(i, n - 1) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;

    g[v].pb(u);
    g[u].pb(v);
  }

  int ans = 0;
  forn(i, n) {
    ans = add(ans, solve(i));
    ans = add(ans, -1 + MOD);
  }

  cout << ans << endl;
	return 0;
}