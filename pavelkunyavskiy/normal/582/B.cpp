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

const int MAXN = 110;

int dp1[110][110];
int dp2[110][110];
int a[110];
int n;

int calc1(int pos, int k) {
  if (k == 0) return 0;
  if (dp1[pos][k] != -1)
    return dp1[pos][k];
  int &res = dp1[pos][k];
  res = 1;
  for (int i = 0; i < n; i++)
    if (a[i] <= a[pos]) {
      if (i < pos) {
        res = max (res, calc1 (i, k) + 1);
      } else {
        res = max (res, calc1 (i, k - 1) + 1);
      }
    }
  return res;
}

int calc2(int pos, int k) {
  if (k == 0) return 0;
  if (dp2[pos][k] != -1)
    return dp2[pos][k];
  int &res = dp2[pos][k];
  res = 1;
  for (int i = 0; i < n; i++)
    if (a[i] >= a[pos]) {
      if (i > pos) {
        res = max (res, calc2 (i, k) + 1);
      } else {
        res = max (res, calc2 (i, k - 1) + 1);
      }
    }
  return res;
}


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int T;
  scanf("%d%d", &n, &T);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));

  if (T <= n + 5) {
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, calc1(i, T));
    printf("%d\n", ans);
    return 0;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    int first = i, last = i;
    for (int j = 0; j < n; j++)
      if (a[j] == a[i]) {
        cnt++;
        first = min(first, j);
        last = max(last, j);
      }
    for (int lf = 1; lf <= n; lf++)
      for (int rg = 1; rg <= n && lf + rg < T; rg++) {
        ans = max(ans, calc1(last, lf) + cnt * (T - lf - rg) + calc2(first, rg));
      }
  }
  printf("%d\n", ans);
      
  return 0;
}