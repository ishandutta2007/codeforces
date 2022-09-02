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

char buf[1'000'000];

int main() {
#ifdef LOCAL
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      int l = strlen(buf);
      int cnt = count(buf, buf + l, 'N');
      v[i] = {cnt, l - cnt};
    }

    int l = -1;
    int r = 1e6;

    auto check = [&](int d) -> pair<int, int> {
      int mx = 0, Mx = numeric_limits<int>::max();
      int my = 0, My = numeric_limits<int>::max();
      int md = numeric_limits<int>::min(), Md = numeric_limits<int>::max();
      for (auto [a, b] : v) {
        mx = max(mx, a - d); Mx = min(Mx, a + d);
        my = max(my, b - d); My = min(My, b + d);
        md = max(md, (a - b) - d); Md = min(Md, (a - b) + d);
      }
      for (int i = mx; i <= Mx; i++) {
        int ly = max(my, i - Md);
        int ry = min(My, i - md);
        if (i == 0) ly = max(ly, 1);
        if (ly <= ry) {
          return {i, ly};
        }
      }
      return {-1, -1};
    };

    assert(check(r).first != -1);

    while (r - l > 1) {
      int m = (l + r) / 2;
      if (check(m).first != -1) {
        r = m;
      } else {
        l = m;
      }
    }
    auto [a, b] = check(r);
    assert(a + b > 0);
    printf("%d\n", r);
    for (int i = 0; i < a; i++) {
      printf("N");
    }
    for (int i = 0; i < b; i++) {
      printf("B");
    }
    printf("\n");
  }

  return 0;
}