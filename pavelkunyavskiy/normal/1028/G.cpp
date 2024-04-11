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

const int MAXN = 10000;

const ll LIMIT = 1e18;

ll smul(ll a, ll b) {
  if (a == 0 || b == 0) return 0;
  if (a >= LIMIT / b) return LIMIT;
  return a * b;
}

ll sadd(ll a, ll b) {
  if (a >= LIMIT - b) {
    return LIMIT;
  }
  return a + b;
}

const ll M = 10004205361450474;

ll dp[MAXN + 1][6];

ll maxval(ll x, int y) {
  if (y == 0) return 0;
  if (x > MAXN) return maxval(MAXN, y);
  ll &ans = dp[x][y];
  if (ans != -1) return ans;
  ans = 0;


  for (int i = 0; i <= x; i++) {
    ans = sadd(ans, maxval(x + ans, y - 1) + 1);
    if (x + ans >= MAXN) {
      ans = sadd(ans, smul(maxval(MAXN, y - 1) + 1, x - i));
      break;
    }
  }
  ans -= 1;

  return ans;
}

void solve(ll x, int y) {
  assert(y != 0);

  int q = (int)min(x, (ll)MAXN);

  vector<ll> seq(q + 1);
  seq[0] = x;
  seq[1] = min(M, sadd(x, maxval(x, y - 1)));


  for (int i = 2; i < (int)seq.size(); i++) {
    seq[i] = sadd(seq[i - 1], maxval(seq[i - 1] + 1, y - 1) + 1);
    seq[i] = min(seq[i], M);
    if (seq[i] == M) {
      seq.resize(i + 1);
      break;
    }
  }
  eprintf("size = %d\n", (int)seq.size());
  printf("%d", (int)seq.size() - 1);
  for (int i = 1; i < (int)seq.size(); i++) {
    printf(" %lld", seq[i]);
  }
  printf("\n");
  fflush(stdout);

  int res;
  scanf("%d", &res);
  eprintf("res = %d\n", res);
  if (res < 0) {
    return;
  }
  assert(res < (int)seq.size());
  solve(seq[res] + (res > 0), y - 1);
}

int main() {
  memset(dp, -1, sizeof(dp));

  eprintf("%lld\n", maxval(2, 1));
  eprintf("%lld\n", maxval(1, 2));
  eprintf("%lld\n", maxval(3, 1));
  eprintf("%lld\n", maxval(1, 5) - M);

  solve(1, 5);

  return 0;
}