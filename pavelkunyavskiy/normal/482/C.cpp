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

const int MAXN = 20;

ll bad[1<<MAXN];
double p[1<<MAXN];

char s[55][25];

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    int m = strlen(s[0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            int mask = 0;
            for (int k = 0; k < m; k++)
                if (s[i][k] == s[j][k])
                    mask |= (1<<k);
            bad[mask] |= (1LL<<i);
        }
    }

    for (int i = (1<<m)-1; i >= 0; i--)
        for (int j = 0; j < m; j++)
            bad[i & ~(1<<j)] |= bad[i]; 
                
    p[0] = 1;
    ld ans = 0;
    for (int i = 0; i < (1<<m); i++){
//          eprintf("%.2lf ", p[i]);
        ans += p[i] * (__builtin_popcountll(bad[i]) *1.0 / n);
        int cnt = m - __builtin_popcount(i);
        if (cnt == 0) continue;
        double coef = 1.0 / cnt;
        //coef *= __builtin_popcountll(bad[i]) *1.0 / n;
        eprintf("%d %.2lf %.2lf %.2lf\n", i, p[i], 1.0 / cnt, __builtin_popcountll(bad[i]) *1.0 / n);
        for (int j = 0; j < m; j++)
            if (!(i & (1<<j)))
                p[i | (1<<j)] += p[i] * coef;
    }
    printf("%.18f\n", (double)(ans));
      
    return 0;
}