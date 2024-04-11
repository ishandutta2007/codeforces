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
    vector<int> a(n);
    vector<int> t(n, -1);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    vector<pair<int, int>> st;
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int ty;
      scanf("%d",&ty);
      if (ty == 2) {
        int x;
        scanf("%d", &x);
        while (st.size() && st.back().second <= x) {
          st.pop_back();
        }
        st.emplace_back(i, x);
      } else {
        int p, x;
        scanf("%d%d",&p, &x);
        --p;
        a[p] = x;
        t[p] = i;
      }
    }

    for (int i = 0; i < n; i++) {
      auto it = lower_bound(st.begin(), st.end(), make_pair(t[i], -1));
      if (it != st.end()) {
        a[i] = max(a[i], it->second);;
      }
      printf("%d ", a[i]);
    }
    printf("\n");
  }

  return 0;
}