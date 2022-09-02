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

const int MOD = 1000000007;

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

struct map_with_reset {
  int version;
  map<int, pair<int, int>> values;

  map_with_reset() : version(1) {

  }

  int &operator[](int key) {
    auto &x = values[key];
    if (x.second != version) {
      x.first = 0;
      x.second = version;
    }
    return x.first;
  }

  void reset() {
    version++;
  }

  vector<int> keys() {
    vector<int> r;
    for (auto x : values) {
      r.push_back(x.first);
    }
    return r;
  }
};

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    set<int> values;
    map_with_reset m;
    values.insert(1e9 + 1);
    m[1e9 + 1] = 1;
    for (int i = 0; i < n; i++) {
      int t;
      if (scanf(" ADD %d", &t) == 1) {
        auto it = values.lower_bound(t);
        m[t] = m[*it];
        values.insert(t);
      } else if (scanf("CCEPT %d", &t) == 1) {
        auto it = values.find(t);
        assert(it != values.end());
        int cur = m[*it];
        it++;
        assert(it != values.end());
        add(cur, m[*it]);
        m.reset();
        values.erase(t);
        m.values.erase(t);
        m[*it] = cur;
      } else {
        assert(false);
      }
    }

    int ans = 0;
    for (int x : values) {
      add(ans, m[x]);
    }
    printf("%d\n", ans);
  }




  return 0;
}