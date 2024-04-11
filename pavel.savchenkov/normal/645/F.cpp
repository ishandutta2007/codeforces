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
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

inline void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

inline int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

inline int mpow(int a, int p) {
  int res = 1;
  for (; p; p >>= 1, a = mul(a, a))
    if  (p & 1)
      res = mul(res, a);
  return res;
}

int fact[MAXN];
int inv_fact[MAXN];

vi primes;
bool pr[MAXN];
vi divs[MAXN];

void precalc() {
  memset (pr, true, sizeof pr);
  for (int i = 2; i < MAXN; ++i) {
    if  (pr[i]) {
      primes.pb(i);
      for (int j = i + i; j < MAXN; j += i) {
        pr[j] = false;
      }
    }
  }

  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fact[i] = mul(i, fact[i - 1]);
  }

  forn(i, MAXN) {
    inv_fact[i] = mpow(fact[i], MOD - 2);
  }

  for (int i = 1; i < MAXN; ++i) {
    for (int j = i; j < MAXN; j += i) {
      divs[j].pb(i);
    }
  }
}

inline int C(int n, int k) {
  if  (n < k) return 0;
  return mul(fact[n], mul(inv_fact[n - k], inv_fact[k]));
}

int a[MAXN];
int n, k, q;
int cnt_up[MAXN];
int ans[MAXN];
int cnt[MAXN];
int sum;

bool read() {
  if  (scanf("%d%d%d", &n, &k, &q) < 3) {
    return false;
  } 
  forn(i, n) {
    scanf("%d", &a[i]);
  }
  return true;
}            

int exact[MAXN];

void insert(int x) {
  const vi& ds = divs[x];
  for (int d : ds) exact[d] = 0;
  ford(i, sz(ds)) {
    int d = ds[i];
    exact[d] = (exact[d] % MOD + MOD) % MOD;
    add(exact[d], C(cnt_up[d], k - 1));
    forn(j, sz(divs[d]) - 1) {
      int dd = divs[d][j];
    //  exact[dd] -= exact[d];
      add(exact[dd], -exact[d] + MOD);
    }
    ++cnt_up[d];
    ++cnt[d];
    add(ans[d], exact[d]);
    add(sum, mul(exact[d], d));
  }
}

int get_worst() {
  int mx = 0;
  int X = -1;
  for (int x = 1; x < MAXN; ++x) {
    int cnt = 0;
    forn(i, sz(divs[x])) {
      cnt += sz(divs[divs[x][i]]);
    }
    if  (cnt > mx) {
      mx = cnt;
      X = x;
    }
  }
  cerr << "mx = " << mx << endl;
  return X;
}

void solve() {
  memset (cnt, 0, sizeof cnt);
  memset (cnt_up, 0, sizeof cnt_up);
  forn(i, n) ++cnt[a[i]];
  
  for (int g = MAXN - 1; g > 0; --g) {
    cnt_up[g] = cnt[g];
    for (int j = g + g; j < MAXN; j += g) {
      cnt_up[g] += cnt[j];
    }
    ans[g] = C(cnt_up[g], k);
    for (int j = g + g; j < MAXN; j += g) {
      add(ans[g], -ans[j] + MOD);
    }
  }

  sum = 0;
  forn(g, MAXN) {
    add(sum, mul(g, ans[g]));
  }

  forn(it, q) {
    int c;
    scanf("%d", &c);
    insert(c);
    printf("%d\n", sum);
  }
}               

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  precalc();

//  get_worst();

  while (read()) {
    solve();
  }

  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
  return 0;
}