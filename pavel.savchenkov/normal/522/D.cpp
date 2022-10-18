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

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr(T x) {
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
const int MAXN = 5e5 + 10;
const int INF = 1e9;

struct SegmTree {
  vi t;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;

    t.assign(sz * 2, 0);
  }

  void put(int pos, int val) {
    int v = sz + pos;
    t[v] = val;
    v /= 2;
    while (v) {
      t[v] = min(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  int get_min(int l, int r) {
    int res = INF;
    l += sz;
    r += sz;
    while (l <= r) {
      res = min(res, t[l]);
      res = min(res, t[r]);
      l = (l + 1) / 2;
      r = (r - 1) / 2;
    }
    return res;
  }
};

struct Query {
  int l, r, id;

  void read(int _id) {
    id = _id;
    scanf("%d%d", &l, &r);
    --l;
    --r;
  }
};

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  int n, m;
  scanf("%d%d", &n, &m);
  vi a(n);
  vi coord;
  forn(i, n) {
    scanf("%d", &a[i]);
    coord.pb(a[i]);
  }

  sort(all(coord));
  coord.resize(unique(all(coord)) - coord.begin());

  forn(i, n) {
    a[i] = lower_bound(all(coord), a[i]) - coord.begin();
  }

  vi prev(n, -1);
  vi last(sz(coord), -1);
  forn(i, n) {
    prev[i] = last[a[i]];
    last[a[i]] = i;
  }

  vector<vector<Query> > who(n);
  forn(i, m) {
    Query cur;
    cur.read(i);
    who[cur.r].pb(cur);
  }

  vi res(m);

  SegmTree T(n);
  forn(i, n) {
    if  (prev[i] != -1) {
      T.put(prev[i], i - prev[i]);
    }
    T.put(i, INF);
    
    for (auto& q : who[i]) {
      int len = T.get_min(q.l, i);
      if  (len == INF) {
        len = -1;
      }
      res[q.id] = len;
    } 
  }

  forn(i, m) {
    printf("%d\n", res[i]);
  }
  return 0;
}