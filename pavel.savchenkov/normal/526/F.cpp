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
const int MAXN = 3e5 + 10;
const int INF = 1e9;

struct Mass {
  int* a;
  int* when;
  int timer;

  Mass() {
    timer = 0;
  
    a = (new int[4 * MAXN]) + (2 * MAXN);
    when = (new int[4 * MAXN]) + (2 * MAXN);
  }

  void clear() {
    ++timer;
  }

  int operator[](int i) {
    return when[i] < timer ? 0 : max(0, a[i]);
  }

  void inc(int i, int v) {
    if  (when[i] < timer) {
      a[i] = 0;
    }

    a[i] += v;
    when[i] = timer;
  }
};

int p[MAXN];
Mass cnt;
ll ans = 0;
int mn_l[MAXN];
int mx_r[MAXN];
int mn_r[MAXN];
int mx_l[MAXN];

int func(int i) {
  return i - mn_l[i];
}

int occur[MAXN];

void dec(int i) {
  if  (occur[i] == 2) {
    cnt.inc(func(i), -1);
  }
  --occur[i];
}

void inc(int i) {
  ++occur[i];
  if  (occur[i] == 2) {
    cnt.inc(func(i), +1);
  }
}

void precalc(int l, int r) {
  int m = (l + r) / 2;
  mn_r[m + 1] = mx_r[m + 1] = p[m + 1];
  for (int i = m + 2; i <= r; ++i) {  
    mx_r[i] = max(p[i], mx_r[i - 1]);
    mn_r[i] = min(p[i], mn_r[i - 1]);  
  }

  mn_l[m] = mx_l[m] = p[m];
  for (int i = m - 1; i >= l; --i) {
    mn_l[i] = min(mn_l[i + 1], p[i]);
    mx_l[i] = max(mx_l[i + 1], p[i]);
  }
}

void go(int l, int r) {
  if  (l == r) {
    ++ans;
    return;
  }

  int m = (l + r) / 2;
  go(l, m);
  go(m + 1, r);

  forn(it, 2) {
    // mx in right, mn in left

    for (int i = l; i <= r; ++i) {
      occur[i] = 0;
    }
    cnt.clear();

    precalc(l, r);

    for (int i = l; i <= r; ++i) {
      inc(i);
    }

    int pref = m;
    int suff = m + 1;
    for (int b = m + 1; b <= r; ++b) {
      // mx1 < mx2
      while (suff - 1 >= l && mx_l[suff - 1] < mx_r[b]) {
        inc(suff - 1);
        --suff;
      }

      // mn1 < mn2
      while (pref >= l && mn_l[pref] > mn_r[b]) {
        dec(pref);
        --pref;
      }
      
      ans += cnt[b - mx_r[b]];
    }
    
    for (int i = l; i <= r; ++i) {
      p[i] = -p[i];
    }
  }

  precalc(l, r);
  
  // mx and mn in left
  for (int i = l; i <= m; ++i) {
    int a = i;
    int len = mx_l[i] - mn_l[i] + 1;
    int b = a + len - 1;

    if  (m + 1 <= b && b <= r && mx_r[b] < mx_l[a] && mn_r[b] > mn_l[a]) {
      ++ans;
    }
  }

  // mx and mn in right
  for (int i = m + 1; i <= r; ++i) {
    int b = i;
    int len = mx_r[b] - mn_r[b] + 1;
    int a = b - len + 1;

    if  (l <= a && a <= m && mx_l[a] < mx_r[b] && mn_l[a] > mn_r[b]) {
      ++ans;
    }
  }
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  int n;
  cin >> n;
  forn(i, n) {
    int r, c;
    scanf("%d%d", &r, &c);
    --r;
    --c;

    p[c] = r;
  }

  go(0, n - 1);

  cout << ans << endl;

  return 0;
}