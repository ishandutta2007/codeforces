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
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  int n, d, m;
  while (scanf("%d%d%d", &n, &d, &m) == 3) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    auto it = upper_bound(a.begin(), a.end(), m);
    vector<int> small(a.begin(), it);
    vector<int> large(it, a.end());
    reverse(large.begin(), large.end());
    ll sum = 0;
    for (int i = 0; i < (int)small.size(); i++) {
      sum += small[i];
    }
    ll ans = sum;
    int pt = 0;
    for (int i = 0; i < (int)large.size(); i++) {
      sum += large[i];
      if ((i + 1) * 1LL * (d + 1) < (int)large.size()) {
        continue;
      }
      ll removed = max(0LL, 1 + i * 1LL * (d + 1) - (int)large.size());
      if (removed > (int)small.size()) continue;
      while (pt < removed) {
        sum -= small[pt++];
      }
      eprintf("i = %d, sum = %lld, removed = %lld\n", i, sum, removed);
      ans = max(ans, sum);
    }
    printf("%lld\n", ans);
  }

  return 0;
}