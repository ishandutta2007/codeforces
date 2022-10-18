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

bool prime(int x) {
  for (int i = 2; i * i <= x; ++i)
    if  (x % i == 0) return false;
  return true;
}         
 
int cnt[30];
char a[30];
int n;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d\n", &n);
  gets(a);

  forn(i, n) {
    int F = a[i] - '0';

    for (int x = 2; x <= F; ++x) {
      int X = x;
      for (int j = 2; j * j <= X; ++j) {
        while  (X % j == 0) {
          X /= j;
          ++cnt[j];  
        }
      }

      if  (X > 1)
        ++cnt[X];
      }
  }

  for (int i = 9; i > 1; --i) {
//    printf("cnt[%d] = %d\n", i, cnt[i]);
//    continue;
    forn(j, cnt[i]) {
      printf("%d", i);
    }

    for (int x = 2; x <= i; ++x) {
      int X = x;
      for (int j = 2; j * j <= X; ++j) {
        while  (X % j == 0) {
          X /= j;
          cnt[j] -= cnt[i];  
        }
      }

      if  (X > 1)
        cnt[X] -= cnt[i];
      }
  }

  return 0;
}