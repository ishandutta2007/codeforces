#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=510;
int a[N];
int b[N];
bool dp[N][N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    ll sum=0ll;
    for (int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
        sum+=a[i]+b[i];
    }
    dp[0][0]=true;
    for (int i=1;i<=n;i++){
        for (int j=0;j<k;j++){
            if (a[i]+b[i]<k){
                dp[i][(j+a[i])%k]|=dp[i-1][j];
            } else {
dp[i][(j+a[i])%k]|=dp[i-1][j];
                for (int t=max(0,k-b[i]);t<=min(k-1,a[i]);t++){
                    dp[i][(j+a[i]-t)%k]|=dp[i-1][j];
                }
            }
        }
    }
    ll res=0ll;
    for (ll i=0;i<k;i++){
        if (dp[n][i]) {
            res=max(res,(sum-i-(sum-i+k)%k+0ll)/(k+0ll));
        }
    }
    cout<<res;
    return 0;
}
/*
2 3
1 100
*/