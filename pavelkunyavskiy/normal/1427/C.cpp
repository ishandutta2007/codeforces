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
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif

  int r, n;
  while (scanf("%d%d", &r, &n) == 2) {
    vector<int> x(n + 1), y(n + 1), t(n + 1);
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &t[i], &x[i], &y[i]);
      --x[i], --y[i];
    }
    vector<int> dp(n + 1, numeric_limits<int>::min()), dpp(n + 1, numeric_limits<int>::min());
    dp[0] = dpp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j >= 0; j--) {
        if (t[j] + 2 * r <= t[i]) {
          dp[i] = max(dp[i], dpp[j] + 1);
          break;
        }
        if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      dpp[i] = max(dpp[i - 1], dp[i]);
    }
    printf("%d\n", dpp.back());
  }

  return 0;
}