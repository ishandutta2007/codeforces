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

#define TASKNAME "G"

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


double dp[30][30];
double ndp[30][30];


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n, k;
  scanf("%d%d",&n,&k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i][j] = i < j;

  for (int it = 0; it < k; it++){
    memset(ndp, 0, sizeof(ndp));
    double coef = 2.0 / (n * (n+1));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int l = 0; l < n; l++)
          for (int r = l; r < n; r++){
            int ni = (l <= i && i <= r ? (r + l - i) : i);
            int nj = (l <= j && j <= r ? (r + l - j) : j);
            ndp[i][j] += dp[ni][nj] * coef;
          }
    memcpy(dp, ndp, sizeof(dp));
    /*for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        fprintf(stderr, "%.3f%c", dp[i][j], " \n"[j==n-1]);*/
  }

  vector<int> p(n);
  for (int i = 0; i < n; i++){
    scanf("%d",&p[i]);
  }
  double ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      if (p[i] > p[j])
        ans += dp[i][j];
      else 
        ans += dp[j][i];
  printf("%.10f\n", ans);     
  return 0;
}