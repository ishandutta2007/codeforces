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
};

pt operator-(const pt& a, const pt& b) {
  return {a.x - b.x, a.y - b.y};
}

ll operator*(const pt& a, const pt& b) {
  return a.x * 1LL * b.y - a.y * 1LL * b.x;
}

char buf[2100];

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<pair<pt, int>> v(n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &v[i].first.x, &v[i].first.y);
      v[i].second = i + 1;
    }
    scanf("%s", buf);

    vector<int> ans;

    auto to_ans = [&](decltype(v)::iterator pos) {
      ans.push_back(pos->second);
      auto res = pos->first;
      v.erase(pos);
      return res;
    };

    pt cur = to_ans(min_element(v.begin(), v.end(), [](const pair<pt, int>& a, const pair<pt, int>& b) {
      return tie(a.first.x, a.first.y) < tie(b.first.x, b.first.y);
    }));

    for (int i = 0; i < n - 2; i++) {
      auto cmp = [&cur](const pair<pt, int>& a, const pair<pt, int>& b) {
        return (a.first - cur) * (b.first - cur) > 0;
      };
      if (buf[i] == 'L') {
        cur = to_ans(min_element(v.begin(), v.end(), cmp));
      } else {
        cur = to_ans(max_element(v.begin(), v.end(), cmp));
      }
    }

    to_ans(v.begin());

    for (int x : ans) {
      printf("%d ", x);
    }
    printf("\n");
  }

  return 0;
}