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

const int MOD = 1000000007;

int pow(int a,ll b){
    if (!b) return 1;
    if (b&1) return (pow(a,b-1)*1LL*a)%MOD;
    int temp = pow(a,b>>1);
    return (temp*1LL*temp)%MOD;
}

const int MAXN = 110;

int c[MAXN][MAXN];

int c1[MAXN];
int c2[MAXN];

int dp[MAXN][MAXN*MAXN];



int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

     c[0][0] = 1;
     for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++){
            if (i) c[i][j] = (c[i][j] + c[i-1][j]) % MOD;
            if (i && j) c[i][j] = (c[i][j] + c[i-1][j-1]) % MOD;
        }
                                  

     int n,k;
     ll m;                          

     cin >> n >> m >> k;


     for (int i = 0; i <= n; i++)
        c1[i] = pow(c[n][i], m/n);
     for (int i = 0; i <= n; i++)
        c2[i] = pow(c[n][i], m/n+1);

     dp[0][0] = 1;


     for (int i = 0; i < n; i++){
        int* c = (i < m%n?c2:c1);
        for (int j = 0; j <= k; j++){
            for (int t = 0; j+t <= k && t <= n; t++)
                dp[i+1][j+t] = (dp[i+1][j+t] + dp[i][j] * 1LL * c[t]) % MOD;
        }
     }

     cout << dp[n][k] << endl;

      
     return 0;
}