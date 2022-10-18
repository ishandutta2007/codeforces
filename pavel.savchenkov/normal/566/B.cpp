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
const int MAXN = 3e4 * 4 + 10;

struct Rule {
  int a, b, c;

  bool read() {
    if  (scanf("%d%d%d", &a, &b, &c) < 3) {
      return false;
    }
    --a;
    --b;
    --c;
    return true;
  }
};

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  vector<Rule> rules(4 * n);
  forn(i, 4 * n) {
    assert(rules[i].read());
  }

  vi deg(n, 4);
  vi used(4 * n, 0);
  vi ans;
  while (sz(ans) < 4 * n) {
    forn(i, 4 * n) {
      if  (used[i]) {
        continue;
      }
      const auto& r = rules[i];
      --deg[r.a];
      ++deg[r.b];
      ++deg[r.c];
      if  (deg[r.a] <= 9 && deg[r.b] <= 9 && deg[r.c] <= 9) {
        ans.pb(i);
        used[i] = true;
        continue;
      }
      ++deg[r.a];
      --deg[r.b];
      --deg[r.c];
    }
  }

  puts("YES");
  for (auto x : ans) printf("%d ", x + 1);
  puts("");

  return 0;
}