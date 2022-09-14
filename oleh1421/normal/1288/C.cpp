#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const ll mod=1000000007ll;
ll dp[30][1010];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    m+=m;
    for (int i=1;i<=n;i++) dp[1][i]=1ll;
    for (int i=2;i<=m;i++){
        for (int last=1;last<=n;last++){
            for (int cur=last;cur<=n;cur++){
                dp[i][cur]+=dp[i-1][last];
                dp[i][cur]%=mod;
            }
        }
    }
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        sum+=dp[m][i];
        sum%=mod;
    }
    cout<<sum;
    return 0;
}