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
const int MOD = 1e9 + 7;
const int MAXN = 1000;

void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

int C[MAXN][MAXN];

int cnt[10];

int solve(int len) {
  vi dp(len + 1, 0);
  dp[0] = 1;
  forn(d, 10) {
    vi ndp(len + 1, 0);
    for (int have = 0; have < sz(dp); ++have) {
      for (int take = max(0, cnt[d]); take + have < sz(ndp); ++take) {
        add(ndp[have + take], mul(C[have + take][take], dp[have]));
      }
    }

    dp.swap(ndp);
  }  

  int ans = 0;
  forn(i, len + 1) {
    add(ans, dp[i]);
  }
  return ans;
}

vi s;

void go(int i, int n, int& ans) {
  bool ok = true;
  forn(j, 10) {
    if  (cnt[j] > 0) {
      ok = false;
    }
  }
  
  if  (ok) {
    ++ans;
    puts("q:");
    for (int d : s) {
      printf("%d", d);
    }
    puts("");
  }

  if  (i == n) {
    return;
  }

  forn(d, 10) {
    if  (d == 0 && i == 0) {
      continue;
    }
    --cnt[d];
    s.pb(d);
    go(i + 1, n, ans);
    s.pop_back();
    ++cnt[d];
  }
}

int brut(int n) {
  int ans = 0;
  --cnt[0];
  bool ok = true;
  forn(d, 10) {
    if  (cnt[d] > 0) {
      ok = false;
    } 
  }
  ++cnt[0];
  ans += ok;

  go(0, n, ans);
  return ans;
}

int n;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  C[0][0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    C[i][0] = 1;
    for (int j = 1; j < MAXN; ++j) {
      add(C[i][j], C[i - 1][j - 1]);
      add(C[i][j], C[i - 1][j]);
    }
  }

  scanf("%d", &n);
  forn(i, 10) {
    scanf("%d", &cnt[i]);
  }

  int ans = 0;
  for (int f = 1; f < 10; ++f) {
    --cnt[f];
    add(ans, solve(n - 1));
//    printf("cur = %d\n", solve(n - 1));
    ++cnt[f];
  }
  /*
  if  (cnt[0] <= 1) {
    add(ans, 1);
    for (int i = 1; i < 10; ++i) {
      if  (cnt[i]) {
        add(ans, -1 + MOD);
        break;
      }
    }
  }*/

  printf("%d\n", ans);
//  printf("%d\n", brut(n));
  return 0;
}