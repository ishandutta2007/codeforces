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

int get_cnt(int n) {
  int res = 0;
  while (n) {
    ++res;
    n /= 10;
  }
  return res;
}

ll solve(int n) {
  if  (n <= 9) {
    return n;
  }

  int cnt = get_cnt(n);
  int pw10 = 1;
  forn(i, cnt - 1) pw10 *= 10;

  return solve(pw10 - 1) + (n - pw10 + 1) * 1ll * cnt;
}

int brut(int n) {
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += get_cnt(i);
  }
  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

/*
  while (1) {
    int n = rand() + 1;
    if  (brut(n) != solve(n)) {
      printf("bad at %d, my=%I64d, brut=%d\n", n, solve(n), brut(n));
      return 0;
    }
  }
*/

  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}