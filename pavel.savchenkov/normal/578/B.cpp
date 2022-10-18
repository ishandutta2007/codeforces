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

int n, k, x;
int a[MAXN];
int pref[MAXN];
int suff[MAXN];

bool read() {
  if  (scanf("%d%d%d", &n, &k, &x) < 3) {
    return false;
  }
  forn(i, n) {
    scanf("%d", &a[i]);
  }
  return true;
}

void precalc() {
  pref[0] = a[0];
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] | a[i];
  }
  suff[n - 1] = a[n - 1];
  ford(i, n - 1) {
    suff[i] = suff[i + 1] | a[i];
  }
}

int get_or(int pos) {
  int ans = 0;
  if  (pos > 0) {
    ans |= pref[pos - 1];
  }
  if  (pos + 1 < n) {
    ans |= suff[pos + 1];
  }
  return ans;
}

ll solve() {
  precalc();

  ll ans = 0;
  ll nx = 1;
  forn(it, k) {
    nx *= x;
  }
  forn(i, n) {
    ans = max(ans, get_or(i) | (a[i] * nx));  
  }                                         
  return ans;
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