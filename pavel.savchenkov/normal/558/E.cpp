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
const int MAXN = 1e5 + 10;
const int A = 26;

struct SegmTree {
  vi t;
  vi to_put;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    t.assign(sz * 2, 0);
    to_put.assign(sz * 2, -1);
  }

  void push(int v, int tl, int tr) {
    if  (to_put[v] == -1) {
      return;
    }
    to_put[v * 2] = to_put[v * 2 + 1] = to_put[v];
    t[v * 2] = t[v * 2 + 1] = to_put[v] * ((tr - tl + 1) / 2);
    to_put[v] = -1;
  }

  void put(int v, int tl, int tr, int l, int r, int val) {
    l = max(l, tl);
    r = min(r, tr);
    if  (l > r) {
      return;
    }

    if  (l == tl && r == tr) {
      to_put[v] = val;
      t[v] = val * (tr - tl + 1);
      return;  
    }

    push(v, tl, tr);

    int tm = (tl + tr) / 2;
    put(v * 2, tl, tm, l, r, val);
    put(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }

  void put(int l, int r, int val) {
    put(1, 0, sz - 1, l, r, val);
  }

  int sum(int v, int tl, int tr, int l, int r) {
    l = max(l, tl);
    r = min(r, tr);

    if  (l > r) {
      return 0;
    }

    if  (l == tl && r == tr) {
      return t[v];
    }

    push(v, tl, tr);

    int tm = (tl + tr) / 2;
    int res = sum(v * 2, tl, tm, l, r) + sum(v * 2 + 1, tm + 1, tr, l, r);
    t[v] = t[v * 2] + t[v * 2 + 1];
    return res;
  }

  int sum(int l, int r) {
    return sum(1, 0, sz - 1, l, r);
  }
};

char s[MAXN];
int n, q;
SegmTree T[A];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d%d\n", &n, &q);
  gets(s);
  forn(c, A) {
    T[c] = SegmTree(n);
  }
  forn(i, n) {
    int c = s[i] - 'a';
    T[c].put(i, i, 1);
  }

  while (q --> 0) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    --l;
    --r;

    if  (k == 0) {
      // zzz 
      int border = l;
      ford(c, A) {
        int cnt = T[c].sum(l, r);
        T[c].put(l, r, 0);
        T[c].put(border, border + cnt - 1, 1);
        border += cnt;  
      }
    } else {
      int border = l;
      forn(c, A) {
        int cnt = T[c].sum(l, r);
        T[c].put(l, r, 0);
        T[c].put(border, border + cnt - 1, 1);
        border += cnt;  
      }      
    }
  }
  
  forn(i, n) {
    forn(c, A) {
      if  (T[c].sum(i, i)) {
        s[i] = c + 'a';
      }
    }
  }
  puts(s);


  return 0;
}