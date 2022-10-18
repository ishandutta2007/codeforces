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
const int K = 4000;
const int MAXN = 5e5 + 10;

int a[MAXN];

struct Block {
  vector<pair<ll, int>> vals; // (val, pos)
  int L, R;
  ll add;

  Block() {}

  Block(int l, int r) : L(l), R(r), add(0) {
    for (int i = l; i <= r; ++i) {
      vals.pb(mp(a[i], i));
    }
    sort(all(vals));
  }

  void print() const {
    forn(i, sz(vals)) {
      printf("%I64d %d\n", vals[i].fst, vals[i].snd);
    }
    printf("+= %I64d\n", add);
    puts("");
  }

  void go_add(int l, int r, ll Add) {
    l = max(l, L);
    r = min(r, R);
    if  (l > r) {
      return;
    }
    if  (l == L && r == R) {
      add += Add;
    } else {
      vector<pair<ll, int>> vals1;
      vector<pair<ll, int>> vals2;
      forn(i, sz(vals)) {
        ll val = vals[i].fst;
        int pos = vals[i].snd;
        bool in = l <= pos && pos <= r;
        if  (in) {
          vals1.pb(mp(val + Add, pos));
        } else {
          vals2.pb(mp(val, pos));
        }
      }
      merge(all(vals1), all(vals2), vals.begin());
    }
  }

  int right(ll y) {
    int pos = upper_bound(all(vals), mp(y - add, MAXN)) - vals.begin();
    --pos;
    if  (0 <= pos && pos < sz(vals)) {
      return vals[pos].fst == y - add ? vals[pos].snd : -1;
    }
    return -1;
  }

  int left(ll y) {
    int pos = lower_bound(all(vals), mp(y - add, -1)) - vals.begin();
    if  (0 <= pos && pos < sz(vals)) {
      return vals[pos].fst == y - add ? vals[pos].snd : -1;
    }
    return -1;
  }
};

vector<Block> blocks;
int n, q;

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  cin >> n >> q;
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n; i += K) {
    blocks.pb(Block(i, min(n - 1, i + K - 1)));
  }

  while (q--) {
    int t;
    scanf("%d", &t);

    if  (t == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      --l;
      --r;
      for (auto& b : blocks) {
        b.go_add(l, r, x);
      }
    } else {
      int left = MAXN;
      int right = -1;
      int y;
      scanf("%d", &y);
      for (auto& b : blocks) {
        int l = b.left(y);
        if  (l != -1) left = min(left, l);
        int r = b.right(y);
        if  (r != -1) right = max(right, r);
      }
      printf("%d\n", max(-1, right - left));
    }
  }

  return 0;
}