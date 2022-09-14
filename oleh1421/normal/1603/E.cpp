//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=210;
ll mod;
int n;
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
int dp[N][N][N];
ll f[N];
ll rf[N];

void solve(){

    cin>>n>>mod;
    f[0]=rf[0]=1;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
        rf[i]=binpow(f[i],mod-2);
    }
    ll res=0ll;
    int VVV=n+1;
    int cnt=0;
    for (int mn=n;mn>=1;mn--){
        memset(dp,0,sizeof(dp));
        for (int cn=1;cn<=mn;cn++){
            dp[mn][0][cn]=rf[cn];
        }
        for (int el=mn;el<=n;el++){
            for (int sum=0;sum<=mn;sum++){
                for (int cn=1;cn<=n;cn++){
                    int L=(el==n);
                    int R=min({n,((el+1-cn)*mn-sum)/(el+1),(mn-sum)/(el+1-mn)});
                    for (int nw=L;nw<=R;nw++){
                        if (sum+nw*(el+1-mn)>mn) exit(1);
                        dp[el+1][sum+nw*(el+1-mn)][cn+nw]=(dp[el+1][sum+nw*(el+1-mn)][cn+nw]+dp[el][sum][cn]*rf[nw])%mod;
                    }
                }
            }
        }
        ll last=res;
        for (int sum=0;sum<=mn;sum++){
            res=(res+dp[n+1][sum][n]*f[n])%mod;
        }
        if (last==res) cnt++;
        else cnt=0;
        if (cnt==3) break;
    }
//    cout<<VVV<<endl;
    res+=2;
    res%=mod;
    cout<<res<<endl;

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
/**
200 999999937

**/