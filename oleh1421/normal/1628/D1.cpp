//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
///#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=5010;
const ll mod=1000000007;
const ll pw2=(mod+1)/2;
ll dp[N][N];
void solve(){
    int n,m;cin>>n>>m;
    ll k;cin>>k;
    for (int i=1;i<=n;i++){
        dp[i][0]=0;
        dp[i][i]=k*i%mod;
        for (int j=1;j<i;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*pw2%mod;
        }

    }
    cout<<dp[n][m]<<endl;



}

int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
3
c
baa
abc


abc
b
a
**/