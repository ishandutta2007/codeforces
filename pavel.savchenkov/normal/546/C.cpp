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

const int MOD[2] = { (int) 1e9 + 7, (int) 1e9 + 17 };

inline void add(int& x, int y, int m) {
  ((x += y) >= m) && (x -= m);
}

inline int mul(int x, int y, int m) {
  return x * 1ll * y % m;
}

struct Hash {
  int v[2];

  Hash(int x = 0) {
    forn(i, 2) v[i] = x;
  }

  void operator += (const Hash& other) {
    forn(i, 2) add(v[i], other.v[i], MOD[i]);
  }

  void operator *= (const Hash& other) {
    forn(i, 2) v[i] = mul(v[i], other.v[i], MOD[i]);
  }

  bool operator < (const Hash& other) const {
    forn(i, 2) if  (v[i] != other.v[i]) return v[i] < other.v[i];
    return false;
  }
};

const ld EPS = 1e-9;
const int P = 11;

#define Hash ull

Hash hash(int* a, int n) {
  Hash h = 0;
  Hash p = 1;
  forn(i, n) {
    Hash cur = p;
    cur *= a[i];
    h += cur;
    p *= P;
  } 
  return h;
}

const int MAXN = 12345;

void read(int* a, int& l, int& r) {
  int k;
  scanf("%d", &k);
  l = 0;
  r = k;
  forn(i, k) scanf("%d", &a[i]);
}

int a[MAXN];
int la, ra;

int b[MAXN];
int lb, rb;

void go() {
  if  (a[la] > b[lb]) {
    a[ra++] = b[lb];
    a[ra++] = a[la];
  } else {
    b[rb++] = a[la];
    b[rb++] = b[lb];
  }
  ++la;
  ++lb;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int n;
  scanf("%d", &n);

  read(a, la, ra);
  read(b, lb, rb);

  set<pair<Hash, Hash>> was;
  int moves = 0;
  while (1) {
    go();
    ++moves;

    if  (la == ra) {
      printf("%d 2\n", moves);
      return 0;
    }

    if  (lb == rb) {
      printf("%d 1\n", moves);
      return 0;
    }

    auto h = mp(hash(a + la, ra - la), hash(b + lb, rb - lb));
    if  (was.count(h)) {
      puts("-1");
      return 0;
    }
    was.insert(h);
  }
  return 0;
}