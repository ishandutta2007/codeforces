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


const int MAXN = 2010;

int nd[MAXN][MAXN];
int  d[MAXN][MAXN];
int n;

bool solve(){      
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d",&nd[i][j]);
    for (int i = 0; i < n; i++) {
        if (nd[i][i] != 0) return false;
        for (int j = i+1; j < n; j++) 
            if (nd[i][j] != nd[j][i] || nd[i][j] == 0) return false;
    }

    vector<bool> used(n, false);
    vector<int> cd(n, (int)1.1e9);
    vector<int> cp(n, -1);
    cd[0] = 0;
    for (int i = 0; i < n; i++) {
        int mid = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (mid == -1 || cd[j] < cd[mid]))
                mid = j;
        assert(mid != -1);
        for (int j = 0; j < n; j++)
            if (used[j])
                d[mid][j] = d[j][mid] = d[j][cp[mid]] + cd[mid];
        used[mid] = true;
        for (int j = 0; j < n; j++)
            if (nd[mid][j] < cd[j])
                cd[j] = nd[mid][j], cp[j] = mid;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (d[i][j] != nd[i][j])
                return false;
    return true;
}


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    while (scanf("%d",&n) == 1)
        if (solve())
            printf("YES\n");
        else
            printf("NO\n");

      
  return 0;
}