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

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int mnW = 10;
  int mnB = 10;
  vector<string> a(8);
  forn(i, 8) {
    getline(cin, a[i]);
  }
  forn(i, 8) forn(j, 8) {
    if  (a[i][j] == '.') {
      continue;
    }
    if  (a[i][j] == 'W') {
      bool ok = true;
      forn(ii, i) {
        if  (a[ii][j] != '.') {
          ok = false;
        }
      }
      if  (ok) {
        mnW = min(mnW, i);
      }
    } else {
      bool ok = true;
      for (int ii = i + 1; ii < 8; ++ii) {
        if  (a[ii][j] != '.') {
          ok = false;
        }
      }
      if  (ok) {
        mnB = min(mnB, 8 - i - 1);
      }
    }
  }

  if  (mnW <= mnB) {
    puts("A");
  } else {
    puts("B");
  }
  return 0;
}