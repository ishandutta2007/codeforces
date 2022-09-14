#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const ll mod=998244353;
const ll inv2=(998244353+1)/2ll;
ll dp[N];
ll pw2[N];
ll sum[N];
void solve(){
    int n;cin>>n;
    dp[0]=1ll;
    sum[0]=1ll;
    pw2[0]=1ll;
    for (int i=1;i<=n;i++){
        pw2[i]=(pw2[i-1]*inv2)%mod;
    }
//    ll A=
    for (int i=1;i<=n;i++){
        dp[i]=(sum[i-1]*pw2[1])%mod;
        sum[i]=dp[i]+sum[i-2]*pw2[2];
        sum[i]%=mod;
//        for (int j=1;j<=i;j+=2){
//            dp[i]+=dp[i-j*2+1]*pw2[j*2-1];
//            dp[i]%=mod;
//        }
    }
    cout<<(dp[n])%mod<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}