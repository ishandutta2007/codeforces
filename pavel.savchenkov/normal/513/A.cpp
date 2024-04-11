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
const int MAXN = 55;

int dp[MAXN][MAXN][2];
int k[2];

int calc(int n1, int n2, bool who) {
  if  (who) {
    if  (n2 == 0) {
      return 0;
    }
  }

  if  (!who) {
    if  (n1 == 0) {
      return 0;
    }
  }

  int& res = dp[n1][n2][who];

  if  (res != -1) {
    return res;
  }

  for (int d = 1; d <= k[who] && (who ? n2 : n1) - d >= 0; ++d) {
    int nn1 = n1;
    int nn2 = n2;
    if  (who) {
      nn2 -= d;
    } else {
      nn1 -= d;
    }

    if  (!calc(nn1, nn2, who ^ 1)) {
      return (res = 1);
    }
  }

  return (res = 0);
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  int n1, n2;
  cin >> n1 >> n2 >> k[0] >> k[1];

  memset (dp, -1, sizeof dp);

  puts(calc(n1, n2, 0) ? "First" : "Second");
  return 0;
}