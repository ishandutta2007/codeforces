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
const int MAXN = 3e4 + 10;

int cnt[MAXN];
int n, d;
int mn[MAXN];
int mx[MAXN];
vi dp[MAXN];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> d;
  forn(i, n) {
    int p;
    scanf("%d", &p);
    ++cnt[p];
  }

  forn(i, MAXN) {
    mn[i] = (int) 1e9;
    mx[i] = -1;
  }

  mn[d] = mx[d] = d;
  for (int i = d; i < MAXN; ++i) {
    for (int j = mx[i] - 1; j <= mx[i] + 1; ++j) {
      if  (i + j < MAXN && j > 0) {
        mx[i + j] = max(mx[i + j], j);
      }
    }

    for (int j = mn[i] - 1; j <= mn[i] + 1; ++j) {
      if  (i + j < MAXN && j > 0) {
        mn[i + j] = min(mn[i + j], j);
      }
    }
  }

  for (int i = d; i < MAXN; ++i) {
    if  (mx[i] != -1) dp[i].assign(mx[i] - mn[i] + 1, 0);
  }

  dp[d][0] = cnt[d];
  for (int i = d; i < MAXN; ++i) {
    if  (mx[i] == -1) continue;

    for (int j = mn[i]; j <= mx[i]; ++j) {
      for (int jj = j - 1; jj <= j + 1; ++jj) {
        if  (jj > 0 && i + jj < MAXN) {
          dp[i + jj][jj - mn[i + jj]] = max(dp[i + jj][jj - mn[i + jj]], dp[i][j - mn[i]] + cnt[i + jj]);
        }
      }
    }
  }

  int ans = 0;
  forn(i, MAXN) forn(j, sz(dp[i])) ans = max(ans, dp[i][j]);

  printf("%d\n", ans);
  return 0;
}