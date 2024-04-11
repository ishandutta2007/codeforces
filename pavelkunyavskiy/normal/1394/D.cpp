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

vector<int> t, h;
vector<vector<int>> g;
vector<ll> dp[3];

ll calc(int v, int p, int out) {
  ll& ans = dp[out][v];
  if (ans != -1) {
    return ans;
  }
  if (p == -1 && out != 1) {
    return -1;
  }
  if (p != -1 && out == 1) {
    return -1;
  }
  if (p != -1 && out == 0 && h[v] < h[p]) {
    return -1;
  }
  if (p != -1 && out == 2 && h[v] > h[p]) {
    return -1;
  }

  ans = numeric_limits<ll>::max();

  ll cur = 0;

  vector<ll> changes;
  int cnt0 = (out == 0), cnt2 = (out == 2);
  for (int u : g[v]) {
    if (u == p) continue;
    ll ans0 = calc(u, v, 2);
    ll ans2 = calc(u, v, 0);
    if (ans0 == -1) {
      cur += ans2;
      cnt2++;
    } else {
      cur += ans0;
      cnt0++;
      if (ans2 != -1) {
        changes.push_back(ans2 - ans0);
      }
    }
  }
  sort(changes.begin(), changes.end());
  for (int i = 0; i <= (int)changes.size(); i++) {
    ans = min(ans, cur + max(cnt0, cnt2) * 1LL * t[v]);
    if (i != (int)changes.size()) {
      cnt0--;
      cnt2++;
      cur += changes[i];
    }
  }

  eprintf("dp(%d, %d) = %lld\n", v, out, ans);

  return ans;
}

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    t = vector<int>(n);
    h = vector<int>(n);
    g = vector<vector<int>>(n);
    dp[0] = dp[1] = dp[2] = vector<ll>(n, -1);

    for (int i = 0; i < n; i++) {
      scanf("%d", &t[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &h[i]);
    }
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    printf("%lld\n", calc(0, -1, 1));
  }

  return 0;
}