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

bool hor[MAXN][MAXN];
bool ver[MAXN][MAXN];
int k, h, w;
char buf[MAXN];
int a[MAXN][MAXN];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> h >> w >> k;
  scanf("\n");

  forn(i, 2 * h - 1) {
    gets(buf);
    if  (i & 1) {
      forn(j, w) {
        ver[i / 2][j] = buf[j] == 'E';
      }
    } else {
      forn(j, w - 1) {
        hor[i / 2][j] = buf[j] == 'E';
      }
    } 
  }

  if  (k == 1) {
    int all = 0;
    int good = 0;

    forn(i, h) {
      forn(j, w - 1) {
        ++all;
        good += hor[i][j];
      }
    }

    forn(i, h - 1) {
      forn(j, w) {
        ++all;
        good += ver[i][j];
      }
    }

    if  (good * 4 >= all * 3) {
      puts("YES");
      forn(i, h) {
        forn(j, w) {
          printf("1 ");
        }
        puts("");
      }
    } else {
      puts("NO");
    }
    return 0;
  }

  if  ((w - 1) * h + ((w + 1) / 2) * (h - 1) > (h - 1) * w + ((h + 1) / 2) * (w - 1)) {
    a[0][0] = 0;
    for (int j = 1; j < w; ++j) {
      if  (hor[0][j - 1]) {
        a[0][j] = a[0][j - 1];  
      } else {
        a[0][j] = a[0][j - 1] ^ 1;
      }
    }

    for (int i = 1; i < h; ++i) {
      vi ok(2, 0);

      forn(c, 2) {
        a[i][0] = c;
        for (int j = 1; j < w; ++j) {
          a[i][j] = a[i][j - 1] ^ (!hor[i][j - 1]);
        }
        forn(j, w) {
          ok[c] += ver[i - 1][j] == (a[i][j] == a[i - 1][j]);
        }
      }

      if  (ok[0] > ok[1]) {
        a[i][0] = 0;
        for (int j = 1; j < w; ++j) {
          a[i][j] = a[i][j - 1] ^ (!hor[i][j - 1]);
        }
      }
    }
  } else {
    a[0][0] = 0;
    for (int i = 1; i < h; ++i) {
      a[i][0] = a[i - 1][0] ^ (!ver[i - 1][0]);
    } 

    for (int j = 1; j < w; ++j) {
      vi ok(2, 0);
      forn(c, 2) {
        a[0][j] = c;
        for (int i = 1; i < h; ++i) {
          a[i][j] = a[i - 1][j] ^ (!ver[i - 1][j]); 
        }
        forn(i, h) {
          ok[c] += hor[i][j - 1] == (a[i][j] == a[i][j - 1]);
        }
      }

      if  (ok[0] > ok[1]) {
        a[0][j] = 0;
        for (int i = 1; i < h; ++i) {
          a[i][j] = a[i - 1][j] ^ (!ver[i - 1][j]); 
        }
      }
    }
  }

  puts("YES");
  forn(i, h) {
    forn(j, w) {
      printf("%d ", a[i][j] + 1);
    }
    puts("");
  }

  return 0;
}