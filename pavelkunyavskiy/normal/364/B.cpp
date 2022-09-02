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

#define TASKNAME "B"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;


const int MAXN = 55;
const int MAXC = 10010;

bool can[MAXC * MAXN];
int dp[MAXC * MAXN];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,d;
    scanf("%d%d",&n,&d);

    can[0] = 1;

    for (int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        for (int i = MAXC * MAXN - 1; i >= 0; i--)
           if (can[i]) {
              can[i+a] = true;
           }
    }

    vector<int> v;
    v.pb(0);

    pair<int,int> ans = mp(0, 0);

    for (int i = 1; i < MAXN * MAXC; i++) if (can[i]){
        int id = lower_bound(v.begin(), v.end(), i - d) - v.begin();
        if (id == (int)v.size()) break;                
        dp[i] = dp[v[id]] + 1;
//        eprintf("%d <- %d dp = %d\n", i, v[id], dp[i]);
        ans = mp(i, dp[i]);
        v.pb(i);
    }

    printf("%d %d\n", ans.first, ans.second);

      
    return 0;
}