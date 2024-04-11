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

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int add(int x, int y) {
  return (x + y) % MOD;
}

int mult(int x, int y) {
  return x * 1ll * y % MOD;
}

struct SegmTree {
  vi mx;
  vi cnt;
  vi cnt_mx;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    mx.assign(sz * 2, -1);
    cnt.assign(sz * 2, 1);
    cnt_mx.resize(sz * 2);

    init(1, 0, sz - 1);
  }

  void init(int v, int tl, int tr) {
    if  (tl == tr) {
      cnt_mx[v] = cnt[v];
      return;
    }

    int tm = (tl + tr) >> 1;
    init(v * 2, tl, tm);
    init(v * 2 + 1, tm + 1, tr);

    cnt_mx[v] = tr - tl + 1;
  }

  void put(int pos, int val, int c) {
    put(1, 0, sz - 1, pos, val, c);
  }

  void put(int v, int tl, int tr, int pos, int val, int c) {
    if  (tl == tr) {
      mx[v] = val;
      cnt[v] = c;
      cnt_mx[v] = c;
      return;
    }

    int tm = (tl + tr) >> 1;
    if  (pos <= tm) {
      put(v * 2, tl, tm, pos, val, c);
    } else {
      put(v * 2 + 1, tm + 1, tr, pos, val, c);
    }

    cnt_mx[v] = 0;
    mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
    if  (mx[v] == mx[v * 2]) {
      cnt_mx[v] = add(cnt_mx[v], cnt_mx[v * 2]);  
    }
    if  (mx[v] == mx[v * 2 + 1]) {
      cnt_mx[v] = add(cnt_mx[v], cnt_mx[v * 2 + 1]);  
    }
  }

  int get_max(int l, int r) {
    return get_max(1, 0, sz - 1, l, r);
  }

  int get_max(int v, int tl, int tr, int l, int r) {
    l = max(tl, l);
    r = min(tr, r);

    if  (l > r) {
      return -1;
    }

    if  (l == tl && r == tr) {
      return mx[v];
    }

    int tm = (tl + tr) >> 1;
    return max(get_max(v * 2, tl, tm, l, r), get_max(v * 2 + 1, tm + 1, tr, l, r));
  }

  int get_cnt(int l, int r) {
    return get_cnt(1, 0, sz - 1, l, r).second;
  }

  pii get_cnt(int v, int tl, int tr, int l, int r) {
    l = max(tl, l);
    r = min(tr, r);

    if  (l > r) {
      return mp(-1, 1);
    }

    if  (l == tl && r == tr) {
      return mp(mx[v], cnt_mx[v]);
    }

    int tm = (tl + tr) >> 1;
    auto left = get_cnt(v * 2, tl, tm, l, r);
    auto right = get_cnt(v * 2 + 1, tm + 1, tr, l, r);
    auto res = max(left, right);
    if  (left.f == right.f) {
      res.s = add(left.s, right.s);
    }
    return res;
  }

  pii get(int pos) {
    return get(1, 0, sz - 1, pos);
  }

  pii get(int v, int tl, int tr, int pos) {
    if  (tl == tr) {
      return mp(mx[v], cnt[v]);
    }

    int tm = (tl + tr) >> 1;
    if  (pos <= tm) {
      return get(v * 2, tl, tm, pos);
    } else {
      return get(v * 2 + 1, tm + 1, tr, pos);
    }
  }
};

SegmTree T;
int a[MAXN];
int n;

int left_len[MAXN];
int left_cnt[MAXN];

int right_len[MAXN];
int right_cnt[MAXN];

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

  int max_a = 0;
  scanf("%d", &n);
  forn(i, n) {
    scanf("%d", &a[i]);
    max_a = max(max_a, a[i]);
  }

  int max_len = 0;

  T = SegmTree(max_a + 1);
  
  int val, cnt;
  tie(val, cnt) = T.get(0);
  T.put(0, 0, 1);

  forn(i, n) {
    left_len[i] = T.get_max(0, a[i] - 1);
    left_cnt[i] = T.get_cnt(0, a[i] - 1);
    ++left_len[i];

    int val, cnt;
    tie(val, cnt) = T.get(a[i]);

    int nval = left_len[i];
    int ncnt = nval == val ? add(cnt, left_cnt[i]) : left_cnt[i];

    T.put(a[i], nval, ncnt);
  }


  reverse(a, a + n);
  forn(i, n) {
    a[i] = max_a - a[i] + 1;
  }

  T = SegmTree(max_a + 1);
  
  tie(val, cnt) = T.get(0);
  T.put(0, 0, 1);

  forn(i, n) {
    right_len[i] = T.get_max(0, a[i] - 1);
    right_cnt[i] = T.get_cnt(0, a[i] - 1);
    ++right_len[i];

    int val, cnt;
    tie(val, cnt) = T.get(a[i]);

    int nval = right_len[i];
    int ncnt = nval == val ? add(cnt, right_cnt[i]) : right_cnt[i];

    T.put(a[i], nval, ncnt);
  }

  reverse(right_cnt, right_cnt + n);
  reverse(right_len, right_len + n);


  forn(i, n) {
//    printf("left_len = %d, left_cnt = %d\n", left_len[i], left_cnt[i]);
//    printf("right_len = %d, right_cnt = %d\n", right_len[i], right_cnt[i]);
    max_len = max(max_len, left_len[i]);
    max_len = max(max_len, right_len[i]);
  }

  int all_cnt = 0;
  forn(i, n) {
    if  (left_len[i] == max_len) {
      all_cnt = add(all_cnt, left_cnt[i]);
    }
  }

//  printf("max_len = %d, all_cnt = %d\n", max_len, all_cnt);

  forn(i, n) {
    int cur_len = left_len[i] + right_len[i] - 1;

    if  (cur_len == max_len) {
      int cnt = mult(left_cnt[i], right_cnt[i]);

      if  (cnt == all_cnt) {
        putchar('3');
      } else {
        putchar('2');
      }
    } else {
      putchar('1');
    } 
  }

	return 0;
}