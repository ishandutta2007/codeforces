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

  int n, m;
  scanf("%d%d", &n, &m);
  if (m == n * (n - 1) / 2) {
    printf("0\n");
    return 0;
  }
  vector<int> g(n);
  for (int i = 0; i < n; i++) {
    g[i] |= 1 << i;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a] |= (1 << b);
    g[b] |= (1 << a);
  }

  vector<int> cost(1 << n);
  vector<int> pi(1 << n);
  vector<int> pj(1 << n);

  const int INF = 1 << 30;

  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) && (g[j] & i) != i) {
        cost[i] = INF;
      }
    }
  }

  for (int i = 1; i < (1 << n); i++) {
    if (cost[i] != INF) {
//      eprintf("%d\n", i);
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          int ni = i | g[j];
          if (cost[ni] > cost[i] + 1) {
            cost[ni] = cost[i] + 1;
            pi[ni] = i;
            pj[ni] = j;
          }
        }
      }
    }
  }

  int mask = (1 << n) - 1;
  printf("%d\n", cost[mask]);

  vector<int> ans;
  while (cost[mask]) {
    ans.push_back(pj[mask]);
    mask = pi[mask];
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < (int)ans.size(); i++) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");

  return 0;
}