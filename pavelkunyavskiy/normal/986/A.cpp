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
#include <numeric>

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

  int n, m, k, s;
  while (scanf("%d%d%d%d", &n, &m, &k, &s) == 4) {
    vector<vector<int>> g(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &c[i]);
      --c[i];
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    vector<vector<int>> cst(n, vector<int>(k, 0));
    for (int col = 0; col < k; col++) {
      queue<int> q;
      vector<int> d(n, -1);
      for (int i = 0; i < n; i++) {
        if (c[i] == col) {
          q.push(i);
          d[i] = 0;
        }
      }
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
          if (d[u] == -1) {
            d[u] = d[v] + 1;
            q.push(u);
          }
        }
      }
      for (int i = 0; i < n; i++) {
        cst[i][col] = d[i];
      }
    }

    for (int i = 0; i < n; i++) {
      nth_element(cst[i].begin(), cst[i].begin() + s, cst[i].end());
      printf("%lld ", accumulate(cst[i].begin(), cst[i].begin() + s, 0LL));
    }
    printf("\n");
  }


  return 0;
}