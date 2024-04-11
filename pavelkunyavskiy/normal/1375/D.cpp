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
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int t;
  scanf("%d", &t);
  while (t-->0) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }

    auto mex = [&](const vector<int>& a) {
      vector<bool> v(a.size() + 1);
      for (int x : a) {
        if (x < (int)v.size()) v[x] = true;
      }
      int res = 0;
      while (v[res]) res++;
      return res;
    };

    vector<int> ops;

    while (!is_sorted(a.begin(), a.end())) {
      int val = mex(a);
      int pos = -1;
      if (val < n) {
        pos = val;
      } else {
        for (int i = 0; i < n; i++) {
          if (a[i] != i) {
            pos = find(a.begin(), a.end(), i) - a.begin();
            break;
          }
        }
      }
      assert(pos != -1);
      ops.push_back(pos);
      a[pos] = val;
    }

    printf("%zd\n", ops.size());
    for (int x : ops) printf("%d ", x + 1);
    printf("\n");
  }


  return 0;
}