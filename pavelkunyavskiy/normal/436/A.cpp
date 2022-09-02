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




int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
    
    int n, x0;  
    while (scanf("%d %d",&n,&x0) == 2){
        vector<int> ty(n), h(n), m(n);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d",&ty[i],&h[i],&m[i]);

        int ans = 0;
        for (int start = 0; start < 2; start++){
            int cur = 0;
            int curty = start;
            int x = x0;
            vector<bool> used(n);
            while (true) {
                int id = -1;
                for (int i = 0; i < n; i++)
                    if (!used[i] && ty[i] == curty && h[i] <= x){
                        if (id == -1 || m[id] < m[i])
                            id = i;
                    }
                if (id == -1) break;
                curty ^= 1;
                cur++;
                x += m[id];
                used[id] = true;
            }
            ans = max(ans, cur);
        }
        printf("%d\n", ans);
    }   
      
  return 0;
}