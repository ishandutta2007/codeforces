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

const int MOD = 1000000007;

void add(int &a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}

void sub(int &a, int b) {
  if ((a -= b) < 0) a += MOD;
}

int mul(int a, int b) {
  return (int) ((a * 1LL * b) % MOD);
}

int mpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int minv(int x) {
  return mpow(x, MOD - 2);
}

const int MAXD = 64;
int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  ll n;
  int k;
  while (scanf("%lld%d", &n, &k) == 2) {
    vector<vector<int>> dp(MAXD, vector<int>(MAXD));
    vector<int> minvs(MAXD + 1);
    for (int i = 1; i <= MAXD; i++) {
      minvs[i] = minv(i);
    }
    for (int i = 0; i < MAXD; i++) {
      vector<int>& d = dp[i];
      d[i] = 1;
      for (int j = 0; j < k; j++) {
        for (int p = 0; p < MAXD; p++) {
          d[p] = mul(d[p], minvs[p + 1]);
          for (int t = 0; t < p; t++) {
            add(d[t], d[p]);
          }
        }
      }
    }

    auto expected = [&dp](int p, int d) {
      int ans = 0;
      int cur = 1;
      for (int i = 0; i <= d; i++) {
        add(ans, mul(cur, dp[d][i]));
        cur = mul(cur, p);
      }
      return ans;
    };

    int ans = 1;

    for (ll i = 2; i * i <= n; i++) {
      int d = 0;
      while (n % i == 0) {
        n /= i;
        d++;
      }
      if (d > 0) {
        ans = mul(ans, expected(i % MOD, d));
      }
    }

    if (n != 1) {
      ans = mul(ans, expected(n % MOD, 1));
    }

    printf("%d\n", ans);
  }

  return 0;
}