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

int MOD;

void add(int &a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}

void sub(int &a, int b) {
  if ((a -= b) < 0) a += MOD;
}

bool is_prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0)
      return false;
  }
  return true;
}

static inline ll rdtsc() {
  int __a, __d;
  ll val;
  asm volatile("rdtsc" : "=a" (__a), "=d" (__d));
  (val) = ((ll) __a) | (((ll) __d) << 32);
  return val;
}

int main() {
#ifdef LOCAL
  freopen("e.in", "r", stdin);
  freopen("e.out", "w", stdout);
#endif

  srand(rdtsc());

  MOD = 1e9 + (abs(rand() ^ rand() << 16)) % 100000000;
  while (!is_prime(MOD)) MOD++;
  eprintf("%d\n", MOD);

  int n, q;
  scanf("%d%d", &n, &q);

  vector<vector<int>> to_add(n);
  vector<vector<int>> to_rem(n);
  for (int i = 0; i < q; i++) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    to_add[l - 1].push_back(x);
    to_rem[r - 1].push_back(x);
  }

  vector<int> dp(n + 1);

  dp[0] = 1;
  vector<int> ok(n + 1);

  for (int i = 0; i < n; i++) {
    for (int x : to_add[i]) {
      for (int j = n; j >= x; j--) {
        add(dp[j], dp[j - x]);
      }
    }

    for (int j = 0; j <= n; j++) {
      ok[j] = ok[j] || (dp[j] != 0);
    }

    for (int x : to_rem[i]) {
      for (int j = x; j < n; j++) {
        sub(dp[j], dp[j - x]);
      }
    }
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (ok[i]) {
      cnt++;
    }
  }

  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++) {
    if (ok[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}