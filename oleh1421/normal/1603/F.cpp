//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=10000010;
const ll mod=998244353;
ll pw[N];
ll inv[N];
ll inv1[N];

int dp[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
void solve(){
    int n,k,x;cin>>n>>k>>x;
    if (x==0){
        if (n>k){
            cout<<0<<endl;
            return;
        }
        int res=1;
        for (int i=0;i<n;i++){
            res=res*(pw[k]-pw[i]+mod)%mod;
        }
        cout<<res<<endl;
        return;
    }
    dp[1]=1;
    ll pwN=binpow(2,n+1);
    for (int j=2;j<=k;j++){
        dp[j]=dp[j-1]*(pwN-pw[j-1]+mod)%mod*inv1[j-1]%mod;
    }
    ll res=0ll;
    ll mult=1ll;
    for (int i=1;i<=k;i++) {
        res+=dp[i]*mult;
        res%=mod;
        mult*=(pw[k]-pw[i]+mod);
        mult%=mod;
        mult*=inv[i];
        mult%=mod;
    }
    cout<<res%mod<<endl;
}

int32_t  main()
{
    pw[0]=1;
    inv[0]=1;
    for (int i=1;i<N;i++){
        pw[i]=(pw[i-1]*2)%mod;
        inv[i]=(1ll*inv[i-1]*(mod+1ll)/2ll)%mod;
    }
    for (int i=0;i<N;i++){
        inv1[i]=binpow(pw[i]-1,mod-2);
    }
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
3 2 3
1 2
1 6
1 14
15


2 1 1
dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*pw[i])%mod;
dp[i][j]=(dp[i-1][j]*pw[j-1]+dp[i-1][j-1]*pw[j-1])%mod;
dp[i-1][j]*(pw[j-1]-1)=dp[i-1][j-1]*(pw[i]-pw[j-1])
**/