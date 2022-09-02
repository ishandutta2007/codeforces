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


int dp[5010][5010];

int h[5010];

int r[5010];

int Psum[5010];


int n;

int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d",&n);
    for (int i = 0; i < n; i++) 
        scanf("%d",&h[i]);

    memset(dp,-1,sizeof(dp));

    for (int i = 0; i < n; i++){
        if (i == 0 || (h[i] >= h[i-1] && dp[0][i-1] == 0))
            dp[0][i] = 0;
        r[i] = i;
    }

    for (int i = 0; i < n; i++)
        Psum[i+1] = Psum[i] + h[i];

    if (dp[0][n-1] != -1){
        printf("0\n");
        return 0;
    }

    for (int i = 0; i <= n; i++){
        for (int j = 0; j < n; j++){                  
            if (i && j && dp[i-1][j-1] != -1)
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
            if (dp[i][j] == -1)
                continue;
            int& r = ::r[j];
            int nv = Psum[j+1] - Psum[dp[i][j]] + Psum[j+1];
            while (r < n && Psum[r+1] < nv)
                r++;
            if (r < n)
                dp[i+r-j-1][r] = max(dp[i+r-j-1][r], j+1); 
        }

        if (dp[i][n-1] != -1){
           printf("%d\n",i);
           return 0;
        }
    }

    assert(false);      
    return 0;
}