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

int deg(ll x, int d) {
  int res = 0;
  while (x % d == 0) {
    x /= d;
    ++res;
  }
  return res;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int n;
  cin >> n;
  vll a(n);
  forn(i, n) {
    int val;
    scanf("%d", &val);
    a[i] = val;
  }

  int max_x = 0;
  forn(i, n) {
    max_x = max(max_x, deg(a[i], 2));
  }

  int max_y = 0;
  forn(i, n) {
    max_y = max(max_y, deg(a[i], 3));
  }

  forn(i, n) {
    int cnt_y = max_y - deg(a[i], 3);
    forn(it, cnt_y) a[i] *= 3;
    int cnt_x = max_x - deg(a[i], 2);
    forn(it, cnt_x) a[i] *= 2;
  }

  sort(all(a));

  puts(a[0] == a.back() ? "Yes" : "No");

  return 0;
}