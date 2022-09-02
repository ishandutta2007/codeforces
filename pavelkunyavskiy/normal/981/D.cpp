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
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    vector<ll> a(n);
    for (auto &x : a) scanf("%lld", &x);
    vector<vector<ll>> c(n, vector<ll>(n + 1));

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        c[i][j] = c[i][j - 1] + a[j - 1];
      }
    }

    auto check = [&c, &n, &k] (ll bits, ll mask) -> bool {
      vector<vector<bool>> dp(k + 1, vector<bool>(n + 1));
      dp[0][0] = true;
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
          if (!dp[i][j]) continue;
          for (int t = j + 1; t <= n; t++) {
            if ((c[j][t] & mask & bits) == (mask & bits)) {
              dp[i + 1][t] = true;
            }
          }
        }
      }
      return dp[k][n];
    };
    
    ll ans = 0;
    ll fixed = 0;
    for (int i = 60; i >= 0; i--) {
      ll bit = 1LL << i;
      fixed |= bit;
      if (check(ans | bit, fixed)) {
        ans |= bit;
      }
    }

    printf("%lld\n", ans);
  }


  return 0;
}