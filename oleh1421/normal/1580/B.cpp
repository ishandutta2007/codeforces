#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
ll n,m,k,mod;
const int N=110;
ll dp[N][N][N];
int mx[N][N];
ll c[N][N];

void solve(){
    cin>>n>>m>>k>>mod;
    for (int i=0;i<=n;i++){
        c[i][0]=1;
        for (int j=1;j<=i;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    dp[1][1][1]=1;
    for (int j=2;j<=n;j++){
        dp[1][j][1]=(dp[1][j-1][1]*1ll*(j*1ll))%mod;
    }
    dp[1][0][0]=1;
    for (int i=0;i<=n;i++){
        mx[1][i]=1;
    }
    int CNT=0;
    int TOT=0;
    for (int i=2;i<=m;i++){
        dp[i][0][0]=1;
        for (int j=1;j<=n;j++){
            for (int t=0;t<=j;t++){
                dp[i][j][t]=0;
                for (int p=1;p<=j;p++){
                    for (int cn=max(0,t-mx[i-1][j-p]);cn<=min(t,mx[i-1][p-1]);cn++){
                        dp[i][j][t]=(dp[i][j][t]+dp[i-1][p-1][cn]*dp[i-1][j-p][t-cn]%mod*c[j-1][p-1])%mod;
                    }
//                    for (int cn=0;cn<=t;cn++){
//                        dp[i][j][t]=(dp[i][j][t]+dp[i-1][p-1][cn]*dp[i-1][j-p][t-cn]%mod*c[j-1][p-1])%mod;
//                    }
                }
                if (dp[i][j][t]) mx[i][j]=t;
            }
        }
    }
    cout<<dp[m][n][k]<<endl;
}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}