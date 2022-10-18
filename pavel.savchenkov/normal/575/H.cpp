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
const int MAXN = 2e6 + 10;

inline void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

inline int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

inline int mpow(int x, int p) {
  int res = 1;
  for (; p > 0; p >>= 1, x = mul(x, x))
    if  (p & 1)
      res = mul(res, x);
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

int main() {
#ifdef LOCAL
//  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  precalc();

  int n;
  cin >> n;

  int ans = 1;
  int prev = 1;
  for (int de = 1; de <= 2 * n; ++de) {
    int cur = mul(prev, 2);
    if  (de - 1 >= n) {
      add(cur, -C(de - 1, n) + MOD);
      add(cur, -C(de - 1, n) + MOD);
    } 
    add(ans, cur);
    prev = cur;
//    printf("de=%d, cur=%d\n", de, cur);
  }

  cout << ans << endl;

//  cout << C(4, 2) << endl;

  return 0;
}