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

char s[MAXN][MAXN];
bool a[MAXN][MAXN];
int n, m;

bool A[MAXN][MAXN];

void print() {
  forn(i, n) {
    forn(j, m) {
      printf("%d", a[i][j]);
    }
    puts("");
  }
}

void trans() {
  forn(i, n) forn(j, m) {
    A[j][i] = a[i][j];
  }
  swap(n, m);
  forn(i, n) forn(j, m) a[i][j] = A[i][j];
}

void up_down() {
  forn(i, n / 2) {
    forn(j, m) {
      swap(a[i][j], a[n - i - 1][j]);
    }
  }
}

void left_right() {
  forn(j, m / 2) {
    forn(i, n) {
      swap(a[i][j], a[i][m - j - 1]);
    }
  }
}

#define int ll

int get0() {
  int cnt = 0;
  forn(j, m) {
    int ok = true;
    forn(i, n) {
      ok &= a[i][j];
    }

    ok &= (0 < j && j < m - 1);

    cnt += ok;
  }
  return cnt;
}

bool left[MAXN][MAXN];
bool down[MAXN][MAXN];

int get1() {
  memset (left, false, sizeof left);
  memset (down, false, sizeof down);

  forn(i, n) {
    left[i][0] = a[i][0];
    for (int j = 1; j < m; ++j) {
      left[i][j] = left[i][j - 1] && a[i][j];
    }
  }

  forn(j, m) {
    down[n - 1][j] = a[n - 1][j];
    for (int i = n - 2; i >= 0; --i) {
      down[i][j] = down[i + 1][j] && a[i][j];
    }
  }

  int cnt = 0;
  forn(i, n) forn(j, m) {
    if  (j == 0 || j == m - 1 || i == 0 || i == n - 1) {
      continue;
    }

    cnt += left[i][j] && down[i][j];
  }

  return cnt;
}

bool right[MAXN][MAXN];
int cnt_right[MAXN][MAXN];

int get2() {    
  memset (left, false, sizeof left);
  memset (right, false, sizeof right);
  memset (cnt_right, 0, sizeof cnt_right);

  forn(i, n) {
    left[i][0] = a[i][0];
    for (int j = 1; j < m; ++j) {
      left[i][j] = left[i][j - 1] && a[i][j];
    }
  }

  forn(i, n) {
    right[i][m - 1] = a[i][m - 1];
    ford(j, m - 1) {
      right[i][j] = right[i][j + 1] && a[i][j];
    }
  }
  
  forn(i, n) forn(j, m) {
    if  (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
      right[i][j] = false;
    }
  }

  forn(j, m) {
    cnt_right[n - 1][j] = 0;
    ford(i, n - 1) {
      if  (!a[i][j] || !a[i + 1][j]) {
        cnt_right[i][j] = 0;
        continue;
      }
      cnt_right[i][j] = cnt_right[i + 1][j] + right[i + 1][j];
    }
  }

  int cnt = 0;
  forn(i, n) forn(j, m) {
    if  (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
      continue;
    }

    cnt += ((int) left[i][j]) * cnt_right[i][j];
  }

  return cnt;
}

int cnt_down[MAXN][MAXN];

int get3() {
  memset (down, false, sizeof down);
  memset (cnt_down, 0, sizeof cnt_down);

  forn(j, m) {
    down[n - 1][j] = a[n - 1][j];
    ford(i, n - 1) {
      down[i][j] = down[i + 1][j] && a[i][j];
    }
  }

  forn(i, n) forn(j, m) {
    if  (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
      down[i][j] = false;
    }
  }

  forn(i, n) {
    cnt_down[i][m - 1] = 0;
    ford(j, m - 1) {
      if  (!a[i][j] || !a[i][j + 1]) {
        cnt_down[i][j] = 0;
        continue;
      }
      cnt_down[i][j] = cnt_down[i][j + 1];
      if  (j + 2 < m) {
        cnt_down[i][j] += down[i][j + 2];
      }
    }
  }

  int cnt = 0;
  forn(i, n) forn(j, m) {
    if  (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
      continue;
    }

    cnt += ((int) down[i][j]) * cnt_down[i][j];
  }

  return cnt;
}

signed main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d\n", &n, &m);
  forn(i, n) {
    gets(s[i]);
  }

  forn(i, n) forn(j, m) {
    a[i][j] = s[i][j] == '.';
  }
/*
  print();
  puts("");
  trans();
  print();
  return 0;
*/
  ll ans = 0;

  // 0
  ans += get0();
  
  trans();
  ans += get0();
  trans();

//  cout << "after 0 --> " << ans << endl;
   
  // 1
  ans += get1();
  
  left_right();
  ans += get1();
  left_right();

  up_down();
  ans += get1();
  left_right();
  ans += get1();
  left_right();
  up_down();

  // 2
  ans += get2();
  left_right();
  ans += get2();
  left_right();

  trans();
  ans += get2();
  left_right();
  ans += get2();
  left_right();
  trans();

  // 3
  ans += get3();
  up_down();
  ans += get3();
  up_down();

  trans();
  ans += get3();
  up_down();
  ans += get3();
  up_down();
  trans();

  cout << ans << endl;
  return 0;
}