//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=510;
const ll mod=998244353;
ll C[N][N];
ll dp[N][N];
ll pw[N][N];
void solve(){
    ll n,x;cin>>n>>x;
    C[0][0]=1ll;
    for (int i=1;i<N;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        pw[i][0]=1;
        for (int j=1;j<N;j++) pw[i][j]=(pw[i][j-1]*(i*1ll))%mod;
    }
    for (int i=1;i<=x;i++) dp[0][i]=1,dp[1][i]=0;
    for (int i=2;i<=n;i++){
        for (int j=1;j<=x;j++){
            dp[i][j]=pw[min(i-1,j)][i];
            if (j>(i-1)){
                for (int t=0;t<i;t++){
                    dp[i][j]+=C[i][t]*pw[i-1][t]%mod*dp[i-t][j-(i-1)];
                    dp[i][j]%=mod;
                }
            }
        }
    }
    cout<<dp[n][x]<<endl;


}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
//6 3 7 5 6
/**
7 1 2
2 15 6 3 7 5 6
3 5
1
**/