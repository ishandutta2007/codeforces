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
const int MOD[2] = { (int) 1e9 + 7, (int) 1e9 + 17 };

void add(int& x, int y, int m) {
  ((x += y) >= m) && (x -= m);
}

int mul(int x, int y, int m) {
  return x * 1ll * y % m;
}

struct Hash {
  static const int SZ = 2;

  int v[SZ];

  Hash(int vv = 0) {
    forn(i, SZ) v[i] = vv % MOD[i];
  }

  void operator += (const Hash& other) {
    forn(i, SZ) {
      add(v[i], other.v[i], MOD[i]);
    }
  }

  void operator *= (const Hash& other) {
    forn(i, SZ) {
      v[i] = mul(v[i], other.v[i], MOD[i]);
    }
  }

  void operator *= (int x) {
    forn(i, SZ) {
      v[i] = mul(v[i], x, MOD[i]);
    }
  }

  bool operator == (const Hash& other) const {
    forn(i, SZ) {
      if  (v[i] != other.v[i]) {
        return false;
      }
    }
    return true;
  }

  void print() const {
    printf("%d %d\n", v[0], v[1]);  
  }
};

const int MAXN = 2e5 + 10;
const int PP = 29;

Hash P[MAXN];

void precalc() {
  P[0] = Hash(1);
  for (int i = 1; i < MAXN; ++i) {
    P[i] = P[i - 1];
    P[i] *= PP;
  }
}

struct SegmTree {
  vector<Hash> t;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;
    t.assign(sz * 2, Hash(0));
  } 
  /*
  void put(int v, int tl, int tr, int pos, const Hash& val) {
    if  (tl == tr) {
      t[v] = val;
      return;
    }

    int tm = (tl + tr) / 2;
    if  (pos <= tm) {
      put(v * 2, tl, tm, pos, val);
    } else {
      put(v * 2 + 1, tm + 1, tr, pos, val);
    }
  }
  */

  void put(int pos, const Hash& val) {
    /*
    put(1, 0, sz - 1, pos, val);
    return;
    */
    /*
    t[pos] = val;
    return;
    */

    int v = sz + pos;
    t[v] = val;
    v /= 2;
    while (v) {
      t[v] = t[v * 2];
      t[v] += t[v * 2 + 1];
      v /= 2;
    }
  }

  Hash get_hash(int l, int r) {
    /*
    auto res = get_hash(1, 0, sz - 1, l, r);
    res *= P[MAXN - r - 1];
    */
/*
    Hash res(0);
    for (int i = l; i <= r; ++i) {
      res += t[i];
    }
    res *= P[MAXN - 1 - r];
    return res;
*/

    auto coef = P[MAXN - r - 1];
    l += sz;
    r += sz;
    Hash res(0);
    while (l <= r) {
      if  (l & 1) {
        res += t[l];
      }
      if  (~r & 1) {
        res += t[r];
      }
      l = (l + 1) / 2;
      r = (r - 1) / 2;
    }
    res *= coef;
    return res;   
  }
};

const int A = 26;

SegmTree T[A];

pair<Hash, pair<vi, vi>> get_hash(char* s) {
  int n = strlen(s);

  vi order;
  forn(c, A) {
    order.pb(c);
  }
  vi last(A, MAXN);
  ford(i, n) {
    last[s[i] - 'a'] = i;
  }
  sort(all(order), [&](int c1, int c2) {
    if  (last[c1] != last[c2]) {
      return last[c1] < last[c2];
    }
    return c1 < c2;
  });
  vi pos(A, -1);
  forn(i, A) {
    pos[order[i]] = i;
  }
/*
  forn(i, A) {
    printf("order[%d] = %d\n", i, order[i]);
  }
*/

  Hash h(0);
  forn(i, n) {
    Hash cur(pos[s[i] - 'a'] + 1);
    cur *= P[i];
    h += cur;
  }
  h *= P[MAXN - 1 - (n - 1)];
  return mp(h, mp(order, last));
}

int ls, lt;
char s[MAXN];
char t[MAXN];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif

  precalc();
  
  scanf("%d%d\n", &ls, &lt);
  gets(s);
  gets(t);

  Hash th;
  vi order_t;
  vi last_t;
  auto tmp = get_hash(t);
  th = tmp.fst;
  order_t = tmp.snd.fst;
  last_t = tmp.snd.snd;
  forn(c, A) {
    T[c] = SegmTree(ls);
  }
//  puts("th:");
//  th.print();

  vi res;
  vi order;
  forn(c, A) {
    order.pb(c);
  }
  vi last(A, MAXN);
  ford(i, ls) {
    last[s[i] - 'a'] = i;
    T[s[i] - 'a'].put(i, P[i]);
    forn(c, A) if  (last[c] >= i + lt) last[c] = MAXN;
    sort(all(order), [&](int c1, int c2) {
      if  (last[c1] != last[c2])
        return last[c1] < last[c2];
      return c1 < c2;
    });
  /*
    printf("i = %d\n", i);
    forn(c, A) {
      printf("order[%d] = %d\n", c, order[c]);
    }
    puts("\n");
  */
    vi pp(A, -1);
    bool ok = true;
    if  (i + lt - 1 < ls) {
      forn(ii, A) {
        if  (last[order[ii]] == MAXN) {
          if  (last_t[order_t[ii]] != MAXN) {
         //   printf("ii=%d, c=%d, cc=%d\n", ii, order[ii], order_t[ii]);
            ok = false;
          }
          continue;
        }
        if  (last[order[ii]] - i != last_t[order_t[ii]]) {
        //  printf("%d %d\n", last[order[ii]] - i, last_t[order_t[ii]]);
          ok = false;
        }
      }

      Hash h(0);
      forn(id, A) {
        if  (last[order[id]] == MAXN) {
          continue;
        }
        int c = order[id];
        int c2 = order_t[id];

        if  (pp[c] != -1 && pp[c] != c2) {
          ok = false;
        }
        if  (pp[c2] != -1 && pp[c2] != c) {
          ok = false;
        }
        pp[c2] = c;
        pp[c] = c2;

        Hash cur = T[c].get_hash(i, i + lt - 1);
        cur *= id + 1;
        h += cur;
      } 
    //  h.print();

      if  (ok && h == th) {
        res.pb(i);
      }
    //  puts("");
    }
  }

  sort(all(res));
  printf("%d\n", sz(res));
  for (int i : res) {
    printf("%d ", i + 1);
  }
  puts("");


  return 0;
}