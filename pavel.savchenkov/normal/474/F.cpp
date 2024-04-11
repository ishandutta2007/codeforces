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

const double EPS = 1e-9;
const int INF = 1e9;

struct SegmTree {
  vii t;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    t.assign(sz * 2, mp(INF, 0));
  }

  void put(int pos, int val) {
    int v = sz + pos;
    t[v] = mp(val, pos);
    v /= 2;
    while (v) {
      t[v] = min(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  int pos_min(int l, int r) {
    pii mn = mp(INF, 0);
    l += sz;
    r += sz;
    while (l <= r) {
      mn = min(mn, t[l]);
      mn = min(mn, t[r]);
      l = (l + 1) / 2;
      r = (r - 1) / 2;
    }
    return mn.snd;
  }
};

vi calc_left(const vi& s) {
  int n = sz(s);
  vi left(n);

  forn(i, n) {
    left[i] = i;
    if  (i == 0 || s[i - 1] % s[i] != 0) {
      continue;
    }

    left[i] = left[i - 1];
    while (left[i] > 0 && s[left[i] - 1] % s[i] == 0) {
      left[i] = left[left[i] - 1];
    }
  }

  return left;
}

SegmTree T;
vi s;
int n;

vvi pos;
vi c;

int coord(int x) {
  return lower_bound(all(c), x) - c.begin();
}

int get_cnt(int x, int l, int r) {
  int cx = coord(x);
  return upper_bound(all(pos[cx]), r) - lower_bound(all(pos[cx]), l);
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d", &n);
  s.resize(n);
  forn(i, n) {
    scanf("%d", &s[i]);
    c.pb(s[i]);
  }

  sort(all(c));
  c.resize(unique(all(c)) - c.begin());
  pos.resize(sz(c));
  forn(i, sz(s)) {
    pos[coord(s[i])].pb(i);
  }

  vi left = calc_left(s);

  reverse(all(s));
  vi right = calc_left(s);
  reverse(all(s));
  reverse(all(right));
  for (int& x : right) x = n - x - 1;

  SegmTree T(n);
  forn(i, n) T.put(i, s[i]);

  int t;
  scanf("%d", &t);
  while (t--) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    --r;

    int p = T.pos_min(l, r);

    int ans = r - l + 1;
    if  (left[p] <= l && r <= right[p]) {
      ans -= get_cnt(s[p], l, r);
    }

    printf("%d\n", ans);
  }

  return 0;
}