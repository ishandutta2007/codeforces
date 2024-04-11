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


double dp[100*100];
double ndp[100*100];

vector<pair<int, int>> moves[100*100];

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n, k;
  scanf("%d%d",&n,&k);
  k = min(k, 1200);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i*n+j] = i < j;

  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++){
      vector<int> moves;
      for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++){
          int ni = (l <= i && i <= r ? (r + l - i) : i);
          int nj = (l <= j && j <= r ? (r + l - j) : j);
          moves.pb(ni * n + nj);
      }
      sort(moves.begin(), moves.end());
      vector<pair<int, int>> movesc;
      for (int l = 0; l < (int)moves.size(); ){
        int r = l;
        while (r < (int)moves.size() && moves[l] == moves[r]) r++;
        movesc.pb(mp(moves[l], r-l));
        l = r;
      }
      ::moves[n * i + j] = movesc;
    }

  for (int it = 0; it < k; it++){
    memset(ndp, 0, sizeof(ndp));
    double coef = 2.0 / (n * (n+1));
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++) {
        for (auto to : moves[n*i+j])
          ndp[i*n + j] += dp[to.first] * to.second;
        ndp[i*n+j] *= coef;
        ndp[j*n+i] = 1.0 - ndp[i*n+j];
      }
    memcpy(dp, ndp, sizeof(dp));
  }
  double maxv = 0;
  /*for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++) {
        fprintf(stderr, "%e%c", dp[i*n+j] - 0.5, " \n"[j==n-1]);
        maxv = max(maxv, fabs(dp[i*n+j] - 0.5));
      }
  fprintf(stderr, "maxv=%e\n", maxv);
  return 0;*/

  vector<int> p(n);
  for (int i = 0; i < n; i++){
    scanf("%d",&p[i]);
  }
  double ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      if (p[i] > p[j])
        ans += dp[i*n+j];
      else 
        ans += dp[j*n+i];
  printf("%.10f\n", ans);     
  return 0;
}