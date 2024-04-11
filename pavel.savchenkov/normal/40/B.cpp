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
const int MAXN = 5000 + 10;

int n, m;
int a[MAXN][MAXN];
/*
int it = 1;
int b[MAXN][MAXN];
int cnt[MAXN][MAXN];

bool on(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void go() {
  forn(i, n) forn(j, m) {
    if  ((i + j) % 2 == 1) {
      continue;
    }

    int C = 0;
    for (int di = -1; di <= 1; di += 2) {
      for (int dj = -1; dj <= 1; dj += 2) {
        int ii = i + di;
        int jj = j + dj;
        if  (on(ii, jj) && a[ii][jj] == it - 1) {
          ++C;
        } 
      }
    }

    if  (C == 4) {
      b[i][j] = it;
      ++cnt[i][j];  
    }
  }

  forn(i, n) forn(j, m) {
    if  (b[i][j] == it) {
      a[i][j] = it;
    }
  }

  ++it;
}
*/
void smart() {
  int i1 = 0;
  int i2 = n - 1;
  int j1 = 0;
  int j2 = m - 1;
  int c = 0;
  while (i1 <= i2 && j1 <= j2) {
    for (int i = i1; i <= i2; ++i) {
      a[i][j1] = a[i][j2] = c;
    } 
    for (int j = j1; j <= j2; ++j) {
      a[i1][j] = a[i2][j] = c;
    }
    
    ++c;
    ++i1;
    --i2;
    ++j1;
    --j2;
  }
}

int main() {
#ifdef LOCAL
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d", &n, &m);

  smart();

  int x;
  scanf("%d", &x);

  int ans = 0;
  forn(i, n) forn(j, m) ans += (i + j) % 2 == 0 && a[i][j] + 1 == x;

  printf("%d\n", ans);
  return 0;
/*
  memset (a, 0, sizeof a);
  while (it <= 100) {
    forn(i, n) {
      forn(j, m) {
        printf("%d ", cnt[i][j]);
      }
      puts("");
    }
    puts("");


    go();
  }
*/
//  while(1) {}
  return 0;
}