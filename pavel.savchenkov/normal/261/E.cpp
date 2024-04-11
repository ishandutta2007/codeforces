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
const int INF = 2e9;

vi primes;

inline bool prime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if  (x % i == 0) {
      return false;
    }
  }
  return true;
}

int vals[(int) 3e6];
int sz = 0;

void gen(int i, int x, int r) {
  if  (i == sz(primes)) {
    vals[sz++] = x;
    return;
  }

  while (1) {
    gen(i + 1, x, r);

    if  (primes[i] > r / x) {
      break;
    }

    x *= primes[i];
  }
}

int dp[2][(int) 3e6];
bool was[(int) 3e6];

int solve(int l, int r, int p) {
  gen(0, 1, r);

//  puts("generated");

  sort(vals, vals + sz);
  int ans = 0;
  memset (was, false, sizeof was);
    
  int c = 0;
  forn(i, sz) {
    dp[c][i] = INF;
  }
  dp[c][0] = 0;
  
  for (int x = 1; x <= p; ++x, c ^= 1) {
    int ax_id = 0;
    for (int a_id = 0; a_id < sz; ++a_id) {
      while (vals[ax_id] * x < vals[a_id]) ++ax_id;

      dp[c ^ 1][a_id] = dp[c][a_id] + 1;
      if  (vals[ax_id] * x == vals[a_id]) {
        dp[c ^ 1][a_id] = min(dp[c ^ 1][a_id], dp[c ^ 1][ax_id] + 1);
      }

      if  (dp[c ^ 1][a_id] <= p && !was[a_id] && l <= vals[a_id] && vals[a_id] <= r) {
        was[a_id] = true;
        ++ans;
      }
    }

//    forn(i, sz) dp[c][i] = INF;
    memset (dp[c], 0xfff, sizeof dp[c]);
  }

  return ans;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  for (int i = 2; i <= 100; ++i) {
    if  (prime(i)) {
      primes.pb(i);
    }
  }

  int l, r, p;
  cin >> l >> r >> p;

  printf("%d\n", solve(l, r, p));

  #ifdef LOCAL
    printf("Time = %.10f\n", (double) clock() / CLOCKS_PER_SEC);
  #endif
  return 0;
}