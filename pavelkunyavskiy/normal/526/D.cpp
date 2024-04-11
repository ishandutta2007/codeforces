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

#define TASKNAME "D"

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

const int MAXN = 1000100;

char s[MAXN];
int z[MAXN];
char ans[MAXN];
int anssum[MAXN];

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n,k;
  scanf("%d%d%s",&n,&k,s);

  {
    int l, r;
    l = r = 0;
    for (int i = 1; i < n; i++) {
      if (i <= r) {
        z[i] = min(r - i + 1, z[i - l]);
      }
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
        z[i]++;
      }
      if (i + z[i] - 1 > r){
        l = i;
        r = i + z[i] - 1;
      }
    }
  }

  for (int i = 1; i <= n; i++){
    int lf = i * k;
    int rg = min(i * (k + 1), i + z[i]);
    if (lf > n) break;
    if (lf > rg) continue;
    anssum[lf]++;
    anssum[rg+1]--;
  }

  int sum = 0;
  for (int i = 0; i < n; i++){
    sum += anssum[i+1];
    ans[i] = sum > 0 ? '1' : '0';
  }  
  puts(ans);
  return 0;
  
}