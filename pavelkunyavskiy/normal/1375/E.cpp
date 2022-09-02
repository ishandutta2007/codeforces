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

int main() {
#ifdef LOCAL
  freopen("e.in", "r", stdin);
  freopen("e.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    vector<pair<int,int>> ops;
    auto op = [&](int x, int y) {
      swap(a[x], a[y]);
      ops.emplace_back(min(x, y), max(x, y));
    };

#ifdef LOCAL
    vector<pair<int, int>> ex_ops;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] > a[j]) {
          ex_ops.emplace_back(i, j);
        }
      }
    }
#endif

    for (int i = n - 1; i >= 0; i--) {
      vector<pair<int, int>> v;
      for (int j = 0; j < i; j++) {
        if (a[j] > a[i]) {
          v.emplace_back(a[j], j);
        }
      }
      if (v.empty()) continue;
      sort(v.begin(), v.end());
      for (auto [_, pos] : v) {
        op(pos, i);
      }
      int st = v[0].second;
      for (int j = st + 1; j < i; j++) {
        if (a[j] == a[st]) {
          op(j, st);
        }
      }
      for (int j = 0; j < (int) v.size();) {
        int k = j;
        while (k < (int) v.size() && a[v[k].second] == a[v[j].second]) k++;
        for (int t = j; t < k; t++) {
          if (v[t].second > v[k - 1].second) {
            op(v[t].second, v[k - 1].second);
          }
        }
        j = k;
      }
    }

    assert(is_sorted(a.begin(), a.end()));

    printf("%zd\n", ops.size());
    for (auto [x, y] : ops) {
      printf("%d %d\n", x + 1, y + 1);
    }

#ifdef LOCAL
    sort(ops.begin(), ops.end());
    sort(ex_ops.begin(), ex_ops.end());
    fflush(stdout);
    assert(ops == ex_ops);
    eprintf("done\n");
#endif
  }

  return 0;
}