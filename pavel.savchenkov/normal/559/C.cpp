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
const int MOD = 1e9 + 7;
const int MAXN = 4e5 + 10;

inline void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

inline int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

inline int mpow(int a, int p) {
  int res = 1;
  for (; p > 0; p /= 2, a = mul(a, a))
    if  (p & 1)
      res = mul(res, a);
  return res;
}

int fact[MAXN];
int inv_fact[MAXN];

void precalc() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fact[i] = mul(i, fact[i - 1]);
  } 

  forn(i, MAXN) {
    inv_fact[i] = mpow(fact[i], MOD - 2); 
  } 
}

inline int C(int n, int k) {
  return mul(fact[n], mul(inv_fact[k], inv_fact[n - k]));
}

inline int CC(int n, int k) {
  return C(n + k - 1, k);
}

inline int ways(int n, int m) {
  return CC(m, n - 1);
}

int dp[3000][2];
int h, w, n;
vii ps;

bool read() {
  if  (scanf("%d%d%d", &h, &w, &n) < 3) {
    return false;
  }
  forn(k, n) {
    int i, j;
    scanf("%d%d", &i, &j);
    --i;
    --j;
    ps.pb(mp(i, j));
  }
  return true;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  precalc();

  assert(read());

  sort(all(ps), [](const pii& a, const pii& b) { return mp(a.snd, a.fst) < mp(b.snd, b.fst); });

  forn(i, n) {
    int r = ps[i].fst;
    int c = ps[i].snd;
    forn(j, i) {
      int pr = ps[j].fst;
      int pc = ps[j].snd;
      assert(c >= pc);
      if  (pr > r) {
        continue;
      }
      forn(par, 2) {
        add(dp[i][par ^ 1], mul(dp[j][par], ways(r - pr + 1, c - pc + 1)));
      }
    }
    add(dp[i][1], ways(r + 1, c + 1));
  }

  int ans = ways(h, w);
  forn(i, n) forn(par, 2) {
    int r = ps[i].fst;
    int c = ps[i].snd;
    int coef = mul(dp[i][par], ways(h - 1 - r + 1, w - 1 - c + 1));
    if  (!par) {
      add(ans, coef);
    } else {
      add(ans, -coef + MOD);
    }
  }

  cout << ans << '\n';
  return 0;
}