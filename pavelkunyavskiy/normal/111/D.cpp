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

typedef long long int64;
typedef long double ld;


int dp[1100][1100];

const int MOD = 1000*1000*1000 + 7;


int calc(int n,int k){
    if (k > n)
        return 0;
    if (n == 0)
        return (k == 0);
    if (dp[n][k] != -1)
        return dp[n][k];
    return dp[n][k] = (k*1LL*(calc(n-1,k-1) + calc(n-1,k))) % MOD;
}

int pow(int a,int b){
    if (b == 0)
        return 1;
    if (b & 1)
        return (pow(a,b-1)*1LL*a)%MOD;
    int tmp = pow(a,b>>1);
    return (tmp*1LL*tmp) % MOD;
}

int f[1100*1100];
int invf[1100*1100];


int c(int n,int k){
    if (k > n || n < 0)
        return 0;
    return (((f[n] * 1LL *invf[k]) % MOD) *1LL* invf[n-k]) % MOD;
}

void init(){
    f[0] = 1;
    invf[0] = 1;
    for (int i = 1; i < 1000100; i++){
        f[i] = (f[i-1] * 1LL * i) % MOD;
        invf[i] = pow(f[i],MOD-2);
    }
    memset(dp,-1,sizeof(dp));
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    init();

    int ans = 0;
    int n,m,k;


    scanf("%d %d %d",&n,&m,&k);


    if (m == 1){
        cout << pow (k,n) << endl;
        return 0;    
    }


    //cerr << c(1,1) << endl;

    for (int i = 1; i <= n && i <= k; i++){
        int sum2 = 0;
        for (int l = 0; l <= i; l++)
            sum2 = (sum2 + ((c(i,l)*1LL*pow(l,n*(m-2)))%MOD)*1LL*c(k-i,i-l))%MOD;
        ans = (ans + ((sum2 * 1LL * ((c(k,i) *1LL* calc(n,i))%MOD))%MOD)*1LL*calc(n,i)) % MOD;        
    }

    cout << ans << endl;
    
    return 0;
}