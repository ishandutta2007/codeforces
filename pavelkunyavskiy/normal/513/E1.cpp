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

#define TASKNAME "E"

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

#define next next_ololo

typedef long long ll;
typedef long double ld;

const int next[4][4] = {
  {0, 1, 0, 1},
  {0, 1, 0, 1},
  {1, 0, 1, 0},
  {1, 0, 1, 0}
};

int dp[210][4][2];
int ndp[210][4][2];
int n, k;

int getCoef(int ty, int id){
  if (ty == 1 || ty == 2) return 0;
  if (ty == 0) return ((id == 1 || id == k) ? -1 : -2);
  return ((id == 1 || id == k) ? 1 : 2);
}

void play(int x){
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < 4; j++)
      for (int t = 0; t < 2; t++)
        ndp[i][j][t] = -1e9;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < 4; j++){
      ndp[i][j][1] = max(ndp[i][j][1], dp[i][j][1] + x * getCoef(j, i));
      ndp[i][j][0] = max(ndp[i][j][0], dp[i][j][0]);
      ndp[i][j][0] = max(ndp[i][j][0], dp[i][j][1]);
      if (i != k) {
        for (int t = 0; t < 4; t++) if (next[j][t]) {
          if (i + 1 == 1 || i + 1 == k) {
            if (t == 1 || t == 2) continue;
          }
          ndp[i+1][t][1] = max(ndp[i + 1][t][1], dp[i][j][0] + x * getCoef(t, i+1));
          ndp[i+1][t][1] = max(ndp[i + 1][t][1], dp[i][j][1] + x * getCoef(t, i+1));
        }
      }
    }
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < 4; j++)
      for (int t = 0; t < 2; t++)
        dp[i][j][t] = ndp[i][j][t]; 

  /*for (int i = 0; i <= k; i++){
    for (int j = 0; j < 4; j++)
      eprintf("(%d, %d)", dp[i][j][0], dp[i][j][1]);
    eprintf("\n");
  }   
  eprintf("=========\n");*/
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  scanf("%d%d",&n,&k);
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < 4; j++)
      for (int t = 0; t < 2; t++)
        dp[i][j][t] = -1e9;
  dp[0][1][0] = 0;
  dp[0][2][0] = 0;
  for (int it = 0; it < n; it++){
    int x;
    scanf("%d",&x);
    play(x);
  }

  printf("%d\n", max(max(dp[k][3][0], dp[k][3][1]),
                     max(dp[k][0][0], dp[k][0][1])));      
  return 0;
}