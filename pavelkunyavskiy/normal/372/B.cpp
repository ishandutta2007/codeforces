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
#endif

typedef long long ll;
typedef long double ld;

int sum[45][45];

int get(int lx,int ly,int rx,int ry){
    return sum[rx+1][ry+1] - sum[lx][ry+1] - sum[rx+1][ly] + sum[lx][ly];
}

int cntd[45][45];
int cntu[45][45];

int dp[45][45][45][45];

int calc(int lx,int ly,int rx,int ry){
    if (lx > rx || ly > ry)
        return 0;
    int& res = dp[lx][ly][rx][ry];
    if (res != -1) return res;
    res = 0;
    res += calc(lx + 0, ly + 1, rx, ry);
    res += calc(lx + 1, ly + 0, rx, ry);
    res -= calc(lx + 1, ly + 1, rx, ry);

    int mv;
    mv = (rx - lx + 1);
    for (int i = ly; i <= ry; i++){
        mv = min(mv, cntd[lx][i]);
        res += mv;
    }
    return res;
}


char s[45][45];

int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            char c;
            scanf(" %c",&c);
            s[i][j] = c;
            sum[i+1][j+1] = (c == '1') + sum[i][j+1] + sum[i+1][j] - sum[i][j];
            cntu[i][j] = (c == '1') ? 0 : (((i == 0)?0:cntu[i-1][j])+1);
        }
    for (int i = n-1; i >= 0; i--)
        for (int j = 0; j < m; j++){
            cntd[i][j] = (s[i][j] == '1') ? 0 : (((i == n-1)?0:cntd[i+1][j])+1);
        }
            

    memset(dp,-1, sizeof(dp));

    for (int i = 0; i < q; i++){
        int lx,ly,rx,ry;
        scanf("%d %d %d %d",&lx,&ly,&rx,&ry);
        --lx, --ly, --rx, --ry;
        printf("%d\n", calc(lx, ly, rx, ry));
    }

      
    return 0;
}