//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int dp[N],a[N],cnt[N];
void solve(){
    int n;cin>>n;
    int mx=0;
    for (int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
    for (int i=0;i<=mx;i++) cnt[i]=dp[i]=0;
    for (int i=1;i<=n;i++) cnt[a[i]]++;
    int res=0;
    for (int i=1;i<=mx;i++){
        dp[i]+=cnt[i];
        for (int j=i*2;j<=mx;j+=i) dp[j]=max(dp[j],dp[i]);
        res=max(res,dp[i]);
    }
    cout<<n-res<<endl;



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
4 5
3 2 1 2
2 1 2 1
*/