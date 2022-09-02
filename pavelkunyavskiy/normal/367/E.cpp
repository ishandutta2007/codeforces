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

#if ( _WIN32 || __WIN32__ )
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
#endif

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

int dp[2][400][400];

void add(int& a,int b){
    if ((a += b) >= MOD) a -= MOD;
}


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int n,m,x;
    scanf("%d %d %d",&n,&m,&x);
    if (n > m){
        printf("0\n");
        return 0;
    }
    --x;

    assert(n < 370);

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for (int it = 0; it < m; it++){
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= i; j++){
                if (it != x) add(dp[1][i][j], dp[0][i][j]);
                add(dp[1][i+1][j], dp[0][i][j]);
                if (it != x) add(dp[1][i][j+1], dp[0][i][j]);
                add(dp[1][i+1][j+1], dp[0][i][j]);
            }
        for (int i = 0; i <= n; i++)
           for (int j = 0; j <= n; j++)
              dp[0][i][j] = dp[1][i][j], dp[1][i][j] = 0;
    }

    int ans = dp[0][n][n];

    for (int i = 1; i <= n; i++)
        ans = (ans * 1LL * i) % MOD;

    printf("%d\n", ans);      
    return 0;
}