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

const ld EPS = 1e-9;
const int MAXN = 11 * 11 * 11 * 11 * 11 + 10;
const int base = 11;

bool dp[22][MAXN][(1 << 5)+10];
int a[22];
int b[22];
int n, m;

int D[22];

void decode(int x) {
  forn(i, n) {
    D[i] = (x % base);
    x /= base;
  }
}

int code() {
  int res = 0;
  ford(i, n) {
    int d = D[i];
    res = res * base + d;
  }
  return res;
}

int ans[22][22];
vi masks[22];

inline bool bit(int mask, int i) {
  return (mask >> i) & 1;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> m;
  forn(i, n) cin >> a[i];
  forn(i, m) cin >> b[i];

  forn(mask, 1 << n) {
    int bl = 0;
    forn(i, n) {
      if  (bit(mask, i)) {
        if  (i == n - 1 || !bit(mask, i + 1)) {
          ++bl;
        }
      }
    } 
    masks[bl].pb(mask);
  }
  
  dp[0][0][0] = true;
  forn(j, m) {
    forn(C, MAXN) {
      decode(C);
      bool bad = false;
      forn(i, n) {
        if  (D[i] > a[i] || D[i] + (m - j + 2) / 2 < a[i]) {
          bad = true;
        }
      }
      if  (bad) {
        continue;
      }
      forn(mask, 1 << n) {
        if  (!dp[j][C][mask]) {
          continue;
        }

        for (int cur_mask : masks[b[j]]) {
          decode(C);
          forn(i, n) {
            if  (!bit(mask, i) && bit(cur_mask, i)) {
              ++D[i];
            }
          }
          dp[j + 1][code()][cur_mask] = true;
        }
      } 
    }
  }

  forn(i, n) {
    D[i] = a[i];
  }
  int need_C = code();
  int need_mask = -1;
  
  ford(j, m) {
    bool ready = false;

    forn(C, MAXN) {
      if  (ready) {
        break;
      }
      forn(mask, 1 << n) {
        if  (ready) {
          break;
        }

        if  (!dp[j][C][mask]) {
          continue;
        }

        for (int cur_mask : masks[b[j]]) {
          if  (need_mask != -1 && cur_mask != need_mask) {
            continue;
          }

          decode(C);
          forn(i, n) {
            if  (!bit(mask, i) && bit(cur_mask, i)) {
              ++D[i];
            }
          }
          if  (code() == need_C) {
            forn(i, n) {
              if  (bit(cur_mask, i)) {
                ans[i][j] = 1;
              }
            }
            need_C = C;
            ready = true;
            need_mask = mask;
            break;
          }
        }
      }
    }

    assert(ready);
  }

  forn(i, n) {
    forn(j, m) {
      putchar(ans[i][j] ? '*' : '.');
    }
    puts("");
  }

  return 0;
}