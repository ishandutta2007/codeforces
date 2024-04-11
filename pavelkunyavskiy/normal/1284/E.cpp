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

struct pt {
  int x, y;
  pt operator-(const pt& a) const {
    return {x - a.x, y - a.y};
  }

  int hpl() const {
    if (y > 0 || (y == 0 && x > 0)) {
      return 0;
    }
    return 1;
  }

  ll operator*(const pt& a) const {
    return x * 1LL * a.y - y * 1LL * a.x;
  }

  bool operator==(const pt &rhs) const {
    return std::tie(x, y) == std::tie(rhs.x, rhs.y);
  }

  bool operator!=(const pt &rhs) const {
    return !(rhs == *this);
  }
};

int main() {
#ifdef LOCAL
  freopen("e.in", "r", stdin);
  freopen("e.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<pt> pts(n);
    for (auto &p : pts) {
      scanf("%d%d", &p.x, &p.y);
    }
    ll ans = 0;
    for (auto p : pts) {
      vector<pt> other;
      other.reserve(2 *n - 2);
      for (auto x : pts) {
        if (x != p) {
          other.push_back(x - p);
        }
      }
      sort(other.begin(), other.end(), [](const pt&a, const pt&b) {
        if (a.hpl() != b.hpl()) {
          return a.hpl() < b.hpl();
        }
        return a * b > 0;
      });
      for (int i = 0; i < n - 1; i++) {
        other.push_back(other[i]);
      }

      auto c4 = [](ll n) {
        return n * (n - 1) * (n - 2) * (n - 3) / 24;
      };
      auto c3 = [](ll n) {
        return n * (n - 1) * (n - 2) / 6;
      };
      int pt = 0;
      ll cur = 0;
      cur += c4(n - 1);
      for (int i = 0; i < n - 1; i++) {
        pt = max(pt, i + 1);
        while (other[i] * other[pt] > 0) {
          pt++;
        }
//        eprintf("%d %d: [%d,%d .. %d,%d) -> -%lld\n", p.x, p.y, other[i].x + p.x, other[i].y + p.y, other[pt].x + p.x, other[pt].y + p.y, c3(pt - i-1));

        cur -= c3(pt - i - 1);
      }
      ans += cur;
//      eprintf("%d %d %lld\n", p.x, p.y, cur);
    }
    printf("%lld\n", ans);
  }

  return 0;
}