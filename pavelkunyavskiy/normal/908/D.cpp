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

int minv(int a) {
  return mpow(a, MOD - 2);
}

const int MAXK = 1010;

int dp[MAXK][MAXK];

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int k, pa, pb;
  scanf("%d%d%d", &k, &pa, &pb);

  int p = mul(pa, minv(pa + pb));
  int q = 1;sub(q, p);
  int extra = mul(p, minv(q));

  if (k == 1) {
    add(extra, 1);
    printf("%d\n", extra);
    return 0;
  }

  dp[0][1] = 1;

  int ans = 0;

  for (int ab = 0; ab < k; ab++) {
    for (int a = 1; ab + a < k; a++) {
      eprintf("d[%d][%d] = %d\n", ab, a, dp[ab][a]);
      if (ab + 2 * a < k) {
        add(dp[ab + a][a], mul(dp[ab][a], q));
      } else {
        int nab = ab + a;
        int na = a;
        int prob = mul(dp[ab][a], q);
        int x = nab;
        if (nab < k) {
          add(x, na);
          add(x, extra);
        }
        add(ans, mul(prob, x));
        eprintf("(%d, %d) -> (%d, %d) scored %d with prob %d\n", ab, a, nab, a, x, prob);
      }

      if (ab + a + 1 < k) {
        add(dp[ab][a + 1], mul(dp[ab][a], p));
      } else {
        int nab = ab;
        int na = a + 1;
        int prob = mul(dp[ab][a], p);
        int x = nab;
        add(x, na);
        add(x, extra);
        add(ans, mul(prob, x));
        eprintf("(%d, %d) -> (%d, %d) scored %d with prob %d\n", ab, a, nab, na, x, prob);
      }
    }
  }

  printf("%d\n", ans);


  return 0;
}