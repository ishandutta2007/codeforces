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
const int MAXN = 300 + 10;

char a[MAXN][MAXN];
int p[MAXN];
int n;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n) {
    scanf("%d", &p[i]);
    --p[i];
  }

  scanf("\n");
  forn(i, n) {
    gets(a[i]);
  }

  forn(k, n) forn(i, n) forn(j, n) if  (a[i][k] == '1' && a[k][j] == '1') a[i][j] = '1';

  forn(i, n) {               
    int mn = p[i];
    int pos = i;

    for (int j = i; j < n; ++j)
      if  (p[j] < mn && a[i][j] == '1') {
        mn = p[j];
        pos = j;
      } 

    swap(p[i], p[pos]);
  }

  forn(i, n) {
    printf("%d ", p[i] + 1);
  }

  return 0;
}