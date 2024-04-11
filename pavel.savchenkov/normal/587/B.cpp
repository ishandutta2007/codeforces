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
const int MOD = 1e9 + 7;

inline void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

inline int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

int n, k;
ll l;
vi a;

bool read() {
  if  (scanf("%d%I64d%d", &n, &l, &k) < 1) {
    return false;
  }
  a.resize(n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }
  return true;
}

int solve() {
  vi c;
  forn(i, n) c.pb(a[i]);
  sort(all(c));
  c.resize(unique(all(c)) - c.begin());
  forn(i, n) a[i] = lower_bound(all(c), a[i]) - c.begin();

  vvi dp1(k + 1, vi(sz(c), 0));
  forn(i, sz(c)) {
    dp1[0][i] = 1;
  }
  
  vvi dp2(k + 1, vi(n, 0));

  for (int have = 1; have <= k; ++have) {
    forn(i, n) {
      add(dp2[have][i], dp1[have - 1][a[i]]);
      add(dp1[have][a[i]], dp2[have][i]);
    }
    for (int i = 1; i < sz(c); ++i) {
      add(dp1[have][i], dp1[have][i - 1]);
    }
  }

  int ans = 0;
  for (int have = 1; have <= k; ++have) {
    forn(i, n) {
      ll rs = l / n;
      if  (i < (l % n)) {
        ++rs;
      }
      rs -= (have - 1);
      if  (rs < 0) {
        continue;
      }
      int coef = rs % MOD;
      add(ans, mul(coef, dp2[have][i]));
    }
  }

  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    printf("%d\n", solve());
  }

  return 0;
}