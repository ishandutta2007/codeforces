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

  scanf("%*d");
  int n, m;
  while (scanf("%d%d", &n,&m) == 2) {
    vector<bool> used(3 * n);
    vector<int> mt;
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      if (!used[a] && !used[b]) {
        used[a] = used[b] = true;
        mt.push_back(i);
      }
    }
    vector<int> ans;
    if ((int) mt.size() >= n) {
      ans = mt;
      printf("Matching\n");
    } else {
      for (int i = 0; i < 3 * n; i++) {
        if (!used[i]) {
          ans.push_back(i);
        }
      }
      printf("IndSet\n");
    }
    assert((int) ans.size() >= n);
    for (int i = 0; i < n; i++) {
      printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
    }
  }

  return 0;
}