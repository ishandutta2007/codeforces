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

  int c, w1, w2, h1, h2;
  scanf("%d%d%d%d%d",&c,&h1,&h2,&w1,&w2);
  if (w1 * 1LL * h2 <= h1 * 1LL * w2){
    swap(w1, w2);
    swap(h1, h2);
  }
  bool bigw2 = false;
  if (w2 >= 100000) {
    swap(w1, w2);
    swap(h1, h2);    
    bigw2 = true;
  }

  long long ans = 0;
  for (int i = 0; i * 1LL * w1 <= c; i++) {
    if (!bigw2 && i == w2) {
      break;
    }
    int j = (c - i * w1) / w2;
    ans = max(ans, i * 1LL * h1 + j * 1LL * h2);
  }
  printf(LLD"\n", ans);
      
  return 0;
}