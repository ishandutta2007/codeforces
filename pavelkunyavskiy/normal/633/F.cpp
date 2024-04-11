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

#define TASKNAME "F"

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


const int MAXN = 100100;

int val[MAXN];

long long dp[MAXN][4];
vector<int> g[MAXN];

void dfs(int v, int p) {
  for (int u : g[v])
    if (u != p)
      dfs(u, v);

  ll max0 = 0, smax0 = 0, tmax0 = 0; int max0v = -1, smax0v = -1;
  ll max1 = 0, smax1 = 0; int max1v = -1;
  ll max2 = 0, smax2 = 0; int max2v = -1;
  ll max3 = 0, smax3 = 0; //int max3v = -1;

  for (int u : g[v])
    if (u != p) {
      ll t = dp[u][0];
      int tv = u;
      if (t > max0) { swap(t, max0); swap(max0v, tv); }
      if (t > smax0) { swap(t, smax0); swap(smax0v, tv); }
      if (t > tmax0) { swap(t, tmax0);  }

      t = dp[u][1];
      if (t > max1) { swap(t, max1); max1v = u; }
      if (t > smax1) swap(t, smax1);


      t = dp[u][2];
      if (t > max2) { swap(t, max2); max2v = u; }
      if (t > smax2) swap(t, smax2);

      t = dp[u][3];
      if (t > max3) { swap(t, max3); /*max3v = u;*/ }
      if (t > smax3) swap(t, smax3);
    }

  dp[v][0] = max0 + val[v];

  dp[v][1] = max(max1, max0 + smax0 + val[v]);

  dp[v][2] = max2 + val[v];
  if (max0v == max1v) {
    dp[v][2] = max(dp[v][2], max(max0 + smax1, max1 + smax0) + val[v]);
  } else {
    dp[v][2] = max(dp[v][2], max0 + max1 + val[v]);
  }

  dp[v][3] = max3;
  dp[v][3] = max(dp[v][3], max1 + smax1);

  if (max0v == max2v) {
    dp[v][3] = max(dp[v][3], max(max0 + smax2, max2 + smax0) + val[v]);
  } else {
    dp[v][3] = max(dp[v][3], max0 + max2 + val[v]);
  }

  for (int u : g[v])
    if (u != p) {
      ll cur = val[v] + dp[u][1];
      if (u == max0v) {
        cur += smax0 + tmax0;
      } else if (u == smax0v) {
        cur += max0 + tmax0;
      } else {
        cur += max0 + smax0;
      }
      dp[v][3] = max(dp[v][3], cur);
    }
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n;
  scanf("%d",&n);

  for (int i = 0; i < n; i++)
    scanf("%d",&val[i]);

  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0, -1);

  printf("%lld\n", *max_element(dp[0], dp[0] + 4));

      
  return 0;
}