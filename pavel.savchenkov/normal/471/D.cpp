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
const int MOD[2] = { (int) 1e9 + 7, (int) 1e9 + 17 };
const int MAXN = 2e5 + 10;

inline void add(int& x, int y, int m) {
  ((x += y) >= m) && (x -= m);
}

inline int mul(int x, int y, int m) {
  return x * 1ll * y % m;
}

struct Hash {
  static const int S = 2;

  int v[S];

  Hash(int x = 0) {
    forn(i, S) v[i] = x;
  }

  Hash& operator += (const Hash& h) {
    forn(i, S) add(v[i], h.v[i], MOD[i]);
    return *this;
  }

  Hash& operator -= (const Hash& h) {
    forn(i, S) add(v[i], -h.v[i] + MOD[i], MOD[i]);
    return *this;
  }

  Hash& operator *= (const Hash& h) {
    forn(i, S) v[i] = mul(v[i], h.v[i], MOD[i]);
    return *this;
  }

  bool operator == (const Hash& h) const {
    forn(i, S) if  (v[i] != h.v[i]) return false;
    return true;
  }
};

const int PP = (int) 1e6 + 7;

Hash P[MAXN];

void precalc() {
  P[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    P[i] = P[i - 1];
    P[i] *= PP;
  }
}

struct Hasher {
  vector<Hash> pref;

  Hasher() {}

  Hasher(const vi& a) {
    pref.resize(sz(a) + 1);
    pref[0] = 0;
    forn(i, sz(a)) {
      Hash cur = a[i] + 1;
      cur *= P[i];
      pref[i + 1] = pref[i];
      pref[i + 1] += cur;
    }
  }

  Hash hash(int l, int r) {
    Hash res = pref[r + 1];
    res -= pref[l];
    res *= P[MAXN - 1 - r];
    return res;
  }
};

vi reduce(const vi& a) {
  vi b(sz(a) - 1);
  forn(i, sz(b)) {
    b[i] = a[i + 1] - a[i];
  }
  return b;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  precalc();

  int n, w;
  scanf("%d%d", &n, &w);
  vi a(n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }
  vi b(w);
  forn(i, w) {
    scanf("%d", &b[i]);
  }

  a = reduce(a);
  b = reduce(b);

  if  (b.empty()) {
    printf("%d\n", n);
    return 0;
  }

  vi c;
  forn(i, sz(a)) c.pb(a[i]);
  forn(i, sz(b)) c.pb(b[i]);

  sort(all(c));
  c.resize(unique(all(c)) - c.begin());

  forn(i, sz(a)) a[i] = lower_bound(all(c), a[i]) - c.begin();
  forn(i, sz(b)) b[i] = lower_bound(all(c), b[i]) - c.begin();

  Hasher A(a);
  Hasher B(b);

  int ans = 0;
  forn(i, sz(a) - sz(b) + 1) {
    ans += A.hash(i, i + sz(b) - 1) == B.hash(0, sz(b) - 1);
  }
  cout << ans << endl;

  return 0;
}