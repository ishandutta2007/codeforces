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

#define TASKNAME "C"

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


double prob[100 * 1000 + 10];
double sums[100 * 1000 + 10];

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n, m;
  scanf("%d%d",&n,&m);
  if (m == 1) {
    printf("1\n");
    return 0;
  }
  prob[0] = 1;
  int tot = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= (i + 1) * m; j++) {
      sums[j + 1] = sums[j] + prob[j];
    }
    int a;
    scanf ("%d", &a);
    tot += a;
    for (int j = (i + 1) * m; j >= 0; j--) {
      prob[j] = (sums[j] - sums[max (0, j - m)] - (j >= a ? prob[j - a] : 0)) / (m - 1);
    }
  }
  double ans = 1;
  for (int i = 0; i < tot; i++) {
    ans += prob[i] * (m - 1);
  }
  printf("%.18f\n", ans);
  return 0;
}