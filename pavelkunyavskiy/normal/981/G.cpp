#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

using namespace std;

#ifdef LOCAL
static struct __timestamper {
  string what;
  __timestamper(const char* what) : what(what){};
  __timestamper(const string& what) : what(what){};
  ~__timestamper(){
    TIMESTAMPf("%s", what.data());
	}
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;

void add(int &a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}

void sub(int &a, int b) {
  if ((a -= b) < 0) a += MOD;
}

int mul(int a, int b) {
  return (int) ((a * 1LL * b) % MOD);
}

int mpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int minv(int x) {
  return mpow(x, MOD - 2);
}


class SegmentTree {
  typedef int value_t;
  typedef pair<int, int> update_t;

  static const value_t EMPTY_VALUE;
  static const update_t EMPTY_UPDATE;

  static inline value_t merge_values(const value_t &a, const value_t &b) {
    value_t x = a;
    add(x, b);
    return x;
  }

  void apply(int v, const update_t &u) {
    tree[v] = mul(tree[v], u.first);
    add(tree[v], mul(u.second, len[v]));
    upd[v].first = mul(upd[v].first, u.first);
    upd[v].second = mul(upd[v].second, u.first);
    add(upd[v].second, u.second);
  }

  vector<value_t> tree;
  vector<update_t> upd;
  vector<int> len;
  int lst;

  void push(int v) {
    apply(2 * v, upd[v]);
    apply(2 * v + 1, upd[v]);
    upd[v] = EMPTY_UPDATE;
  }

  value_t get(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
      return EMPTY_VALUE;
    }
    if (L <= l && r <= R) {
      return tree[v];
    }
    push(v);
    return merge_values(get(2 * v, l, (l + r) / 2, L, R), get(2 * v + 1, (l + r) / 2, r, L, R));
  }

  void update(int v, int l, int r, int L, int R, const update_t &u) {
    if (r <= L || R <= l) {
      return;
    }
    if (L <= l && r <= R) {
      apply(v, u);
      return;
    }
    push(v);
    update(2 * v, l, (l + r) / 2, L, R, u);
    update(2 * v + 1, (l + r) / 2, r, L, R, u);
    tree[v] = merge_values(tree[2 * v], tree[2 * v + 1]);
  }

public:

  void init(int n) {
    lst = 2;
    while (lst < n) lst *= 2;
    tree = vector<value_t>((size_t) (2 * lst), EMPTY_VALUE);
    upd = vector<update_t>((size_t) (2 * lst), EMPTY_UPDATE);
    len = vector<int>((size_t) 2 * lst, 1);
    for (int i = 0; i < n; i++) {
      len[lst + i] = 1;
    }
    for (int i = lst - 1; i > 0; i--) {
      len[i] = len[2 * i] + len[2 * i + 1];
    }
  }

  void init(vector<value_t> v) {
    int n = (int) v.size();
    lst = 2;
    while (lst < n) lst *= 2;
    tree = vector<value_t>((size_t) 2 * lst, EMPTY_VALUE);
    for (int i = 0; i < n; i++) {
      tree[lst + i] = v[i];
    }
    for (int i = lst - 1; i > 0; i--) {
      tree[i] = merge_values(tree[2 * i], tree[2 * i + 1]);
    }
    upd = vector<update_t>((size_t) 2 * lst, EMPTY_UPDATE);
  }

  value_t get(int l, int r) {
    return get(1, 0, lst, l, r);
  }

  void update(int l, int r, update_t u) {
//    eprintf("%d %d (%d, %d)\n", l, r, u.first, u.second);
    return update(1, 0, lst, l, r, u);
  }
};

const SegmentTree::update_t SegmentTree::EMPTY_UPDATE = pair<int, int>{1, 0};
const SegmentTree::value_t SegmentTree::EMPTY_VALUE = 0;


struct SegmentMerger {
  map<int, int> x;

  SegmentMerger() {
    assert(0);
  }

  SegmentMerger(int n) {
    x[0] = n;
  }

  vector<pair<int, int>> get_segments(int l, int r) {
    auto it = x.upper_bound(l);
    vector<pair<int, int>> res;
    while (it != x.end()) {
      if (it->first >= r) break;
      int rr = it->second;
      res.push_back({it->first, min(r, rr)});
      auto nit = it;
      nit++;
      x.erase(it);
      if (rr > r) {
        x[r] = rr;
        break;
      }
      it = nit;
    }
    it = x.upper_bound(l);
    if (it != x.begin()) {
      it--;
      if (it->second > l) {
        int rr = it->second;
        res.push_back({l, min(rr, r)});
        it->second = l;
        if (it->first == it->second) {
          x.erase(it);
        }
        if (r < rr) {
          x[r] = rr;
        }
      }
    }
    return res;
  }
};


int main() {
#ifdef LOCAL
  freopen("g.in", "r", stdin);
  freopen("g.out", "w", stdout);
#endif

  int n, q;
  scanf("%d%d", &n, &q);

  map<int, SegmentMerger> vals;
  SegmentTree tree;
  tree.init(n);

  int minv2 = minv(2);

  for (int i = 0; i < q; i++) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      l--;
      if (vals.find(x) == vals.end()) {
        vals.emplace(x, SegmentMerger(n));
      }
      for (auto y : vals[x].get_segments(l, r)) {
        tree.update(y.first, y.second, {minv2, minv2});
      }
      tree.update(l, r, {2, 0});
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      --l;
      printf("%d\n", tree.get(l, r));
    }
  }

  return 0;
}