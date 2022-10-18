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

const int MAXN = 150000 + 10;

int t[MAXN];
int n;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return false;
  }
  forn(i, n) {
    scanf("%d", &t[i]);
  }
  return true;
}

bool ok[MAXN];
int sum[MAXN];

int get_sum(int l, int r) {
  if  (l > r) return 0;
  return sum[r + 1] - sum[l];
}

int last[MAXN];

bool is_ok(int);

bool check(int i, int j) {
  if  (i > j) swap(i, j);

  swap(t[i], t[j]);
  int cnt = get_sum(0, i - 2);
  cnt += get_sum(i + 2, j - 2);
  cnt += get_sum(j + 2, n - 1);

  static int it = 0;
  ++it;
  for (int k = max(0, i - 1); k <= i + 1 && k < n; ++k) {
    last[k] = it;
    cnt += is_ok(k);
  } 
  for (int k = max(0, j - 1); k <= j + 1 && k < n; ++k) {
    if  (last[k] == it) {
      continue;
    }
    cnt += is_ok(k);
  }
  swap(t[i], t[j]);
  return cnt == n;
}

bool is_ok(int i) {
    if  (i == n - 1) return true;
    if  (i % 2 == 0) {
      return t[i] < t[i + 1];
      int mn = MAXN;
      if  (i - 1 >= 0) {
        mn = min(mn, t[i - 1]);
      } 
      if  (i + 1 < n) {
        mn = min(mn, t[i + 1]);
      }
      return t[i] < mn;
    } else {
      return t[i] > t[i + 1];
      int mx = -MAXN;
      if  (i - 1 >= 0) {
        mx = max(mx, t[i - 1]);
      }
      if  (i + 1 < n) {
        mx = max(mx, t[i + 1]);
      }
      return t[i] > mx;
    }
}

int solve() {
  sum[0] = 0;
  forn(i, n) {
    ok[i] = is_ok(i);
    sum[i + 1] = sum[i] + ok[i];
  }

  int bad = n - get_sum(0, n - 1);
  assert(bad);
  if  (bad > 20) {
    return 0;
  }

  vi a;
  forn(i, n) {
    if  (!ok[i]) {
      a.pb(i);
      if  (i - 1 >= 0) a.pb(i - 1);
      if  (i + 1 < n) a.pb(i + 1);
    }
  }

  sort(all(a));
  a.resize(unique(all(a)) - a.begin());
  for (int i : a) ok[i] = false;

  /*
  forn(i, n) {
    printf("%d", ok[i]);
  }
  puts("");
  */

  memset (last, -1, sizeof last);
  int ans = 0;
  for (int i : a) {
    forn(j, n) {
      if  (!ok[j] && j <= i) {
        continue;
      }
      if  (check(i, j)) {
      //  printf("%d %d\n", i, j);
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
    break;
  }
  
#ifdef DEBUG
  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}