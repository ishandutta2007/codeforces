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

const double EPS = 1e-9;
const int MAXN = 1e3 + 10;

int a[MAXN][MAXN];
int n, m;
int p;

void add(int& x, int y) {
  (x += y) >= p && (x -= p);
}

int mul(int x, int y) {
  return x * 1ll * y % p;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  memset (a, -1, sizeof a);

  cin >> n >> m;

  int k;
  cin >> k;
  forn(i, k) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    --x;
    --y;

    if  (n > m) {
      a[y][x] = c == -1;  
    } else {
      a[x][y] = c == -1;
    }
  }

  scanf("%d\n", &p);

  if  (n > m) {
    swap(n, m);
  }

  if  (n % 2 != m % 2) {
    puts("0");
    return 0;
  }
/*
  forn(i, n) {
    forn(j, m) {
      printf("%d ", a[i][j]);
    }
    puts("");
  }
*/
  int p;
  scanf("%d", &p);

  int ans = 1;
  bool was_empty = false;
  forn(j, m) {
    bool was = false;
    forn(i, n) {
      was |= a[i][j] != -1;
    }

    if  (!was && !was_empty) {
      was_empty = true;
      continue;  
    }

    vi dp(2, 0);
    dp[0] = 1;
    forn(i, n) {
      vi ndp(2, 0);
      forn(par, 2) {
        forn(c, 2) {
          if  (a[i][j] != -1 && a[i][j] != c) {
            continue;
          }
          add(ndp[(par + c) % 2], dp[par]);
        } 
      }
      dp.swap(ndp);
    }

    ans = mul(ans, dp[1]);
  }

  printf("%d\n", ans);
  return 0;
}