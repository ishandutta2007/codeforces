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

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    static char buf[200];
    int cnt, totx, toty;
    cnt = totx = toty = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      for (int j = 0; j < m; j++) {
        if (buf[j] == 'B') {
          cnt++;
          totx += i + 1;
          toty += j + 1;
        }
      }
    }
    printf("%d %d\n", totx / cnt, toty / cnt);
  }

  return 0;
}