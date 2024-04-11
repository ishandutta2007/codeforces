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

int gcd(int a, int b, int& x, int& y) {
  if  (!b) {
    x = 1;
    y = 0;
    return a;
  }

  int xx, yy;
  int g = gcd(b, a % b, xx, yy);

  x = yy;
  y = xx - (a / b) * yy;
  return g;
}            

int inv(int a, int mod) {
  int x, y;
  int g = gcd(a, mod, x, y);
  assert(g == 1);
  return x % mod; 
}

int mul(int x, int y, int mod) {
  return x * 1ll * y % mod;
}

const int MAXN = 1e6 + 10;

int n, m, dx, dy;
int cnt[MAXN];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif
  
  scanf("%d%d%d%d", &n, &m, &dx, &dy);
  
  forn(i, m) {
    int x, y;
    scanf("%d%d", &x, &y);
    ++cnt[(mul(dy, x, n) - mul(dx, y, n) + n) % n];
  }

  int mx = 0;
  forn(c, MAXN) {
    mx = max(mx, cnt[c]);
  }

  forn(c, MAXN)
    if  (cnt[c] == mx) {
      printf("%d %d\n", 0, (- mul(c, inv(dx, n), n) + n) % n);
      return 0;
    }

  return 0;
}