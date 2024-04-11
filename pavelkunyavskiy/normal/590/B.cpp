//#include <iostream>
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
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"

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


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int x1, y1, x2, y2;
  int vmax, t;
  int vx, vy, wx, wy;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  scanf("%d %d", &vmax, &t);
  scanf("%d %d %d %d", &vx, &vy, &wx, &wy);

  double l = 0;
  double r = 1e9;

  for (int it = 0; it < 200; it++) {
    double m = (l + r) / 2;
    double dx = (x2 - x1) - vx * min (m, (double)t) - wx * max (0.0, m - t);
    double dy = (y2 - y1) - vy * min (m, (double)t) - wy * max (0.0, m - t);
    double needt = sqrt (dx * dx + dy * dy) / vmax;
    if (needt > m) {
      l = m;
    } else {
      r = m;
    }
  }

  printf("%.18f\n", (l + r) / 2);
      
  return 0;
}