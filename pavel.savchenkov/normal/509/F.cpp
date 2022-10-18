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
const int MAXN = 500 + 10;
const int MOD = 1e9 + 7;

void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

int mpow(int a, int p) {
  int res = 1;
  for (; p > 0; p /= 2, a = mul(a, a))
    if  (p & 1) 
      res = mul(res, a);
    
  return res;
}

int dp_root[MAXN][MAXN];
int dp[MAXN][MAXN];
int b[MAXN];
int n;
int pow2[MAXN];

int calc_root(int, int);

int calc(int l, int r) {
  if  (l >= r) {
    return 1;
  }

  int& res = dp[l][r];

  if  (res != -1) {
    return res;
  }

  res = 0;
  for (int m = l; m <= r; ++m) {
    if  (m == r || b[m + 1] > b[l]) {
      add(res, mul(calc_root(l, m), calc(m + 1, r)));
    }
  }

  return res;
}

int calc_root(int l, int r) {
  if  (l == r) {
    return 1;
  }

  int& res = dp_root[l][r];
  
  if  (res != -1) {
    return res;
  }
  
  int cnt = 0;
  for (int i = l + 1; i <= r; ++i) {
    cnt += b[i] > b[l];
  }

  return res = mul(calc(l + 1, r), pow2[cnt]);
}

int ans;
int a[MAXN][MAXN];
bool used[MAXN];
vi B;


void dfs(int v) {
  used[v] = true;
  B.pb(v);
  forn(to, n) {
    if  (!used[to] && a[v][to] == 1) {
      dfs(to);
    }
  }
}

void gen(int i, int j) {
  ++j;
  if  (j == n) {
    ++i;
    j = 0;
  }

  while (i < n && i > j) {
    ++j;
    if  (j == n) {
      ++i;
      j = 0;
    }
  }

  if  (i == n) {
    B.clear();
    forn(z, n) used[z] = false;

    dfs(0);
    
    if  (sz(B) != n) return;

    forn(z, n) {
      if  (B[z] != b[z]) {
        return;
      }
    }
/*
    forn(z, n) {
      forn(k, n) {
        printf("%d", a[z][k]);
      }
      puts("");
    }
    puts("");
*/
    ++ans;
    return;
  }

  assert(i <= j);

//  printf("%d %d\n", i, j);

  a[i][j] = a[j][i] = 0;
  gen(i, j);

  if  (i == j) return;

  a[i][j] = a[j][i] = 1;
  gen(i, j);
}

int brut() {
  ans = 0;
  gen(-1, n - 1);
  return ans;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  memset (dp, -1, sizeof dp);
  memset (dp_root, -1, sizeof dp_root);

  pow2[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    pow2[i] = 1;//mul(pow2[i - 1], 2);
  }

  cin >> n;
  forn(i, n) {
    cin >> b[i];
    --b[i];
  }
/*
  forn(l, n)
    for (int r = l; r < n; ++r) {
      printf("dp[%d][%d] = %d\n", l, r, calc(l, r));
      printf("dp_root = %d\n\n", calc_root(l, r));
    }
*/
  cout << mul(calc_root(0, n - 1), mpow(pow2[n - 1], MOD - 2)) << endl;
//  printf("brut = %d\n", brut());
  return 0;
}