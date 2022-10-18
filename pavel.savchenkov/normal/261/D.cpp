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
const int INF = 1e9;

struct Mass {
  int a[(int) 3e7 + 10 + (int) 1e5];
  int base;                   

  Mass() {
    forn(i, (int) 3e7 + 10 + 1e5) {
      a[i] = INF;
    }
  }

  Mass(int base) : base(base) {}

  int* operator [](int i) {
    return a + i * base;
  }
};

int calc_maxb(int n) {
  return (2e7 + n - 1) / n;
}

int n, maxb, t;

int b[(int) 2e5];
int first[(int) 2e5];
Mass next;
Mass dp;

int solve() {
  int max_len = min(n, maxb);

  for (int x = 1; x <= maxb; ++x) {
    first[x] = -1;
  }
  forn(i, n) {
    if  (first[b[i]] == -1) {
      first[b[i]] = i;
    }
  }
/*
  for (int x = 1; x <= maxb; ++x) {
    printf("first[%d] = %d\n", x, first[x]);
  }
  puts("");
*/
  for (int x = 1; x <= maxb; ++x) {
    next[n][x] = -1;
  }
  ford(i, n) {
    for (int x = 1; x <= maxb; ++x) {
      next[i][x] = next[i + 1][x];
    }
    if  (i < n - 1) {
      next[i][b[i + 1]] = i + 1;
    }
  }

  // len = 1
  for (int last = 1; last <= maxb; ++last) {
    dp[1][last] = dp[1][last - 1];
    if  (first[last] != -1) {
      dp[1][last] = min(dp[1][last], first[last]);
    }
//    printf("dp[%d][%d] = %d\n", 1, last, dp[1][last]);
  }

  for (int len = 2; len <= max_len; ++len) {
    for (int last = 2; last <= maxb; ++last) {
      dp[len][last] = dp[len][last - 1];

      if  (first[last] == -1) {
        continue;
      }

      int prev = dp[len - 1][last - 1];
      int real_prev = prev % n;
      if  (next[real_prev][last] != -1) {
        dp[len][last] = min(dp[len][last], (prev / n) * n + next[real_prev][last]);
      } else {
        dp[len][last] = min(dp[len][last], (1 + (prev / n)) * n + first[last]);
      } 

//      printf("dp[%d][%d] = %d\n", len, last, dp[len][last]);
    } 
  }

  int ans = 0;
  ll L = n * 1ll * t - 1;
  for (int len = 1; len <= max_len; ++len) {
    for (int last = 1; last <= maxb; ++last) {
      if  (dp[len][last] < INF && dp[len][last] <= L) {
        ans = max(ans, len);
      }
    }
  }

  return ans;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  int k;
  cin >> k >> n >> maxb >> t;

  next = Mass(maxb + 2);
  dp = Mass(maxb + 2);

  forn(it, k) {
    forn(i, n) {
      scanf("%d", &b[i]);
    } 
    printf("%d\n", solve());
  }

  return 0;
}