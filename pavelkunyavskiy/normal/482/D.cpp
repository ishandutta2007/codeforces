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

const int MOD = 1000000007;

void add(int& a, int b) {
    if ((a += b) >= MOD) a -= MOD;
}

int mul(int a, int b) {
    return (a * ll(b)) % MOD;
}

const int MAXN = 110000;

int dp[MAXN][2];
vector<int> g[MAXN];


void dfs(int v) {
    int dp2[8];
    memset(dp2, 0, sizeof(dp2));
    dp2[0] = 1;
    for (int i = 0; i < (int)g[v].size(); i++) {
        int u = g[v][i];
        dfs(u);
        int dp3[8];
        memset(dp3, 0, sizeof(dp3));
        for (int j = 0; j < 8; j++) {
            add(dp3[j], dp2[j]);
            add(dp3[j | 1], mul(dp2[j], dp[u][0]));
            add(dp3[(j | 2) ^ 4], mul(dp2[j], dp[u][1]));
        }
        memcpy(dp2, dp3, sizeof(dp3));
    }
    for (int i = 0; i < 8; i++) {
        int parity = i >> 2;
        add(dp[v][parity ^ 1], dp2[i]);
        if (i & (1<<!parity)) add(dp[v][parity ^ 1], dp2[i]);
    }
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
    int n;
    scanf("%d",&n);
    for (int i = 1; i < n; i++){
        int p;
        scanf("%d",&p);
        --p;
        g[p].pb(i);
    }

    dfs(0);
    int ans = 0;
    add(ans, dp[0][0]);
    add(ans, dp[0][1]);
    printf("%d\n", ans);
      
    return 0;
}