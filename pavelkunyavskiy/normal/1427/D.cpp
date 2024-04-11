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

  int n;
  while (scanf("%d", &n) == 1) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      --v[i];
    }
    vector<vector<int>> ops;

    while (true) {
      assert((int)ops.size() <= n);
      vector<int> nop;
      if (v[0] == 0) {
        for (int i = 0; i < n; i++) {
          if (v[i] == i) {
            nop.push_back(1);
          } else {
            int id = find(v.begin(), v.end(), i) - v.begin();
            nop.push_back(id - nop.size() + 1);
            nop.push_back(n - id - 1);
            break;
          }
        }
        nop.erase(std::remove(nop.begin(), nop.end(), 0), nop.end());
        if ((int)nop.size() == n) {
          break;
        }
      } else if (v[n - 1] == 0) {
        for (int i = 0; i < n; i++) {
          if (v[n - i - 1] == i) {
            nop.push_back(1);
          } else {
            int id = find(v.begin(), v.end(), i) - v.begin();
            nop.push_back(n - id - nop.size());
            nop.push_back(id);
            break;
          }
        }
        reverse(nop.begin(), nop.end());
        nop.erase(std::remove(nop.begin(), nop.end(), 0), nop.end());
      } else {
        int id = find(v.begin(), v.end(), 0) - v.begin();
        nop.push_back(id);
        nop.push_back(n - id);
      }
      ops.push_back(nop);
      vector<vector<int>> nvals;
      nvals.emplace_back();
      int pt = 0;
      for (int i = 0; i < n; i++) {
        if (nop[pt] == 0) {
          nvals.emplace_back();
          pt++;
        }
        nop[pt]--;
        nvals.back().push_back(v[i]);
      }
      reverse(nvals.begin(), nvals.end());
      v.clear();
      for (auto x : nvals) {
        v.insert(v.end(), x.begin(), x.end());
      }
    }


    assert((int)ops.size() <= n);
    printf("%d\n", (int)ops.size());
    for (auto x : ops) {
      printf("%d", (int)x.size());
      for (auto y : x) {
        printf(" %d", y);
      }
      printf("\n");
    }
  }

  return 0;
}