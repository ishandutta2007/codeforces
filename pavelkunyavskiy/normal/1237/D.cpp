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
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<pair<int, int>> v(3 * n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &v[i].first);
      v[i + n].first = v[i + 2 * n].first = v[i].first;
      v[i].second = i;
      v[i + n].second = i + n;
      v[i + 2 * n].second = i + 2 * n;
    }
    sort(v.begin(), v.end());
    int ptr = 0;
    set<int> poss;
    poss.insert(1e9);
    vector<int> ans(3 * n);
    for (int i = 0; i < 3 * n; i++) {
      while (ptr < 3 * n && v[ptr].first * 2 < v[i].first) {
        poss.insert(v[ptr].second);
        ptr++;
      }
      ans[v[i].second] = *poss.lower_bound(v[i].second);
    }

    for (int i = 3 * n - 2; i >= 0; i--) {
      ans[i] = min(ans[i], ans[i + 1]);
    }

    for (int i = 0; i < n; i++) {
      int r = ans[i] - i;
      if (r > 3 * n) {
        r = -1;
      }
      printf("%d%c", r, " \n"[i == n - 1]);
    }
  }

  return 0;
}