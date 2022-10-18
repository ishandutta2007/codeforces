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
const int MAXC = 1e5;
const int MAXN = 300 + 10;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int n;
int l[MAXN];
int c[MAXN];

vi dels;
vll dp;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif
   
  scanf("%d", &n);
  int g = 0;
  forn(i, n) {
    scanf("%d", &l[i]);
    g = gcd(g, l[i]);
  }

  if  (g != 1) {
    puts("-1");
    return 0;
  }

  forn(i, n) {
    scanf("%d", &c[i]);
  }

  forn(i, n) {
    int x = l[i];
    for (int j = 1; j * j <= x; ++j) {
      if  (x % j == 0) {
        dels.pb(j);
        dels.pb(x / j);
      }   
    }
  }

  sort(all(dels));
  dels.resize(unique(all(dels)) - dels.begin());

  dp.assign(sz(dels), (ll) 1e18);

//  debug(sz(dels));

  forn(i, n) {
    forn(j, sz(dels)) {
      int g = dels[j];

      int ng = gcd(l[i], g);

      int jj = lower_bound(all(dels), ng) - dels.begin();

//      debug(jj);
      
      if  (ng < g) {
        dp[jj] = min(dp[jj], dp[j] + (ll)c[i]);
      } 
    }
          
    int j = lower_bound(all(dels), l[i]) - dels.begin();
    dp[j] = min(dp[j], (ll)c[i]);
  }

  cout << dp[0] << endl;
  return 0;
}