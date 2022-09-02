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

#define TASKNAME "A"

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

multiset<int> h, w;
set<int> hc, wc;

void cut(multiset<int>& lens, set<int>& cuts, int id){
  auto it = cuts.upper_bound(id);
  int r = *it;
  assert(it != cuts.begin());
  --it;
  int l = *it;
  lens.erase(lens.find(r - l));
  lens.insert(id - l);
  lens.insert(r - id);
  cuts.insert(id);
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int _w, _h, n;
  scanf("%d%d%d",&_w,&_h,&n);
  hc.insert(0), hc.insert(_h);
  wc.insert(0), wc.insert(_w);
  h.insert(_h);
  w.insert(_w);

  for (int i = 0; i < n; i++){
    char c; int id;
    scanf(" %c %d",&c, &id);
    if (c == 'H') {
      cut(h, hc, id);
    } else {
      cut(w, wc, id);
    }
    printf(LLD"\n", *(--h.end()) * 1LL * *(--w.end()));
  }

      
  return 0;
}