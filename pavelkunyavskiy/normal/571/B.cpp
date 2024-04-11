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

const int INF = 0x7fffffff;


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    vector<int> v(n);
    for (int& x : v)
      scanf("%d",&x);
    sort(v.begin(), v.end());

    int block_size = (n + k - 1) / k;
    int small = n % k;
    if (small) small = k - small;

    vector<int> dp(small + 1, -1);
    dp[0] = 0;
    if (small) dp[1] = 0;

    for (int i = 1; i < k; i++) {
      vector<int> ndp(small + 1, -1);
      for (int j = 0; j <= small; j++){
        if (dp[j] == -1) continue;
        int tot = block_size * i - j;
        if (tot < n)
          ndp[j] = max(ndp[j], dp[j] + v[tot] - v[tot - 1]);
        if (j != small && tot < n)
          ndp[j + 1] = max(ndp[j + 1], dp[j] + v[tot] - v[tot - 1]);
      }
      dp = ndp;
    }

    assert(dp[small] != -1);

    printf("%d\n", v.back() - v[0] - dp[small]);
  }
      
  return 0;
}