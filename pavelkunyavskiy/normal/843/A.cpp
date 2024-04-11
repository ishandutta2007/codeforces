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
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

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

  int n;
  while (scanf("%d", &n) == 1) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &v[i].first);
      v[i].second = i;
    }
    sort(v.begin(), v.end());
    vector<bool> used(n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      if (used[i]) continue;
      ans.push_back(vector<int>());
      for (int j = i; !used[j]; j = v[j].second) {
        ans.back().push_back(j);
        used[j] = true;
      }
      sort(ans.back().begin(), ans.back().end());
    }

    printf("%d\n", (int)ans.size());
    for (const auto& x : ans) {
      printf("%d", (int)x.size());
      for (int y : x) {
        printf(" %d", y + 1);
      }
      printf("\n");
    }
  }

  return 0;
}