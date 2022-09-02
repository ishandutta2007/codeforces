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

#define TASKNAME "D"

typedef long long ll;
typedef long double ld;


const int MOD = 1000000007;

const int MAXN = 510;

int dp[MAXN][MAXN];
int c[MAXN][MAXN];


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif
    int cnt1,cnt2;
    cnt1 = cnt2 = 0;
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++){
        int a;
        scanf("%d",&a);
        if (a == 1)
            cnt1++;
        else
            cnt2++;
    }

    dp[0][0] = 1;
    c[0][0] = 1;

//    cnt1 = cnt2 = 10;

    for (int i = 0; i <= cnt2; i++)
        for (int j = 0; j <= cnt2; j++){
            if (i) c[i][j] = (c[i][j] + c[i-1][j]) % MOD;
            if (i && j) c[i][j] = (c[i][j] + c[i-1][j-1]*1LL*j) % MOD;
        }



    for (int i = 0; i <= cnt1; i++)
        for (int j = 0; j <= cnt2; j++){
            if (i) {
                dp[i][j] = 0;
                for (int k = 0; k <= j; k++)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k]*1LL*c[j][k]) % MOD;
                if (i >= 2){
                    dp[i][j] = (dp[i][j] + dp[i-2][j] *1LL* (i-1)) % MOD;
                    for (int k = 1; k <= j; k++)
                        dp[i][j] = (dp[i][j] + ((dp[i-2][j-k]*1LL*c[j][k]) % MOD * 1LL*(i-1))%MOD *1LL* (k+1)) % MOD;
                }
            } else {
                if (j)
                    dp[i][j] = (dp[i][j-1] * 1LL* j) % MOD;
            }
            eprintf("%d%c",dp[i][j]," \n"[j==cnt2]);
        }

    printf("%d\n",dp[cnt1][cnt2]);
            
      
    TIMESTAMP(end);
    return 0;
}