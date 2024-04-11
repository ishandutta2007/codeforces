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
#define hash kjfdkljkdhgjdkfhgurehg
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
const int INF = 2e9 + 1;

vii p;
vi dp;
int n;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d", &n);
  p.resize(n);
  forn(i, n) {
    int x, w;
    scanf("%d%d", &x, &w);
    p[i] = mp(x + w, x);
  }

  sort(all(p));

  dp.assign(n, 0);
  forn(i, n) {
    int x = p[i].snd;
    int w = p[i].fst - x;

    int pos = upper_bound(all(p), mp(x - w, INF)) - p.begin();
    --pos;

    int prev_dp = pos >= 0 ? dp[pos] : 0;
    dp[i] = prev_dp + 1;
    if  (i > 0) {
      dp[i] = max(dp[i], dp[i - 1]);
    }
  }

  printf("%d\n", dp[n - 1]);
  return 0;
}