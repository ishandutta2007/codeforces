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
const int MAXN = 1e3 + 10;

int sum[MAXN][MAXN];
int a[MAXN][MAXN];
int n, m;

int get_sum(int x1, int y1, int x2, int y2) {
  return sum[x2 + 1][y2 + 1] - sum[x2 + 1][y1] - sum[x1][y2 + 1] + sum[x1][y1];
}

int is_full(int x1, int y1, int x2, int y2) {
  return get_sum(x1, y1, x2, y2) == (x2 - x1 + 1) * (y2 - y1 + 1);
}

bool is_1(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m && a[i][j];
}

char buf[MAXN];

bool check(int i, int j, int x, int y) {
  int cnt = x * y;
  while (1) {
    if  (!is_full(i, j, i + x - 1, j + y - 1)) {
      return false;
    }

    if  (is_1(i, j + y)) {
      cnt += x;
      ++j;
    } else if  (is_1(i + x, j)) {
      cnt += y;
      ++i;
    } else {
      break;
    }
  }

  return cnt == get_sum(0, 0, n - 1, m - 1);
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d\n", &n, &m);
  int I = n;
  int J = m;
  forn(i, n) {
    gets(buf);
    
    forn(j, m) {
      a[i][j] = buf[j] == 'X';
      sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + a[i][j];

      if  (a[i][j] && (i < I || (i == I && j < J))) {
        I = i;
        J = j;  
      }
    }
  }

  if  (I == n) {
    puts("-1");
    return 0;
  }

  int max_x = 0;
  for (int i = I; i < n && a[i][J]; ++i, ++max_x) ;

  int max_y = 0;
  for (int j = J; j < m && a[I][j]; ++j, ++max_y) ;

  int res = n * m + 1;
  for (int y = 1; y <= max_y; ++y) {
    if  (check(I, J, max_x, y)) {
      res = min(res, max_x * y);
    }
  }
  for (int x = 1; x <= max_x; ++x) {
    if  (check(I, J, x, max_y)) {
      res = min(res, x * max_y);
    }
  }

  printf("%d\n", res == n * m + 1 ? -1 : res);
  return 0;
}