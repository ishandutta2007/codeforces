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
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr( T x ) {
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
const int MAXN = 100 + 10;

int a[MAXN][MAXN];
int b[MAXN][MAXN];
int n, m;

int main() {    
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

  scanf("%d%d", &m, &n);

  forn(i, m) {
    forn(j, n) {
      a[i][j] = 1;
    }
  }

  forn(i, m) {
    forn(j, n) {
      scanf("%d", &b[i][j]);

      if  (!b[i][j]) {
        forn(jj, n) {
          a[i][jj] = 0;
        }
        forn(ii, m) {
          a[ii][j] = 0;
        }
      }
    }
  }

  forn(i, m) {
    forn(j, n) {
      int c = 0;
      forn(ii, m) {
        c |= a[ii][j];
      }
      forn(jj, n) {
        c |= a[i][jj];
      }

      if  (c != b[i][j]) {
        puts("NO");
        return 0;
      }
    }
  }

  puts("YES");
  forn(i, m) {
    forn(j, n) {
      printf("%d ", a[i][j]);
    }
    puts("");
  }
	return 0;
}