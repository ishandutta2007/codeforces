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
const int MAXN = 2e3 + 10;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };


vii who[4];

int D[MAXN][MAXN];

char a[MAXN][MAXN];
int cnt = 1;

int b[MAXN][MAXN];

int n, m;

bool on(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void calc(int x, int y) {
  D[x][y] = 0;
  forn(k, 4) {
    int X = x + dx[k];
    int Y = y + dy[k];

    if  (on(X, Y) && b[X][Y] == 0) {
      ++D[x][y];  
    }

  } 

//  printf("D[%d][%d] = %d\n", x, y, D[x][y]);
}

void upd_from(int x, int y) {
  forn(k, 4) {
    int X = x + dx[k];
    int Y = y + dy[k];
    
    if  (on(X, Y) && b[X][Y] == 0) {
      calc(X, Y);

      who[D[X][Y]].pb(mp(X, Y));
    }
  }
}

void paint(int i, int j, int i2, int j2) {
  b[i][j] = cnt;
  b[i2][j2] = cnt;
  ++cnt;

  vii c;
  c.pb(mp(i, j));
  c.pb(mp(i2, j2));

  forn(k, 2) {
    int x = c[k].fst;
    int y = c[k].snd;

    upd_from(x, y);
  } 
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d\n", &n, &m);

  forn(i, n) {
    gets(a[i]);
  }

  forn(i, n) forn(j, m) if  (a[i][j] == '*') b[i][j] = -1;

  forn(i, n) forn(j, m) if  (b[i][j] == 0) {
    calc(i, j);
    who[D[i][j]].pb(mp(i, j));
  }

  while (1) {
    if  (who[1].empty()) {
      break;
    }

    auto cur = who[1].back();
    who[1].pop_back();


    int i = cur.fst;
    int j = cur.snd;
    int d = D[i][j];

//    printf("cur == %d %d\n", i, j);

    if  (d != 1) {
      continue;
    }

    forn(k, 4) {
      int I = i + dx[k];
      int J = j + dy[k];

      if  (on(I, J) && b[I][J] == 0) {
        paint(i, j, I, J);
        break;
      }
    } 
  }
 /*
  forn(i, n) {
    forn(j, m)
      printf("%d ", b[i][j]);
    puts("");
  }
 */
  forn(i, n) forn(j, m) if  (b[i][j] == 0) {
    puts("Not unique");
    return 0;
  }

  forn(i, n) forn(j, m)
    if  (b[i][j] != -1) {
      forn(k, 4) {
        int I = i + dx[k];
        int J = j + dy[k];

        if  (on(I, J) && b[I][J] == b[i][j]) {
          if  (I == i - 1) {
            a[i][j] = 'v';
          } else if  (I == i + 1) {
            a[i][j] = '^';
          } else if  (J == j - 1) {
            a[i][j] = '>';
          } else {
            a[i][j] = '<';
          }

        }
      }
    }

  forn(i, n) {
    puts(a[i]);
  }

  return 0;
}