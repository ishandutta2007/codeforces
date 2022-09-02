#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;


int dp[110][110][730];
int a[110];
int n;

int main()
{
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    memset(dp,120,sizeof(dp));
    int INF = dp[0][0][0];
    dp[0][0][10] = 0;

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    sort(a,a+n);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= 720; k++){
                if (dp[i][j][k] >= INF)
                    continue;
                if (i != n && k + a[i] <= 720)
                    dp[i+1][j+1][k+a[i]] = min(dp[i+1][j+1][k+a[i]], dp[i][j][k] + max(k+a[i]-360,0));             
                if (i != n)
                    dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
                dp[i][j][k+1] = min(dp[i][j][k+1],dp[i][j][k]);
            }





    for (int i = n; i >= 0; i--)
        if (dp[n][i][720] < INF){
            printf("%d %d\n",i,dp[n][i][720]);
            return 0;
        }

    assert(false);

    return 0;
}