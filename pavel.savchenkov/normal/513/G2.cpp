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
typedef long double ld;

const double EPS = 1e-9;

vi p;

ll cnt[100];
ll all = 0;

void go(int k) {
  if  (k == 0) {
    int cur = 0;
/*    
    for (int x : p) {
      printf("%d ", x);
    }
    puts("");
*/    
    forn(i, sz(p)) for (int j = i + 1; j < sz(p); ++j) cur += p[i] > p[j];
    cnt[cur]++;
    ++all;
    return;
  }

  int all = 0;
  forn(l, sz(p)) {
    for (int r = l; r < sz(p); ++r) {
      reverse(p.begin() + l, p.begin() + r + 1);
      go(k - 1);
      ++all;
      reverse(p.begin() + l, p.begin() + r + 1);
    }
  }

//  cout << all << endl;
}

int n, k;

ld small() {
  go(k);

  ld ans = 0;
  forn(i, 100) ans += i * (ld) cnt[i] / all;
   
  return ans;
}


const int MAXN = 32;

ld dp[2][MAXN][MAXN];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> k;
  p = vi(n);
  forn(i, n) {
    scanf("%d", &p[i]);
    --p[i];
  }

  int c = 0;
  forn(i, n) forn(j, n) dp[c][i][j] = 0.0;

  forn(i, n) {
    for (int j = i + 1; j < n; ++j) {
      if  (p[i] > p[j]) {
        dp[c][i][j] = 1.0;
      }
    }
  }
  
  int all = n * (n - 1) / 2 + n;

//  printf("all = %d\n", all);

  for (int was = 1; was <= k; ++was, c ^= 1) {
//    printf("was = %d\n", was);

    forn(i, n) forn(j, n) dp[c ^ 1][i][j] = 0.0;

    forn(i, n) {
      for (int j = i + 1; j < n; ++j) {
//        printf("dp[was=%d][%d][%d] = %.5f\n", was - 1, i, j, (double) dp[c][i][j]);
        for (int l = 0; l < n; ++l) {
          for (int r = l; r < n; ++r) {
            ld prob = 1.0 / all;
            int I = (l <= i && i <= r) ? l + (r - i) : i;
            int J = (l <= j && j <= r) ? l + (r - j) : j;
            
            if  (I < J) {
              dp[c ^ 1][i][j] += prob * dp[c][I][J];
            } else {
              dp[c ^ 1][i][j] += prob * (1.0 - dp[c][J][I]);
            }
          }
        }
        continue;
        /*
        int rest = all;

        ld prob = (ld) (i + 1) * 1.0 * (n - j) / (ld) all;
        rest -= (i + 1) * (n - j);
        printf("prob_rev = %.10f\n", (double) prob);
        dp[c ^ 1][i][j] += dp[c][i][j] * (1.0 - prob) + (1.0 - dp[c][i][j]) * prob;

        for (int l = 0; l <= i; ++l) {
          for (int r = i; r < j; ++r) {
            int I = l + (r - i);
            ld prob = 1.0 / all;
            --rest;
            dp[c ^ 1][i][j] += dp[c][I][j] * prob;
          }
        }

        for (int l = i + 1; l <= j; ++l) {
          for (int r = j; r < n; ++r) {
            int J = l + (r - j);
            ld prob = 1.0 / all;
            rest -= prob;
            dp[c ^ 1][i][j] += dp[c][i][J] * prob;
          }
        }

        dp[c ^ 1][i][j] += dp[c][i][j] * rest;
        */
      }
    }
  }
  
  ld ans = 0;
  forn(i, n) forn(j, n) if  (i <= j) ans += dp[c][i][j];

  printf("%.15f\n", (double) ans);

//  printf("small = %.10f\n", (double) small());

  return 0;
}