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

vector<vector<int>> g;
vector<bool> used;
int es, vs, ps;

const int MOD = 1000000007;

int mul(int a, int b) {
  return (int) ((a * 1LL * b) % MOD);
}

void dfs(int v) {
  if (used[v]) return;
  used[v] = true;
  vs++;
  es += g[v].size();
  for (int u : g[v]) {
    if (u == v) ps++;
    dfs(u);
  }
}

int main() {
#ifdef LOCAL
  freopen("e.in", "r", stdin);
  freopen("e.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    g = vector<vector<int>>(2 * n);
    for (int i = 0; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    used = vector<bool>(2 * n);

    int ans = 1;

    for (int i = 0; i < 2 * n; i++) {
      if (used[i]) {
        continue;
      }
      es = vs = ps = 0;
      dfs(i);
      es /= 2;
      if (es == 0 || ps != 0) {
        continue;
      }
      if (es == vs - 1) {
        ans = mul(ans, vs);
      } else {
        assert(es == vs);
        ans = mul(ans, 2);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}