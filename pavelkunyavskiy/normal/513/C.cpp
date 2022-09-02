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


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n;
  scanf("%d",&n);
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++)
      scanf("%d%d",&l[i],&r[i]);
  double ans = 0;
  for (int i = 1; i <= 10000; i++){
    double prob[3];
    prob[0] = 1;
    prob[1] = prob[2] = 0;
    for (int j = 0; j < n; j++){
      double p = max(r[j] - max(l[j], i) + 1, 0) * 1.0 / (r[j] - l[j] + 1);
      #ifdef LOCAL
      assert(0 <= p && p <= 1);
      #endif
      prob[2] += prob[1] * p;
      prob[1] = prob[1] * (1.0 - p) + prob[0] * p;
      prob[0] *= 1.0 - p;
    }
    ans += prob[2];
  }
  printf("%.10f\n", ans);      
  return 0;
}