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
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<int> d(n);
    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      d[a - 1]++;
      d[b - 1]++;
    }

    int id = -1;
    for (int i = 0; i < n; i++) {
      if (d[i] > 2) {
        if (id == -1) {
          id = i;
        } else {
          id = -2;
        }
      }
    }
    if (id == -2) {
      printf("No\n");
    } else if (id == -1) {
      printf("Yes\n1\n");
      for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
          printf("%d ", i + 1);
        }
      }
      printf("\n");
    } else {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
          cnt++;
        }
      }
      printf("Yes\n%d\n", cnt);
      for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
          printf("%d %d\n", id + 1, i + 1);
        }
      }
    }
  }

  return 0;
}