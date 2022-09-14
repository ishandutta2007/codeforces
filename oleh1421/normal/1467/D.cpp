//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=5010;
const ll mod=1000000007;
ll a[N];
ll c[N];
ll dp[N][N];
void solve(){
    int n,k,q;cin>>n>>k>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) dp[0][i]=1ll;
    for (int i=1;i<=k;i++){
        for (int j=1;j<=n;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<=k;j++){
            c[i]+=dp[j][i]*dp[k-j][i];
            c[i]%=mod;
        }
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        res+=a[i]*c[i];
        res%=mod;
    }
    for (int i=1;i<=q;i++){
        int ind,x;cin>>ind>>x;
        res+=mod-a[ind]*c[ind]%mod;
        a[ind]=x;
        res+=a[ind]*c[ind];
        res%=mod;
        cout<<res<<endl;
    }
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