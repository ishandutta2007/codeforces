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
const int MAXN = 1e5 + 10;

char s[MAXN];
int n;

bool solve() {
  int l = -1;
  forn(i, n - 1) {
    if  (s[i] == 'A' && s[i + 1] == 'B') {
      l = i + 1;
      break;
    }
  }

  int r = -1;
  forn(i, n - 1) {
    if  (s[i] == 'B' && s[i + 1] == 'A') {
      r = i;
    }
  }

  if  (l != -1 && r != -1 && l < r) {
    return true; 
  }

  l = -1;
  forn(i, n - 1) {
    if  (s[i] == 'B' && s[i + 1] == 'A') {
      l = i + 1;
      break;
    }
  }

  r = -1;
  forn(i, n - 1) {
    if  (s[i] == 'A' && s[i + 1] == 'B') {
      r = i;
    }
  }

  if  (l != -1 && r != -1 && l < r) {
    return true; 
  }

  return false;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  gets(s);
  n = strlen(s);

  puts(solve() ? "YES" : "NO"); 
  return 0;
}