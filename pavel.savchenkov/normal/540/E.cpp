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

map<int, int> pos;
map<int, int> who_pos;

void sw(int a, int b) {
  if  (!pos.count(a)) {
    pos[a] = a;
    who_pos[a] = a;
  }
  if  (!pos.count(b)) {
    pos[b] = b;
    who_pos[b] = b;
  }

  int pa = pos[a];
  int pb = pos[b];
  who_pos[pa] = b;
  who_pos[pb] = a;
  pos[a] = pb;
  pos[b] = pa;
}

struct FenwTree {
  vi t;

  FenwTree(int n = 0) {
    t.assign(n, 0);
  }

  void upd(int pos, int val) {
    for (int i = pos; i < sz(t); i |= i + 1) {
      t[i] += val;
    }
  }

  int get(int r) {
    int res = 0;
    for (int i = r; i >= 0; i &= i + 1, --i) {
      res += t[i];
    }
    return res;
  }

  int get(int l, int r) {
    return get(r) - get(l - 1);
  }
};

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  vi c;
  int n;
  cin >> n;
  forn(i, n) {
    int a, b;
    scanf("%d%d", &a, &b);
    sw(a, b);
    c.pb(a);
    c.pb(b);
  }

  sort(all(c));
  c.resize(unique(all(c)) - c.begin());

  vi val;
  vi p;
  for (const auto& it : pos) {
    p.pb(it.fst);
    val.pb(it.snd);
  }
  val.pb((int) 1e9);
  p.pb((int) 1e9);
/*
  printf("sz(c) = %d\n", sz(c));

  forn(i, sz(val)) {
    printf("%d %d\n", p[i], val[i]);
  }
*/
  ll ans = 0;
  FenwTree T(sz(c));
  ford(i, sz(val) - 1) {
    int v = lower_bound(all(c), val[i]) - c.begin();
    ans += T.get(v - 1);  
    T.upd(v, +1);

    if  (p[i] >= val[i]) {
      int l = lower_bound(all(p), val[i]) - p.begin();
//      printf("val=%d, l = %d\n", val[i], l);
      int have = i - l + 1;
      int all = p[i] - p[l] + 1;
      ans += all - have;
      ans += max(0, (p[l] - 1) - (val[i] + 1) + 1);
      continue;
    }

    int r = lower_bound(all(p), val[i]) - p.begin();
//    printf("val=%d, r = %d\n", val[i], r);

    int have = (r - 1) - i + 1;
    int all = p[r - 1] - p[i] + 1;
//    printf("all = %d, have = %d\n", all, have);
    ans += all - have;
    ans += max(0, (val[i] - 1) - (p[r - 1] + 1) + 1);
  }

  cout << ans << endl;

  return 0;
}