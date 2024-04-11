#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=510;
ll binpow(ll a,ll b,ll M){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1,M)*a%M;
    else return binpow(a*a%M,b/2ll,M);
}
ll f[N],rf[N];
ll pw2[N];
ll dp[N][N];
ll cnt[N][N];
void solve(){
    ll n,M;cin>>n>>M;
    f[0]=rf[0]=1ll;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%M;
        rf[i]=binpow(f[i],M-2,M);
    }
    pw2[0]=1ll;
    for (int i=1;i<=n;i++){
        pw2[i]=(pw2[i-1]*2ll)%M;
    }
    dp[0][0]=1ll;
    for (int i=1;i<=n;i++){
        dp[i][0]=rf[i]%M;
        for (int j=1;j<=n;j++){
            for (int t=2;t<i;t++){
                dp[i][j]+=dp[t-1][j-1]*rf[i-t];
                dp[i][j]%=M;
            }
        }
    }
    ll res=0ll;
    for (int i=0;i*2<=n;i++){
        res+=((f[n-i]*dp[n][i])%M)*pw2[n-i*2-1];
        res%=M;
    }
    cout<<res<<endl;



}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**




**/