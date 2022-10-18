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
#include <fstream>
#include <unordered_map>
#include <unordered_set>

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
const int MAXN = 2e5 + 10;

int ans[MAXN];
int a[2 * MAXN];
int n;
bool ok[2 * MAXN];
int mem_gcd[MAXN];

bool read() {
  if  (scanf("%d", &n) < 1) {
    return false;
  }
  forn(i, n) {
    scanf("%d", &a[i]);
  }
  return true;
}

int cnt_in(int len, int s) {
  assert(s <= len);
  return len - s + 1;
}

ll solve() {
  forn(i, n) a[i + n] = a[i];

  for (int i = 1; i <= n; ++i) {
    mem_gcd[i] = __gcd(i, n);
  }

  memset (ans, 0, sizeof ans);

  for (int g = 1; g < n; ++g) {
    if  (n % g != 0) {
      continue;
    }
    memset (ok, 0, sizeof ok);
    forn(offset, g) {
      int mx = a[offset];
      for (int i = offset; i < n; i += g) {
        mx = max(mx, a[i]);
      }
      for (int i = offset; i < 2 * n; i += g) {
        ok[i] = (a[i] == mx);
      }
    }
    /*
    printf("g=%d\n", g);
    forn(i, 2 * n) printf("%d ", ok[i]);
    puts("");
    */
    int last_ok = -1;
    forn(i, 2 * n) {
      if  (!ok[i]) {
        last_ok = -1;
        continue;
      }
      if  (last_ok == -1 && ok[i]) {
        last_ok = i;
      }
      if  (last_ok >= n) {
        break;
      }
      if  ((i + 1 == 2 * n || !ok[i + 1]) && last_ok != -1) {
        int len = i - last_ok + 1;
        for (int s = g; s <= len && s < n; s += g) {
          if  (mem_gcd[s] != g) {
            continue;
          }
          ans[s] += min(cnt_in(len, s), (n - 1) - last_ok + 1);
//          printf("g=%d, s=%d, pos=%d += %d\n", g, s, i, cnt_in(len, s));
        } 
      }
    }
  }

  /*
  for (int i = 1; i <= n; ++i) {
    printf("ans[%d] = %d\n", i, ans[i]);
  }
  */

  ll res = 0;
  for (int s = 1; s <= n; ++s) res += ans[s];

  return res;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    cout << solve() << '\n';
  }

  return 0;
}