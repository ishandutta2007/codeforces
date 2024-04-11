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
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    ll ans = 0;
    vector<int> mins;
    vector<int> maxs;
    for (int i = 0; i < n; i++) {
      int l;
      scanf("%d", &l);
      vector<int> v(l);
      for (int &x : v) scanf("%d", &x);
      if (!is_sorted(v.begin(), v.end(), greater<>())) {
        ans += 2 * n - 1;
        --n;
        --i;
        continue;
      }
      mins.push_back(v.back());
      maxs.push_back(v[0]);
    }
    sort(mins.begin(), mins.end());
    sort(maxs.begin(), maxs.end());
    for (int x : mins) {
      ans += maxs.end() - upper_bound(maxs.begin(), maxs.end(), x);
    }
    printf("%lld\n", ans);
  }

  return 0;
}