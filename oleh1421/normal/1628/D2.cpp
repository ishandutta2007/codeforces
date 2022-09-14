//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
///#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=2000100;
const ll mod=1000000007;

ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll f[N],rf[N];
ll C(int n,int k){
    if (k<0 || k>n) return 0;
    return f[n]*rf[k]%mod*rf[n-k]%mod;
}
ll go(int n,int m){
    if (n<0 || m<0) return 0;
    return C(n+m,n);
}
ll pw2[N];
void solve(){
    int n,m;cin>>n>>m;
    ll k;cin>>k;
    f[0]=1ll;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[n]=binpow(f[n],mod-2);
    pw2[0]=1ll;
    pw2[1]=(mod+1)/2;
    for (int i=2;i<=n;i++){
        pw2[i]=(pw2[i-1]*pw2[1])%mod;
    }
    for (ll i=n;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    ll res=0ll;
    for (int i=1;i<=m;i++){
        res+=(k*i)%mod*(go(m-i,n-m)-go(m-i-1,n-m)+mod)%mod*pw2[n-i]%mod;
        res%=mod;
//        cout<<(go(m-i,n-m)-go(m-i-1,m)+mod)%mod<<" ";
    }
    cout<<res<<endl;
//
//    for (int i=1;i<=n;i++){
//        dp[i][0]=0;
//        dp[i][i]=k*i%mod;
//        for (int j=1;j<i;j++){
//            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])*pw2[1]%mod;
//        }
//
//    }
//    cout<<dp[n][m]<<endl;



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