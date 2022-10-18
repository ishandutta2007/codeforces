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
const int MAXK = 1e6 + 10;
const int MAXN = 3e5 + 10;

struct SegmTree {
  vii t;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    t.assign(sz * 2, mp(0, 0));
    for (int v = sz; v < sz * 2; ++v) {
      t[v].snd = v - sz;
    }
  }

  void put(int pos, int val) {
    int v = sz + pos;
    t[v] = mp(val, pos);
    v /= 2;
    while (v) {
      t[v] = max(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  pii get_max(int l, int r) {
    l += sz;
    r += sz;
    pii res(-1, 0);
    while (l <= r) {
      res = max(res, t[l]);
      res = max(res, t[r]);
      l = (l + 1) / 2;
      r = (r - 1) / 2;
    }
    return res;
  }
};

vi pos_pref[MAXK];
int a[MAXN];
int n, k;
int pref[MAXN];
SegmTree T;

int cnt_pref(int l, int r, int sum) {
  assert(l <= r);
  assert(0 <= sum && sum < k);
  return upper_bound(all(pos_pref[sum]), r) - lower_bound(all(pos_pref[sum]), l);
}

ll get(int l, int r) {
//  printf("in [%d, %d]\n", l, r);

  if  (l > r) {
    return 0;
  }

  if  (l == r) {
    return 1;
  }

  int pos = T.get_max(l, r).snd;

  ll ans = 0;
  if  (pos - l < r - pos) {
    for (int L = l; L <= pos; ++L) {
      // pref[R + 1] - a[pos] - pref[L] == 0
      // pos <= R <= r
      ans += cnt_pref(pos + 1, r + 1, (a[pos] + pref[L]) % k);
    }
  } else {
    for (int R = pos; R <= r; ++R) {
      // pref[L] = pref[R + 1] - a[pos]
      // l <= L <= pos
      ans += cnt_pref(l, pos, (pref[R + 1] - (a[pos] % k) + k) % k);
    }
  }

//  printf("cur = %I64d\n", ans);
  return ans + get(l, pos - 1) + get(pos + 1, r);
}

void solve() {
  scanf("%d%d", &n, &k);
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  pref[0] = 0;
  forn(i, n) {
    pref[i + 1] = (pref[i] + a[i]) % k;
  }
  forn(i, n + 1) {
    pos_pref[pref[i]].pb(i);
  } 

  T = SegmTree(n);
  forn(i, n) T.put(i, a[i]);

  cout << get(0, n - 1) - n << '\n';
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  solve();

  return 0;
}