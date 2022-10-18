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

int n, m, mod;

inline void add(int& x, int y) {
  if  ((x += y) >= mod)
    x -= mod;
}

inline int mul(int x, int y) {
  return x * 1ll * y % mod;
}

char s[600][600];
int dp[2][600][600];
int prec[600];

inline int C2(int x) {
  if  (x <= 1)
    return 0;

  return prec[x];
}

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  cin >> n >> m >> mod;
  scanf("\n");

  for (int i = 2; i <= n; ++i) {
    prec[i] = 0;
    for (int j = 0; j < i; ++j) {
      add(prec[i], i - j - 1);
    }
  }

  vi cnt(n, 0);
  forn(i, m) {
    gets(s[i]);
    forn(j, n) {
      cnt[j] += s[i][j] == '1';
    }
  }

  sort(all(cnt));

  while (!cnt.empty() && cnt.back() == 2) cnt.pop_back();

  if  (cnt.empty()) {
    printf("%d\n", 1 % mod);
    return 0;
  }

  memset (dp, 0, sizeof dp);
  int c = 0;
  dp[c][n - m][0] = 1;
  for (int i = 0; i < sz(cnt); ++i, c ^= 1) {
    memset (dp[c ^ 1], 0, sizeof dp[c ^ 1]);

    add(dp[c ^ 1][0][0], dp[c][0][0]);

    for (int cnt0 = 0; cnt0 <= n - m; ++cnt0)
      for (int cnt1 = 0; cnt1 + cnt0 <= n - m; ++cnt1) {
        if  (!dp[c][cnt0][cnt1]) {
          continue;
        }

        if  (cnt[i] == 0) {
          // both 1
          if  (cnt1 >= 2)
            add(dp[c ^ 1][cnt0][cnt1 - 2], mul(C2(cnt1), dp[c][cnt0][cnt1]));

          // 1, 0
          if  (cnt0 && cnt1)
            add(dp[c ^ 1][cnt0 - 1][cnt1], mul(mul(cnt1, cnt0), dp[c][cnt0][cnt1]));

          // 0, 0
          if  (cnt0 >= 2)
            add(dp[c ^ 1][cnt0 - 2][cnt1 + 2], mul(C2(cnt0), dp[c][cnt0][cnt1]));
        } else {
          // 0
          if  (cnt0)
            add(dp[c ^ 1][cnt0 - 1][cnt1 + 1], mul(cnt0, dp[c][cnt0][cnt1]));

          // 1
          if  (cnt1)
            add(dp[c ^ 1][cnt0][cnt1 - 1], mul(cnt1, dp[c][cnt0][cnt1]));
        }
      } 
  }

  printf("%d\n", dp[c][0][0] % mod);

//  printf("%.10f\n", (double) clock() / CLOCKS_PER_SEC);
  return 0;
}