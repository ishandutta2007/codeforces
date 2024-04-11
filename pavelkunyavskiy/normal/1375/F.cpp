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
#include <random>
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

//#define TEST

int main() {
//#ifdef LOCAL
//  freopen("f.in", "r", stdin);
//  freopen("f.out", "w", stdout);
//#endif

  std::random_device rd;
  int seed = rd();
  eprintf("seed = %d\n", seed);
  std::mt19937 rnd(seed);

  ll a[3];
  int last = -1;
  scanf("%lld%lld%lld", &a[0], &a[1], &a[2]);

  printf("First\n");
  fflush(stdout);
  auto run = [&](ll x) {
    printf("%lld\n", x);
    fflush(stdout);
    int pos;
#ifdef TEST
    do {
      pos = rnd() % 3;
    } while (pos == last);
    pos++;
#else
    scanf("%d", &pos);
#endif
    if (pos == 0) {
      exit(0);
    }
    a[pos - 1] += x;
    last = pos - 1;
    eprintf("now %lld %lld %lld : %d\n", a[0], a[1], a[2], last);
    if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) {
      exit(0);
    }
  };

  run(1);
  int mx = -1;
  int mn = -1;
  int md = -1;
  auto norm = [&]() {
    mx = max_element(a, a + 3) - a;
    mn = min_element(a, a + 3) - a;
    md = 3 - mn - mx;
    a[mx] -= a[mn];
    a[md] -= a[mn];
    a[mn] = 0;
  };
  norm();
  if (mx != last) {
    int other = 3 - mx - last;
    run(a[mx] - a[other]);
    assert(mx == last);
  }
  run(2 * a[mx] - a[md]);
  norm();
  run(a[md]);
  assert(false);


  return 0;
}