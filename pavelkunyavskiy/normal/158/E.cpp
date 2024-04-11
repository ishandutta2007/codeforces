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

const int MAXN = 4100;

int t[MAXN];
int d[MAXN];
int n,k;

int dp[MAXN][MAXN];

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++)
        scanf("%d %d",&t[i],&d[i]);

    if (k == n){
        cout << 86400 << endl;
        return 0;
    }
             


    for (int i = 0; i <= k; i++)
        dp[0][i] = 1;
    dp[0][0] = t[0]+d[0];

    for (int i = 1; i < n; i++)
        for (int j = 0; j <= k; j++){
            if (j == 0){
                dp[i][j] = max(t[i],dp[i-1][j])+d[i];
                continue;
            }
            dp[i][j] = min(dp[i-1][j-1], max(t[i],dp[i-1][j])+d[i]);
        }

    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++){
            int nid = i+(k-j)+1;
            int sleepto;
            if (nid >= n)
                sleepto = 86401;
            else
                sleepto = t[nid];
            ans = max(ans,sleepto - dp[i][j]);
        }

    ans = max(ans,t[k]-1);

    cout << ans << endl;      
    return 0;
}