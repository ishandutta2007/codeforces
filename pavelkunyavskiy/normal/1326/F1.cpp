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
  freopen("f1.in", "r", stdin);
  freopen("f1.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char c;
        scanf(" %c", &c);
        g[i][j] = c == '1';
      }
    }

    vector<vector<int>> to(n + 1);
    vector<int> from ( 1<< n);
    for (int i = 0; i < (1 << n); i++) {
      int cnt = __builtin_popcount(i);
      from[i] = to[cnt].size();
      to[cnt].push_back(i);
    }

    auto make_v = [](int a, int b, int c) {
      return vector<vector<vector<ll>>>(a,
                                        vector<vector<ll>>(b, vector<ll>(c)));
    };

    auto dp = make_v(n, 1, to[1].size());
    for (int i = 0; i < n; i++) {
      dp[i][0][from[1 << i]] = 1;
    }

    for (int bits = 1; bits < n; bits++) {
      auto ndp = make_v(n, 1 << bits, to[bits + 1].size());
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << (bits - 1)); j++) {
          for (int lid = 0; lid < (int)to[bits].size(); lid++) {
            int mask = to[bits][lid];
            if (!(mask & (1 << i))) {
              continue;
            }
            for (int k = 0; k < n; k++) {
              if (!(mask & (1 << k))) {
                int next_j = (j << 1) | g[i][k];
                ndp[k][next_j][from[mask | (1 << k)]] += dp[i][j][lid];
              }
            }
          }
        }
      }
      dp = std::move(ndp);
    }

    vector<ll> ans(1 << (n - 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1 << (n - 1)); j++) {
        assert(dp[i][j].size() == 1);
        ans[j] += dp[i][j][0];
      }
    }

    for (ll an : ans) {
      printf("%lld ", an);
    }
    printf("\n");
  }


  return 0;
}