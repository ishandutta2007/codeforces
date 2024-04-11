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
const int MAXN = 50 + 10;

ll dp[2][MAXN][MAXN]; // taken, sum -> cnt ways

int n;
vi a;
int p;

ll C[MAXN][MAXN];

long double brut() {
  long double sum = 0;
  int cnt = 0;
  
  vi P(sz(a));
  forn(i, sz(a)) {
    P[i] = i;
  }

  do {
    int s = 0;
    forn(i, sz(a)) {
      s += a[P[i]];
      if  (s > p) {
        sum += i;
        break;
      }
    }
    if  (s <= p) {
      sum += n;
    }
    ++cnt;
  } while (next_permutation(all(P)));

  return sum / cnt;
}

long double solve() {
  long double ans = 0;
  forn(j, sz(a)) {
    memset (dp, 0, sizeof dp);
    int c = 0;
    dp[c][0][0] = 1ll;
    for (int i = 0; i < n; ++i, c ^= 1) {
      for (int s = 0; s <= p; ++s) {
        for (int taken = 0; taken <= i; ++taken) {
          if  (i != j && s + a[i] <= p) {
            dp[c ^ 1][s + a[i]][taken + 1] += dp[c][s][taken];
          }
          dp[c ^ 1][s][taken] += dp[c][s][taken];
        }
      }

      memset (dp[c], 0, sizeof dp[c]);
    }
/*
    printf("j = %d, a[j] = %d\n", j, a[j]);
    for (int taken = 0; taken < n; ++taken) {
      for (int s = 0; s <= p; ++s) {
        printf("dp[taken=%d][sum=%d] = %I64d\n", taken, s, dp[c][s][taken]);
      }
    }
*/

    for (int cnt = 0; cnt < n; ++cnt) {
      for (int sum = max(0, p - a[j] + 1); sum <= p; ++sum) {
        assert(sum + a[j] > p);
        long double coef = 1.0 / n;
        coef *= (long double) dp[c][sum][cnt] / C[n - 1][cnt];
//        printf("cnt=%d, sum=%d, coef=%.5f\n", cnt, sum, (double) coef);
        ans += cnt * coef;
      }
    }
  }

  int S = 0;
  forn(i, n) {
    S += a[i];
  }

  if  (S <= p) {
    return n;
  }

  return ans;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  C[0][0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    C[i][0] = 1;
    for (int j = 1; j < MAXN; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  scanf("%d", &n);
  a = vi(n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &p);

  printf("%.10f\n", (double) solve());
  return 0;

  while (1) {
    n = rand() % 10 + 1;
    a = vi(n);
    forn(i, n) {
      a[i] = rand() % 50 + 1;
    }
    p = rand() % 50 + 1;

    long double my = solve();
    long double b = brut();
    if  (fabs(my - b) < EPS) {
      printf("OK n=%d\n", n);
    } else {
      forn(i, n) {
        printf("%d ", a[i]);
      }
      printf("\n%d\n", p);
      printf("my=%.10f, b=%.10f\n", (double) my, (double) b);
      return 0;
    }
  }

  return 0;
}