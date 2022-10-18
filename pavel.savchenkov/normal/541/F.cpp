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
const int MAXN = 1e3 + 10;
const int MAXT = 100 + 10;

int dp[MAXN][MAXT];
int t[MAXN];
int q[MAXN];
int n, T;

vi who[MAXT];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d%d", &n, &T);
//  n = 1000;
//  T = 100;
  forn(i, n) {
    scanf("%d%d", &t[i], &q[i]);
//    t[i] = rand() % T + 1;
//    q[i] = rand();
    who[T - t[i]].pb(i);
  }

  for (int de = 0; de <= T; ++de) {
    sort(all(who[de]), [&](int i, int j) { return q[i] > q[j]; });
  }

  for (int de = T; de >= 0; --de) {
    for (int cnt = 0; cnt <= n; ++cnt) {
      int& d = dp[cnt][de];
      int sum = 0;
      int ncnt = cnt;
      d = max(d, dp[min(n, cnt * 2)][de + 1]);
      for (int id : who[de]) {
        --ncnt;
        if  (ncnt < 0) {
          break;
        }
        sum += q[id];
        d = max(d, sum + dp[min(n, ncnt * 2)][de + 1]);  
      } 
    }
  }

  int res = 0;
  forn(de, T + 1) for (int cnt = 0; cnt <= n && cnt <= (de <= 20 ? 1 << de : n); ++cnt) {
    res = max(res, dp[cnt][de]);
//    if  (dp[cnt][de] > 0) {
//      printf("dp[%d][%d] = %d\n", cnt, de, dp[cnt][de]);
//    }
  }

  cout << res << endl;

//  printf("%.10f\n", (double) clock() / CLOCKS_PER_SEC);
  return 0;
}