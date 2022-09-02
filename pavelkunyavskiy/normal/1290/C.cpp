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

struct my_set {
  set<int> lf, rg;
  int force = 0;

  int ops() {
    if (force == 0) {
      return min(lf.size(), rg.size());
    }
    if (force == 1) {
      return lf.size();
    }
    if (force == 2) {
      return rg.size();
    }
    assert(false);
  }

  static void merge_sets(set<int> &a, set<int> &&b) {
    if (a.size() < b.size()) {
      a.swap(b);
    }
    for (int x : b) {
      a.insert(x);
    }
    b.clear();
  }

  void merge(my_set &&other) {
    assert(!force || !other.force || force == other.force);
    force = max(force, other.force);
    merge_sets(lf, std::move(other.lf));
    merge_sets(rg, std::move(other.rg));
  }

  int get_color(int x) {
    if (lf.count(x)) return 1;
    assert(rg.count(x));
    return 2;
  }

  void flip() {
    lf.swap(rg);
    if (force) {
      force = 3 - force;
    }
  }

  void enforce(int f) {
    assert(!force || force == f);
    force = f;
  }
};

struct dsu {
  vector<int> p;
  vector<my_set> data;
  dsu(int n) : p(n), data(n) {
    for (int i = 0; i < n; i++) {
      p[i] = i;
      data[i].lf.insert(i);
    }
  }

  int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
  }

  my_set& get_data(int x) {
    return data[get(x)];
  }

  void join(int a, int b) {
    a = get(a);
    b = get(b);
    assert(a != b);
    p[a] = b;
    data[b].merge(std::move(data[a]));
  }
};

constexpr int MAXN = 310000;
char s[MAXN];

int main() {
#ifdef LOCAL
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif
  int n, k;
  while (scanf("%d%d%s", &n, &k, s) == 3) {
    vector<vector<int>> ins(n);

    dsu d(k);

    for (int i = 0; i < k; i++) {
      int sz;
      scanf("%d", &sz);
      for (int j = 0; j < sz; j++) {
        int pos;
        scanf("%d", &pos);
        --pos;
        ins[pos].push_back(i);
      }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (ins[i].empty()) {
        assert(s[i] == '1');
      } else if (ins[i].size() == 1) {
        int op = ins[i][0];
        auto &data = d.get_data(op);
        ans -= data.ops();
        if (s[i] == '1') {
          data.enforce(3 - data.get_color(op));
        } else {
          data.enforce(data.get_color(op));
        }
        ans += data.ops();
      } else if (ins[i].size() == 2) {
        int op1 = ins[i][0];
        int op2 = ins[i][1];
        bool should_change = s[i] == '0';
        bool would_change = d.get_data(op1).get_color(op1) != d.get_data(op2).get_color(op2);

        if (d.get(op1) == d.get(op2)) {
          assert(should_change == would_change);
        } else {
          if (should_change != would_change) {
            d.get_data(op2).flip();
          }
          ans -= d.get_data(op1).ops();
          ans -= d.get_data(op2).ops();
          d.join(op1, op2);
          ans += d.get_data(op1).ops();
        }
      } else {
        assert(false);
      }
      printf("%d\n", ans);
    }
  }

  return 0;
}