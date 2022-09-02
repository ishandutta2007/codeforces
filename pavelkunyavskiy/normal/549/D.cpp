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

int n,m;
char s[110][110];
long long val[110][110];

int main(){
#ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
#endif
    while (scanf("%d%d",&n,&m)==2){
        for (int i = 0; i < n; i++)
            scanf("%s", s[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                val[i][j] = (s[i][j] == 'W' ? 1 : -1);
        int ans = 0;
        for (int i = n-1; i >= 0; i--)
            for (int j = m-1; j >= 0; j--){
                if (val[i][j] == 0) continue;
                ans++;
                long long c = val[i][j];
                for (int i1 = 0; i1 <= i; i1++)
                    for (int j1 = 0; j1 <= j; j1++)
                        val[i1][j1] -= c;
            }
        printf("%d\n", ans);
    }

      
    return 0;
}