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
const int MAXN = 5e5 + 10;
const int MOD[2] = { (int) 1e9 + 7, (int) 1e9 + 17 };

void add(int& x, int y, int m) {
  ((x += y) >= m) && (x -= m);
}

int mul(int x, int y, int m) {
  return x * 1ll * y % m;
}

struct Hash {
  int v1, v2;

  Hash(int v = 0) {
    v1 = v2 = v;
  }

  void operator += (const Hash& other) {
    add(v1, other.v1, MOD[0]);
    add(v2, other.v2, MOD[1]);
  }

  void operator -= (const Hash& other) {
    add(v1, -other.v1 + MOD[0], MOD[0]);
    add(v2, -other.v2 + MOD[1], MOD[1]);
  }

  void operator *= (const Hash& other) {
    v1 = mul(v1, other.v1, MOD[0]);
    v2 = mul(v2, other.v2, MOD[1]);
  }

  bool operator < (const Hash& other) const {
    if  (v1 != other.v1) {
      return v1 < other.v1;
    }
    return v2 < other.v2;
  }

  bool operator != (const Hash& other) const {
    return v1 != other.v1 || v2 != other.v2;
  }

  bool operator == (const Hash& other) const {
    return v1 == other.v1 && v2 == other.v2;
  }

  int id() const {
    return v1 + v2;
  }

  void print() const {
    printf("%d %d\n", v1, v2);
  }
};

const int PP = 29;
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

  Hasher(const string& s) {
    pref.assign(sz(s) + 1, 0);
    forn(i, sz(s)) {
      Hash cur = s[i] - 'a' + 1;
      cur *= P[i];
      pref[i + 1] = pref[i];
      pref[i + 1] += cur;
    }
  }

  Hash get(int l, int r) {
    Hash res = pref[r + 1];
    res -= pref[l];
    res *= P[MAXN -  1 - r];
    return res;
  }
};

struct HashTable {
  static const int SZ = 1 << 20;
  pair<Hash, int> T[SZ];

  HashTable() {
    forn(i, SZ) T[i].snd = -1;
  }

  void put(const Hash& h, int val) {
    int v = h.id() & (SZ - 1);
    while (T[v].fst != h && T[v].snd != -1) {
      ++v;
      if  (v == SZ) {
        v = 0;
      }
    }

    T[v] = mp(h, val);
  }

  int get(const Hash& h) {
    int v = h.id() & (SZ - 1);
    while (T[v].fst != h && T[v].snd != -1) {
      ++v;
      if  (v == SZ) {
        v = 0;
      }
    }

    if  (T[v].fst == h && T[v].snd != -1) {
      return T[v].snd;  
    }
    return -1;
  }
};

HashTable T;
int ans[MAXN];
Hasher str[MAXN];
int len[MAXN];
int n, q;

string read_string() {
  static char buf[MAXN];
  gets(buf);
  return string(buf);
}

struct Query {
  int id, k, neg;
};

vector<Query> qs[MAXN];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  precalc();

  vi lens;
  scanf("%d%d\n", &n, &q);
  forn(i, n) {
    const string& s = read_string();
    lens.pb(sz(s));
    len[i] = sz(s);
    str[i] = Hasher(s);
  }

  forn(i, q) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    --l;
    --r;
    --k;

    qs[r].pb({ i, k, false });
    if  (l - 1 >= 0) {
      qs[l - 1].pb({ i, k, true });
    }
  }

  sort(all(lens));
  lens.resize(unique(all(lens)) - lens.begin());

/*
  forn(i, n) {
    str[i].get(0, len[i] - 1).print();
  }
*/

  vector<Hash> uniq;
  forn(i, n) uniq.pb(str[i].get(0, len[i] - 1));
  sort(all(uniq));
  uniq.resize(unique(all(uniq)) - uniq.begin());

  vi new_pos(n, -1);
  forn(i, n) {
    const auto& h = str[i].get(0, len[i] - 1);
    int pos = lower_bound(all(uniq), h) - uniq.begin();
    new_pos[i] = pos;
  }

  forn(i, n) {
    T.put(str[i].get(0, len[i] - 1), new_pos[i]);
  }

  vi seen(sz(uniq), 0);
  forn(i, n) {
    forn(j, len[i]) {
      for (int L : lens) {
        if  (j + L - 1 >= len[i]) {
          continue;
        }
        auto our = str[i].get(j, j + L - 1);
        int id = T.get(our);
        if  (id != -1) {
          ++seen[id];
        }
      }
    }

    for (auto& q : qs[i]) {
      int val = seen[new_pos[q.k]];
      if  (q.neg) {
        ans[q.id] -= val;
      } else {
        ans[q.id] += val;
      }
    }
  }

  forn(i, q) {
    printf("%d\n", ans[i]);
  }

  return 0;
}