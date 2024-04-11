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

struct rect {
  int x1, y1;
  int x2, y2;

  bool empty() const {
    return x1 > x2 || y1 > y2;
  }
};

rect intersect(const rect& a, const rect& b) {
  return {
    max(a.x1, b.x1),
    max(a.y1, b.y1),
    min(a.x2, b.x2),
    min(a.y2, b.y2)
  };
}

const int INF = 1 << 30;

int main() {
#ifdef LOCAL
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<rect> v(n);
    for (rect &x : v) {
      scanf("%d%d%d%d", &x.x1, &x.y1, &x.x2, &x.y2);
    }

    vector<rect> pref(n + 1);
    pref[0] = {-INF, -INF, INF, INF};
    for (int i = 0; i < n; i++) {
      pref[i + 1] = intersect(pref[i], v[i]);
    }

    vector<rect> suff(n + 1);
    suff[n] = {-INF, -INF, INF, INF};
    for (int i = n - 1; i >= 0; i--) {
      suff[i] = intersect(suff[i + 1], v[i]);
    }

    for (int i = 0; i <= n; i++) {
      assert(i < n);
      rect cur = intersect(pref[i], suff[i + 1]);
      if (!cur.empty()) {
        printf("%d %d\n", cur.x1, cur.y1);
        break;
      }
    }
  }

  return 0;
}