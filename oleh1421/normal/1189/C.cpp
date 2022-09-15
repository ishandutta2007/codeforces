#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200001];
pair<int,int> dp[200001][31];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++){
        dp[i][1]={(a[i]+a[i+1])/10,(a[i]+a[i+1])%10};
    }
    for (int lg=2;(1<<lg)<=n;lg++){
         for (int i=1;i+(1<<lg)-1<=n;i++){
              dp[i][lg]={(dp[i][lg-1].second+dp[i+(1<<(lg-1))][lg-1].second)/10+dp[i][lg-1].first+dp[i+(1<<(lg-1))][lg-1].first,(dp[i][lg-1].second+dp[i+(1<<(lg-1))][lg-1].second)%10};
         }
    }
    int tt;cin>>tt;
    while (tt--){
        int l,r;cin>>l>>r;
        int len=r-l+1;
        int lg=0;
        while ((1<<lg)<len) lg++;
        cout<<dp[l][lg].first<<'\n';
    }
    return 0;
}