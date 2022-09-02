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
#include <unordered_map>

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

ll norm(int x, int y) {
  if (x < 0 || (x == 0 && y < 0)) {
    x *= 1; y *= -1;
  }
  int g = __gcd(abs(x), abs(y));
  x /= g;
  y /= g;

  union {
    struct {
      int x, y;
    };
    ll z;
  } conv;
  conv.x = x;
  conv.y = y;
  return conv.z;
}

struct query {
  int t, x, y;
};

int main() {
#ifdef LOCAL
  freopen("f.in", "r", stdin);
  freopen("f.out", "w", stdout);
#endif

  int q;
  while (scanf("%d", &q) == 1) {
    vector<query> qs(q);
    unordered_map<ll, int> ans;
    ans.rehash(q);
    map<ll, set<pair<int, int>>> v;

    for (auto& x : qs) {
      scanf("%d%d%d", &x.t, &x.x, &x.y);
      if (x.t == 3) {
        ans[norm(x.x, x.y)] = 0;
      }
    }


    auto to_ans = [&](int x, int y, int v) {
      ll t = norm(x, y);
      auto it = ans.find(t);
      if (it != ans.end()) {
        it->second += v;
      }
    };

    auto process_point = [&](ll dist, int x, int y, int coef) {
      for (const auto& p : v[dist]) {
        int px = p.first + x;
        int py = p.second + y;
        to_ans(px, py, 2 * coef);
      }
      to_ans(x, y, 1 * coef);
    };


    int tot = 0;
    for (auto [ty, x, y] : qs) {
      if (ty == 1) {
        ++tot;
        ll dist = x * 1LL * x + y * 1LL * y;
        process_point(dist, x, y, +1);
        v[dist].insert({x, y});
      } else if (ty == 2) {
        --tot;
        ll dist = x * 1LL * x + y * 1LL * y;
        v[dist].erase({x, y});
        process_point(dist, x, y, -1);
      } else if (ty == 3) {
        printf("%d\n", tot - ans[norm(x, y)]);
      } else {
        assert(0);
      }
    }
  }

  return 0;
}