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

enum ev_type {OPEN, CLOSE};

struct event {
  int pos;
  ev_type ty;
  int id;

  bool operator<(const event &rhs) const {
    return std::tie(pos, ty, id) < std::tie(rhs.pos, rhs.ty, rhs.id);
  }
};


bool solve(int n) {
  vector<pair<int, int>> a(n), b(n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &a[i].first, &a[i].second, &b[i].first, &b[i].second);;
  }

  for (int it2 = 0; it2 < 2; it2++) {
    for (int it = 0; it < 2; it++) {
      vector<event> events;
      multiset<int> ls, rs;
      for (int i = 0; i < (int) a.size(); i++) {
        events.push_back({a[i].first, OPEN, i});
        events.push_back({a[i].second, CLOSE, i});
      }


      sort(events.rbegin(), events.rend());
      for (auto ev : events) {
        if (ev.ty == OPEN) {
          ls.insert(b[ev.id].first);
          rs.insert(b[ev.id].second);
        } else {
          int id = ev.id;
          if (ls.lower_bound(b[id].first) != ls.upper_bound(b[id].second)) {
            return false;
          }
          if (rs.lower_bound(b[id].first) != rs.upper_bound(b[id].second)) {
            return false;
          }
        }
      }

      for (auto &x : a) {
        swap(x.first, x.second);
        x.first *= -1;
        x.second *= -1;
      }
    }
    swap(a, b);
  }

  return true;
}

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    if (!solve(n)) {
      puts("NO");
    } else {
      puts("YES");
    }

  }

  return 0;
}