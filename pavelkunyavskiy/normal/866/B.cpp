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
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif

  int n, s;
  scanf("%d%d", &n, &s);
  vector<pair<ll, ll>> v;
  ll tot = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    ans += a * 1LL * b;
    tot += a;
    v.push_back({c - b, a});
  }
  ll num = (tot + s - 1) / s;
  v.push_back({0, num * s - tot});

  sort(v.rbegin(), v.rend());
  ll sec = 0;
  ll res = ans;
  for (int i = 0; i < (int)v.size(); i++) {
    ll t = min(sec, v[i].second);
    v[i].second -= t;
    sec -= t;
    res += v[i].first * t;
    if (sec == 0) {
      ans = max(res, ans);
    }
    if (v[i].second != 0) {
      assert(sec == 0);
      t = (v[i].second / s) * s;
      v[i].second -= t;
      res += v[i].first * t;
      ans = max(res, ans);
      sec = s;
      i--;
    }
  }

  printf("%lld\n", ans);
  return 0;
}