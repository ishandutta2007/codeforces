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
const int MAXN = 500;

char a[MAXN][MAXN];
char b[MAXN][MAXN];
int n, m;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d\n", &m, &n);
  forn(i, n) {
    gets(a[i]);
  }

  forn(j, m) {
    ford(i, n) {
      b[j][n - i - 1] = a[i][j];
    }
  }

  swap(n, m);
  swap(a, b);

  forn(i, n) {
    forn(j, m / 2) {
      swap(a[i][j], a[i][m - j - 1]);
    }
  }

  forn(i, n) {
    forn(j, m) {
      b[2 * i][2 * j] = b[2 * i + 1][2 * j] = b[2 * i][2 * j + 1] = b[2 * i + 1][2 * j + 1] = a[i][j];
    }
  }

  forn(i, 2 * n) {
    b[i][2 * m] = 0;    
    puts(b[i]);
  }

  return 0;
}