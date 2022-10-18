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
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const int MAXN = 3e5 + 10;
const int MOD = 1e9 + 7;

inline void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

inline int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

int mpow(int a, int p) {
  int res = 1;
  for (; p > 0; p >>= 1, a = mul(a, a))
    if  (p & 1)
      res = mul(res, a);
  return res;
}

vi primes;                   
bool pr[MAXN];

int fact[MAXN];
int inv_fact[MAXN];

int pow2[MAXN];

void precalc() {
  memset (pr, 1, sizeof pr);
  for (int i = 2; i < MAXN; ++i) {
    if  (pr[i]) {
      for (int j = i + i; j < MAXN; j += i) {
        pr[j] = false;
      }
      primes.pb(i);
    }
  }

  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fact[i] = mul(i, fact[i - 1]);
  }

  forn(i, MAXN) {
    inv_fact[i] = mpow(fact[i], MOD - 2);
  }

  pow2[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    pow2[i] = mul(pow2[i - 1], 2);
  }
}

int C(int n, int k) {
  if  (n < k) return 0;
  return mul(fact[n], mul(inv_fact[n - k], inv_fact[k]));
}

int cnt[MAXN];
int n;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return false;
  }
  memset (cnt, 0, sizeof cnt);
  forn(i, n) {
    int t;
    scanf("%d", &t);
    ++cnt[t];
  }
  return true;
}

int get_deg(int x, int p) {
  int d = 0;
  while (x % p == 0) x /= p, ++d;
  return d;
}

int c[20];
int sum_c[20];

int get_sum_c(int l, int r) {
  if  (l > r) return 0;
  return sum_c[r + 1] - sum_c[l];
}

void prec(int* s, int n) {
  s[0] = 0;
  forn(i, n + 1) {
    s[i + 1] = s[i];
    add(s[i + 1], C(n, i));
  }
}

int get_sum(int* s, int l, int r) {
  if  (l > r) return 0;
  int res = s[r + 1];
  add(res, -s[l] + MOD);
  return res;
}

int calc(int) {
  int m = 0;
  forn(i, 20) {
    if  (c[i]) m = i + 1;
  } 

  if  (!m) {
    return 0;
  }

  /*
  printf("calc p=%d:\n", p);
  forn(i, m) {
    printf("%d ", c[i]);
  }
  puts("");
  */

  sum_c[0] = 0;
  forn(i, m) {
    sum_c[i + 1] = sum_c[i] + c[i];
  }

  int ans = 0;
  forn(i, m) {
    int have_left = get_sum_c(0, i - 1);
    int have_right = get_sum_c(i, m - 1);
    if (!have_left) continue;
    int all_left = pow2[have_left];
    add(all_left, -1 + MOD);
    int all_right = pow2[have_right];
    add(all_right, -1 + MOD);
//    printf("left=%d, right=%d\n", have_left, have_right);
    for (int mn = 1; mn <= have_left && mn <= have_right; ++mn) {
      int cnt = 0;
      int mn_left = C(have_left, mn);
      int mn_right = C(have_right, mn);
      add(all_left, -mn_left + MOD);
      add(all_right, -mn_right + MOD); 
      add(cnt, mul(mn_left, mn_right));
      add(cnt, mul(all_left, mn_right));
      add(cnt, mul(mn_left, all_right));
      add(ans, mul(mn, cnt));
    }
  }

//  printf("cur = %d\n", ans);
  return ans;
}

int solve() {
  int ans = 0;
  for (int p : primes) {
    memset (c, 0, sizeof c);
    for (int x = p; x < MAXN; x += p) {
      c[get_deg(x, p)] += cnt[x];
    }
    c[0] = n;
    for (int i = 1; i < 20; ++i) {
      c[0] -= c[i];
    }
    add(ans, calc(p));
  }
  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  //freopen(FILE_NAME ".out", "w", stdout);
#endif

  precalc();

  while (read()) {
    printf("%d\n", solve());
  }

#ifdef DEBUG
  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}