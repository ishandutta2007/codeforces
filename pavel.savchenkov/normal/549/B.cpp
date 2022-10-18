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

#define FILE_NAME ""

const ld EPS = 1e-9;
const int MAXN = 100 + 10;

bool g[MAXN][MAXN];
int n;
int a[MAXN];
char s[MAXN][MAXN];
int b[MAXN];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d\n", &n);
  forn(i, n) {
    gets(s[i]);
    forn(j, n) g[i][j] = s[i][j] == '1';
  }

  forn(i, n) {
    scanf("%d", &a[i]);
  }

  forn(i, n) {
    forn(j, n) {
      if  (g[i][j]) {
        ++b[j];
      }
    }
  }

/*
  puts("b:");
  forn(i, n) {
    printf("%d ", b[i]);
  }
  puts("");

  puts("a:");
  forn(i, n) {
    printf("%d ", a[i]);
  }
  puts("");
*/

  vi in(n, 1);
  while (1) {
    int bad = -1;
    forn(i, n) {
      if  (in[i] && b[i] == a[i]) {
        bad = i;
        break;
      }
    }

    if  (bad == -1) {
      break;
    }

//    printf("out = %d\n", bad);

    forn(j, n) {
      if  (in[j] && g[bad][j]) {
        --b[j];
      }
    }
    in[bad] = 0;
  }
/*
  forn(i, n) assert(b[i] >= 0);

  forn(i, n) {
    if  (b[i] == a[i]) {
      printf("== at %d\n", i);
      puts("-1");
      return 0;
    }
  }
*/

  int cnt = 0;
  forn(i, n) cnt += in[i];

  printf("%d\n", cnt);
  forn(i, n) {
    if  (in[i]) {
      printf("%d ", i + 1);
    }
  }
  puts("");

  return 0;
}