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

  ll x;
  while (scanf("%lld", &x) == 1) {
    vector<tuple<ll, char, ll>> ops;
    set<ll> have;
    have.insert(0);
    have.insert(x);

    auto do_xor = [&](ll a, ll b) {
      if (!have.count(a ^ b)) {
        ops.emplace_back(a, '^', b);
        have.insert(a ^ b);
      }
      return a ^ b;
    };
    auto do_add = [&](ll a, ll b) {
      if (!have.count(a + b)) {
        ops.emplace_back(a, '+', b);
        have.insert(a + b);
      }
      return a + b;
    };

    vector<ll> vals;
    vals.push_back(x);
    while (find(vals.begin(), vals.end(), 1) == vals.end()) {
      int s = vals.size();
      for (int i = 0; i < s; i++) {
        for (int j = i; j < s; j++) {
          if (vals[i] + vals[j] < (1LL << 61)) {
            vals.push_back(do_add(vals[i], vals[j]));
          }
        }
      }
      for (int i = 0; i < (int)vals.size(); i++) {
        if (vals[i]) {
          ll bit = vals[i] & ~(vals[i] - 1);
          for (int j = 0; j < (int)vals.size(); j++) {
            if (j != i) {
              if (vals[j] & bit) {
                vals[j] = do_xor(vals[j], vals[i]);
              }
            }
          }
        }
      }
      vals.erase(std::remove_if(vals.begin(), vals.end(), [](int x) { return x == 0; }), vals.end());
      eprintf("%d\n", (int)vals.size());
      for (ll x : vals) {
        eprintf("%lld ", x);
      }
      eprintf("\n");
    }
    printf("%d\n", (int)ops.size());
    for (auto x : ops) {
      printf("%lld %c %lld\n", get<0>(x), get<1>(x), get<2>(x));
    }
  }

  return 0;
}