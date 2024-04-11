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

int n;
char s[55][55];
int dp[55][55][55][55];

int solve(int x1, int y1, int x2, int y2) {
  int &ans = dp[x1][y1][x2][y2];
  if (ans != -1) {
    return ans;
  }
  if (x2 == x1 + 1 && y2 == y1 + 1 && s[x1][y1] == '.') {
    return 0;
  }
  ans = max(x2 - x1, y2 - y1);
  for (int i = x1 + 1; i < x2; i++) {
    ans = min(ans, solve(x1, y1, i, y2) + solve(i, y1, x2, y2));
  }
  for (int i = y1 + 1; i < y2; i++) {
    ans = min(ans, solve(x1, y1, x2, i) + solve(x1, i, x2, y2));
  }
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  while (scanf("%d",&n) == 1) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    printf("%d\n", solve(0, 0, n, n));
  }

  return 0;
}