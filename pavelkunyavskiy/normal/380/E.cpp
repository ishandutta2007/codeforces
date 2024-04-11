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

typedef long long ll;
typedef long double ld;

const int MAXN = 310000;

set<int> s;

pair<int,int> v[MAXN];
int n;

ld pow2[200];

ld solveone(int id){
    vector<int> lf, rg;
    s.insert(id);
    lf.pb(0);
    rg.pb(0);

    {
        set<int>::iterator iter = s.find(id);
        ++iter;
        for (; (int)rg.size() <= 60 && iter != s.end(); iter++)
            rg.pb(*iter - id);
    }
    {
        set<int>::reverse_iterator iter = set<int>::reverse_iterator(s.find(id));
        for (; (int)lf.size() <= 60 && iter != s.rend(); iter++)
            lf.pb(id - *iter);
    }

    ld cnt = 0;
    ld lcnt, rcnt;
    lcnt = rcnt = 0;
    for (int i = 0; i + 1 < (int)lf.size(); i++) 
        lcnt += (lf[i+1] - lf[i]) * pow2[i];
    for (int i = 0; i + 1 < (int)rg.size(); i++) 
        rcnt += (rg[i+1] - rg[i]) * pow2[i];
    cnt = lcnt * rcnt;
    
    return cnt / ld(n) / ld(n);
}


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
    pow2[0] = 1;
    for (int i = 1; i < 200; i++) pow2[i] = pow2[i-1] * 0.5;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    sort(v, v+n);
    reverse(v, v+n);

    s.insert(-1);
    s.insert(n);

    ld ans = 0;

    for (int i = 0; i < n; i++) {
        ans += solveone(v[i].second) * v[i].first;
//          if (i % 1000 == 0) eprintf("%d\n", i);
    }

    ans /= 2;

    printf("%.18f\n", (double)ans);
      
    return 0;
}