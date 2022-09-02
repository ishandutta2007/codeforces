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

#define TASKNAME "C"

#ifdef LOCAL
static struct __timestamper {
    ~__timestamper(){
        TIMESTAMP(end);
    }
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;


const int MOD = 1000000007;
const int MAXN = 2010;

int dp[MAXN][MAXN];
int sum[MAXN][MAXN];
char s[MAXN];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n,k;
    while (scanf("%d%d%s",&n,&k,s) == 3){
        memset(dp, 0, sizeof(dp));
        dp[n][0] = 1;

        for (int i = n-1; i >= 0; i--){
            for (int j = 0; j <= k; j++){
                sum[i][j] = (sum[i+1][j] + (s[i] - 'a') * 1LL* dp[i+1][j]) % MOD;
                dp[i][j] = sum[i][j];
                int last = -1;
                for (int ne = i; ne < n; ne++){
                   last = ne;
                   int diff = (ne - i + 1) * (n - ne);
                   if (j - diff >= 0)
                       dp[i][j] = (dp[i][j] + (25 - (s[ne] - 'a')) * 1LL * dp[ne+1][j - diff]) % MOD;
                   else 
                       break;
                }
                assert(last != -1);
                for (int ne = n-1; ne > last; ne--){
                   int diff = (ne - i + 1) * (n - ne);
                   if (j - diff >= 0)
                       dp[i][j] = (dp[i][j] + (25 - (s[ne] - 'a')) * 1LL * dp[ne+1][j - diff]) % MOD;
                   else 
                       break;
                }
            }
            dp[i][0] += 1;
        }

        printf("%d\n", dp[0][k]);
    }   
    return 0;
}