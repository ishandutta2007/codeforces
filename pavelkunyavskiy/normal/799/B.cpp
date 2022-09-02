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
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<bool> used(n);
    vector<int> price(n);
    vector<int> a(n);
    vector<int> b(n);
    vector<int> order[3];
    int ptr[3];
    memset(ptr, 0, sizeof(ptr));

    for (int& x : price) {
      scanf("%d", &x);
    }
    for (int& x : a) {
      scanf("%d", &x);
    }
    for (int& x : b) {
      scanf("%d", &x);
    }

    for (int i = 0; i < n; i++) {
      order[a[i] - 1].push_back(i);
      order[b[i] - 1].push_back(i);
    }

    for (int i = 0; i < 3; i++) {
      sort(order[i].begin(), order[i].end(), [&price](int x, int y) -> bool { return price[x] < price[y];});
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int c;
      scanf("%d", &c);
      --c;
      while (ptr[c] < (int)order[c].size() && used[order[c][ptr[c]]]) ptr[c]++;
      int res = -1;
      if (ptr[c] < (int)order[c].size()) {
        res = price[order[c][ptr[c]]];
        used[order[c][ptr[c]]] = true;
      }
      printf("%d%c", res, " \n"[i == m - 1]);
    }
  }

  return 0;
}