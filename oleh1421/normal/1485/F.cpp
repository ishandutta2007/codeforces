//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const ll mod=1000000007ll;
ll b[N];
ll dp[N][2];

void solve(){
    int n;cin>>n;
    dp[0][0]=dp[0][1]=1ll;
    for (int i=1;i<=n;i++) cin>>b[i],b[i]+=b[i-1];
    map<ll,ll>add;
    for (int i=1;i<=n;i++){
        dp[i][1]=(dp[i-1][1]*2ll+mod-dp[i-1][0])%mod;
        dp[i][0]=add[b[i]]+(b[i]==0);
//        ll sum=0ll;
//        for (int j=i;j>=1;j--){
//            sum+=b[j];
//            if (sum==0){
//                dp[i][0]+=mod+dp[j-1][1]-dp[j-1][0];
//                dp[i][0]%=mod;
//            }
//        }
//        dp[i][0]+=(sum==0);
        add[b[i]]=(add[b[i]]+dp[i][1]-dp[i][0]+mod)%mod;
    }
    cout<<dp[n][1]<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
2
1 -1


1
*/