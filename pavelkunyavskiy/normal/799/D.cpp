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

const int MAXN = 100100;
int dp[MAXN];

int smul(int a, int b, int c) {
  return (int)min(a * 1LL * b, (ll)c);
}

int solve(int a, int b, int w, int h, vector<int> v) {
  if (a >= w && b >= h) return 0;
  memset(dp, -1, sizeof(dp));
  dp[min(a, w)] = min(b, h);
  for (int i = 0; i < (int)v.size(); i++) {
    int x = v[i];
    for (int j = w; j >= 1; j--) {
      if (dp[j] != -1) {
        int id = smul(j, x, w);
        dp[id] = max(dp[id], dp[j]);
        dp[j] = max(dp[j], smul(dp[j], x, h));
      }
    }
    if (dp[w] == h) return i + 1;
  }

  return (int) (v.size() + 1);
}

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int a, b, w, h, n;
  while (scanf("%d%d%d%d%d", &a, &b, &w, &h, &n) == 5) {
    vector<int> v(n);
    for (int& x : v) scanf("%d", &x);
    sort(v.rbegin(), v.rend());
    int ans1 = solve(w, h, a, b, v);
    int ans2 = solve(h, w, a, b, v);
    int ans = min(ans1, ans2);
    if (ans > n) ans = -1;
    printf("%d\n", ans);
  }

  return 0;
}