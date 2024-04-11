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
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 10;

inline void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

inline int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

int C[MAXN][MAXN];

void precalc() {
  C[0][0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    C[i][0] = 1;
    for (int j = 1; j < MAXN; ++j) {
      C[i][j] = C[i - 1][j];
      add(C[i][j], C[i - 1][j - 1]);
    }
  }
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  precalc();

  int ans = 1;
  int have = 0;
  int k;
  scanf("%d", &k);
  forn(i, k) {
    int cnt;
    scanf("%d", &cnt);
    ans = mul(ans, C[have + cnt - 1][cnt - 1]);
    have += cnt;
  }

  cout << ans << endl;
  return 0;
}