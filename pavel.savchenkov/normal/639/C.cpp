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
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const int MAXN = 2e5 + 10;

int a[MAXN];
int c[2 * MAXN];
int n, k;

bool read() {
  if  (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  forn(i, n + 1) {
    scanf("%d", &a[i]);
  }
  return true;
}

void change(int i, int diff) {
  c[i] += diff;
  if  (abs(c[i]) <= 1) {
    return;
  }
  change(i + 1, c[i] / 2);
  c[i] %= 2;
}

int solve() {
  memset (c, 0, sizeof c);
  forn(i, n + 1) {
    change(i, a[i]);
  }

  int left = 0;
  while (!c[left]) ++left;
  assert(c[left]);
  
  int right = n + 100;
  while (!c[right]) --right;

  if  (right - left + 1 > 63) {
    return 0;
  }

  const ll INF = 1e18;
  ll val = 0;
  int ans = 0;
  for (int i = right; i >= 0; --i) {
    val = val * 2 + c[i];
    if  (abs(val) > INF) {
      return ans;
    }
    if  (i <= left && i <= n) {
      ll add = -val;
      ll new_val = a[i] + add;
      if  (abs(new_val) <= k && (i < n || new_val != 0)) {
        ++ans;
      }
    }
  }
  return ans;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  //freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    printf("%d\n", solve());
  }

#ifdef LOCAL
  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}