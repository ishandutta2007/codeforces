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
  freopen("e.in", "r", stdin);
  freopen("e.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<ll> v(n);
    for (auto &x : v) {
      scanf("%lld", &x);
    }

    ll x = *max_element(v.begin(), v.end());
    int st = -1;
    for (int i = 0; i < n; i++) {
      if (v[i] == x && v[(i - 1 + n) % n] != x) {
        st = i;
      }
    }
    if (st == -1) {
      if (x == 0) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
          printf("1 ");
        }
        printf("\n");
      } else {
        printf("NO\n");
      }
      continue;
    }
    printf("YES\n");

    for (int i = 1; i <= n; i++) {
      int pos = (st - i + n) % n;
      int nxt = (pos + 1) % n;
      int nnxt = (pos + 2) % n;
      if (v[pos] >= v[nxt]) {
        ll diff = v[pos] - v[nxt] + 1;
        ll md = v[nnxt];
        ll add = (diff + md - 1) / md;
        v[nxt] += add * md;
      }
    }

    for (int i = 0; i < n; i++) {
      printf("%lld ", v[i]);
    }
    printf("\n");
  }

  return 0;
}