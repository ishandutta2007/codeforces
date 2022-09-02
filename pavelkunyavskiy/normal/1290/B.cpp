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

constexpr int MAXN = 210000;
char s[MAXN];

int main() {
#ifdef LOCAL
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  while (scanf("%s", s) > 0) {
    vector<vector<int>> cpos(26);
    for (int i = 0; s[i]; i++) {
      cpos[s[i] - 'a'].push_back(i);
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      --l;
      int cnt = 0;
      for (const auto &v : cpos) {
        if (lower_bound(v.begin(), v.end(), l) != lower_bound(v.begin(), v.end(), r)) {
          cnt++;
        }
      }
      if (cnt >= 3 || (s[l] != s[r - 1]) || (l == r - 1)) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
    }
  }


  return 0;
}