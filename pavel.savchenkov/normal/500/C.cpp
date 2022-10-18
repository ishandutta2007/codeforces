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
const int MAXN = 500 + 10;

int w[MAXN];
int b[MAXN * 10];
int n, m;
bool was[MAXN];

vi order;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  forn(i, n) {
    scanf("%d", &w[i]);
  }

  forn(i, m) {
    scanf("%d", &b[i]);
    --b[i];
  }

  memset (was, false, sizeof was);
  forn(i, m) {
    if  (!was[b[i]]) {
      order.pb(b[i]);
      was[b[i]] = true;
    }
  }

  int res = 0;
  forn(i, m) {
    int pos = -1;
    forn(j, sz(order)) {
      if  (order[j] == b[i]) {
        pos = j;
      }
    }

    assert(pos != -1);

    forn(j, pos) {
      res += w[order[j]];
    }

    for (int j = pos; j > 0; --j) {
      order[j] = order[j - 1];
    }
    order[0] = b[i];
  }

  printf("%d\n", res);
  return 0;
}