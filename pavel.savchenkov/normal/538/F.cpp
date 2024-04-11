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

struct FenwTree {
  vi t;

  FenwTree(int n = 0) {
    t.assign(n, 0);
  }

  void inc(int pos, int val) {
    for (int i = pos; i < sz(t); i |= i + 1) {
      t[i] += val;
    }
  }

  int get(int r) {
    int res = 0;
    for (int i = r; i >= 0; i &= i + 1, --i) {
      res += t[i];
    }
    return res;
  }

  int get(int l, int r) {
    return get(r) - get(l - 1);
  }                      
};

const int MAXN = 2e5 + 10;

int ans[MAXN];

struct Query {
  int up, k, neg;
};

vector<Query> qs[MAXN];
int n;
int a[MAXN];
/*
void brut() {
  vi res(n + 1, 0);
  for (int k = 1; k < n; ++k) {
    forn(v, n) {
      int l = k * v + 1;
      int r = min(n - 1, l + k - 1);
      for (int i = l; i <= r; ++i) {
        res[k] += a[i] < a[v];
      }
    }
  }
  for (int k = 1; k < n; ++k) {
    printf("%d ", res[k]);
  }
  puts("");
}
*/
int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  vi c;
  forn(i, n) {
    c.pb(a[i]);
  }
  sort(all(c));
  c.resize(unique(all(c)) - c.begin());

  forn(i, n) {
    a[i] = lower_bound(all(c), a[i]) - c.begin();
  }

  for (int k = 1; k < n; ++k) {
    forn(v, n) {
      int l = k * v + 1;
      if  (l >= n) {
        break;
      }
      int r = min(l + k - 1, n - 1);

//      printf("v = %d, [%d, %d]\n", v, l, r);

      qs[r].pb({ a[v], k, false });
      if  (l > 0) {
        qs[l - 1].pb({ a[v], k, true });
      }
    }
  }

  FenwTree T(sz(c));
  forn(i, n) {
    T.inc(a[i], +1);

    forn(j, sz(qs[i])) {
      int sum = T.get(qs[i][j].up - 1);
      int k = qs[i][j].k;
      if  (qs[i][j].neg) {
        ans[k] -= sum;
      } else {
        ans[k] += sum;
      }
    }
  }

  for (int k = 1; k < n; ++k) {
    printf("%d ", ans[k]);
  }
  puts("");

//  brut();

  return 0;
}