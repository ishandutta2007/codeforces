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

struct point {
  int x, y, z;
  int id;
  bool operator<(const point& other) const {
    return std::tie(x, y, z) < std::tie(other.x, other.y, other.z);
  }
};

int main() {
#ifdef LOCAL
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<point> ps(n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &ps[i].x, &ps[i].y, &ps[i].z);
      ps[i].id = i + 1;
    }
    vector<pair<int, int>> ans;
    vector<point> psinit = ps;
    sort(ps.begin(), ps.end());
    vector<point> nps;
    for (int i = 0; i < (int)ps.size(); i++) {
      if (i + 1 < (int)ps.size() && ps[i].x == ps[i + 1].x && ps[i].y == ps[i + 1].y) {
        ans.emplace_back(ps[i].id, ps[i + 1].id);
        i++;
      } else {
        nps.push_back(ps[i]);
      }
    }
    ps = nps; nps.clear();
    sort(ps.begin(), ps.end());
    for (int i = 0; i < (int)ps.size(); i++) {
      if (i + 1 < (int)ps.size() && ps[i].x == ps[i + 1].x) {
        ans.emplace_back(ps[i].id, ps[i + 1].id);
        i++;
      } else {
        nps.push_back(ps[i]);
      }
    }
    ps = nps; nps.clear();
    sort(ps.begin(), ps.end());
    for (int i = 0; i < (int)ps.size(); i += 2) {
      ans.emplace_back(ps[i].id, ps[i + 1].id);
    }
    for (auto x : ans) {
      printf("%d %d\n", x.first, x.second);
    }

#ifdef LOCAL
    fflush(stdout);
    for (auto [id1, id2]: ans) {
      --id1, --id2;
      psinit[id1].id = -1;
      psinit[id2].id = -1;
      for (point p : psinit) {
        assert(
          p.id == -1 ||
          !(min(psinit[id1].x, psinit[id2].x) <= p.x && p.x <= max(psinit[id1].x, psinit[id2].x)) ||
          !(min(psinit[id1].y, psinit[id2].y) <= p.y && p.y <= max(psinit[id1].y, psinit[id2].y)) ||
          !(min(psinit[id1].z, psinit[id2].z) <= p.z && p.z <= max(psinit[id1].z, psinit[id2].z))
        );
      }
    }
#endif
  }

  return 0;
}