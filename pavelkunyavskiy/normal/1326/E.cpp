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
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

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

class SegmentTree {
  typedef int value_t;
  typedef int update_t;

  static constexpr value_t EMPTY_VALUE = -1e9;
  static constexpr update_t EMPTY_UPDATE = 0;

  static inline value_t merge_values(const value_t &a, const value_t &b) {
    return max(a, b);
  }

  void apply(int v, const update_t &u) { tree[v] += u; upd[v] += u;}

  vector<value_t> tree;
  vector<update_t> upd;
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
    return merge_values(get(2 * v, l, (l + r) / 2, L, R),
                        get(2 * v + 1, (l + r) / 2, r, L, R));
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
  void init(vector<int> vals) {
    int n = vals.size();
    lst = 2;
    while (lst < n)
      lst *= 2;
    tree.resize(2 * lst, EMPTY_VALUE);
    for (int i = 0; i < n; i++) {
      tree[i + lst] = vals[i];
    }
    for (int i = lst - 1; i >= 0; i--) {
      tree[i] = merge_values(tree[2 * i], tree[2 * i + 1]);
    }
    while ((int)tree.size() < 2 * lst) tree.push_back(EMPTY_VALUE);
    upd = vector<update_t>((size_t)(2 * lst), EMPTY_UPDATE);
  }

  value_t get(int l, int r) {
    value_t res = get(1, 0, lst, l, r);
    return res;
  }

  void update(int l, int r, update_t u) {
    return update(1, 0, lst, l, r, u);
  }

  void dump() {
    for (int i = 0; i < lst; i++) {
      eprintf("%d ", get(i, i + 1));
    }
    eprintf("\n");

  }
};

int main() {
#ifdef LOCAL
  freopen("e.in", "r", stdin);
  freopen("e.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<int> p(n);
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      p[x - 1] = i;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &q[i]);
      --q[i];
    }

    int vptr = n;
    int dptr = 0;

    SegmentTree t;
    t.init(vector<int>(2 * n, 0));
    vector<int> ans(n);

//    t.dump();

    while (dptr < n) {
      while (t.get(0, 2 * n) <= 0) {
        assert(vptr);
        t.update(0, 2 * p[--vptr] + 1, 1);
      }
      ans[dptr] = vptr;
      t.update(0, 2 * q[dptr++] + 2, -1);
//      t.dump();
    }

    for (int x : ans) {
      printf("%d ", x + 1);
    }
    printf("\n");

  }

  return 0;
}