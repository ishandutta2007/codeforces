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

vector<vector<int>> ga;
vector<vector<int>> gb;
vector<int> comp;
vector<bool> used;

void dfsa(int v) {
  used[v] = true;
  comp.push_back(v);
  for (int u : ga[v]) {
    if (!used[u]) {
      dfsa(u);
    }
  }
}

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int n, m, a, b;
  while (scanf("%d%d%d%d", &n, &m, &a, &b) == 4) {
    ga = gb = vector<vector<int>>(n);

    for (int i = 0; i < m; i++) {
      int x, y, c;
      scanf("%d%d%d", &x, &y, &c);
      --x, --y;
      auto &g = (c == a) ? ga : gb;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    vector<pair<int, int>> order;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        order.emplace_back(i, j);
      }
    }
    sort(order.begin(), order.end(), [&](const pair<int, int>& x, const pair<int, int>& y) {
      return x.first * a + x.second * b < y.first * a + y.second * b;
    });

    vector<int> comp_id(n, -1);
    used = vector<bool>(n, false);
    int cc = 0;
    int cc2 = -2;

    for (int i = 0; i < n; i++) {
      if (comp_id[i] == -1) {
        comp.clear();
        dfsa(i);
        int cid = (comp.size() >= 4 ? cc++ : cc2--);
        for (int x : comp) {
          comp_id[x] = cid;
        }
      }
    }

    vector<vector<vector<pair<int, int>>>> vs(n, vector<vector<pair<int, int>>>(n));
    vector<vector<int>> dp((1 << cc), vector<int>(n, 1 << 30));
    int init_id = (comp_id[0] < 0) ? 0 : (1 << comp_id[0]);
    dp[init_id][0] = 0;
    vs[0][0].emplace_back(init_id, 0);

    vector<int> ans(n, 1 << 30);

    for (auto &[cnta, cntb] : order) {
      for (auto &[mask, v] : vs[cnta][cntb]) {
        if (dp[mask][v] != cnta * a + cntb * b) continue;
        ans[v] = min(ans[v], dp[mask][v]);

        for (int u : ga[v]) {
          if (dp[mask][u] > dp[mask][v] + a) {
            assert(comp_id[u] == comp_id[v]);
            dp[mask][u] = dp[mask][v] + a;
            vs[cnta + 1][cntb].emplace_back(mask, u);
          }
        }

        for (int u : gb[v]) {
          if (comp_id[u] == comp_id[v]) continue;
          int nmask = mask;
          if (comp_id[u] >= 0) {
            nmask |= (1 << comp_id[u]);
            if (mask == nmask) continue;
          }
          if (dp[nmask][u] > dp[mask][v] + b) {
            dp[nmask][u] = dp[mask][v] + b;
            vs[cnta][cntb + 1].emplace_back(nmask, u);
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }

  return 0;
}