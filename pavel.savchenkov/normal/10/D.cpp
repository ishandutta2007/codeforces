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
const int MAXN = 500 + 10;

int a[MAXN];
int b[MAXN];
int n, m;
int dp[MAXN][MAXN];
int who[MAXN];
pii prev[MAXN][MAXN];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n) scanf("%d", &a[i]);

  scanf("%d", &m);
  forn(i, m) scanf("%d", &b[i]);

  const pii E = mp(-1, -1);
  memset (dp, -1, sizeof dp);
  memset (who, -1, sizeof who);
  forn(i, n) {
    pii mx = E;
    forn(j, m) {
      if  (b[j] < a[i]) {
        if  (who[j] == -1) {
          continue;
        }
        if  (mx == E || dp[mx.fst][mx.snd] < dp[who[j]][j]) {
          mx = mp(who[j], j);
        }
      } else if  (b[j] == a[i]) {
        if  (mx == E) {
          if  (dp[i][j] < 1) {
            dp[i][j] = 1;
            who[j] = i;
            prev[i][j] = E;
          }
        } else {
          if  (dp[i][j] < dp[mx.fst][mx.snd] + 1) {
            dp[i][j] = dp[mx.fst][mx.snd] + 1;
            who[j] = i;
            prev[i][j] = mx;
          } 
        }
      }
    }
  }

  int max_len = 0;
  forn(i, n) forn(j, m) max_len = max(max_len, dp[i][j]);

  if  (max_len == 0) {
    puts("0");
    return 0;
  }

  forn(i, n) forn(j, m)
    if  (dp[i][j] == max_len) {
      vi res;
      pii cur = mp(i, j);
      while (prev[cur.fst][cur.snd] != E) {
        res.pb(a[cur.fst]);
        cur = prev[cur.fst][cur.snd];                             
      }
      res.pb(a[cur.fst]);

      reverse(all(res));
      printf("%d\n", sz(res));
      forn(i, sz(res)) printf("%d ", res[i]);
      return 0;
    }
  assert(false);

  return 0;                   
}