//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define endl '\n'
const int N=2030;
const int mod=998244353;
ll dp[N][N];
ll val1[N];
ll val2[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=0;i<=m;i++) dp[0][i]=1;
    for (int i=1;i<=n;i++){
        dp[i][0]=1;
        for (int j=1;j<=m;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    ll res=0ll;
    for (int a=1;a<m;a++){
        int b=m-a;
        ll sum=0ll;
        for (int i=1;i<=n;i++){
            val1[i]=dp[i-1][a]*dp[n-i][a-1]%mod;
            val2[i]=dp[i-1][b-1]*dp[n-i][b]%mod;
            res+=sum*val2[i]*2ll;
            res%=mod;
            sum+=val1[i];
            sum%=mod;
        }
    }
    for (int i=1;i<n;i++){
        for (int a=1;a<m;a++){
            val1[a]=dp[i-1][a]*dp[i][m-a-1]%mod;
        }
        for (int b=1;b<m;b++){
            val2[b]=dp[n-i][m-b-1]*dp[n-i-1][b]%mod;
        }
        val2[m]=0;
        for (int b=m-1;b>=1;b--){
            val2[b]+=val2[b+1];
            val2[b]%=mod;
        }
        for (int a=1;a<m;a++){
            res+=val1[a]*val2[m-a+1]*2ll;
            res%=mod;
        }
    }
    cout<<res<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}

/**
000
000



**/