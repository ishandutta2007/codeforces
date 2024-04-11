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

  int n, lim;
  while (scanf("%d%d", &n, &lim) == 2) {
    vector<int> v(n);
    for (int &x : v) {
      scanf("%d", &x);
    }
    sort(v.begin(), v.end());

    int ans = n;
    int K = 1 << min(30, 8 * lim / n);
    int last = 0;
    map<int, int> m;
    for (int i = 0; i < (int) v.size(); i++) {
      while (last < (int) v.size()) {
        if (m.find(v[last]) == m.end() && (int)m.size() == K) {
          break;
        }
        m[v[last++]]++;
      }
      ans = min(ans, n - (last - i));
      if (--m[v[i]] == 0) {
        m.erase(v[i]);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}