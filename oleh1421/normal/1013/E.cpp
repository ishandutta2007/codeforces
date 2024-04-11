#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if(a>b) a=b;
typedef long long ll;
using namespace std;
ll dp[5010][5010][2];
ll a[5010];
ll f(int pos,ll cur){
     return max(a[pos]-cur+1ll,0ll);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            for (int k=0;k<2;k++){
                dp[i][j][k]=10000000001ll;
            }
        }
    }
    dp[1][1][1]=0;
    dp[1][0][0]=0;
    int maxk=n/2+n%2;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=maxk;j++){
             ///dp[i][j][0]
             MINX(dp[i+1][j][0],dp[i][j][0]);
             MINX(dp[i+1][j+1][1],dp[i][j][0]+f(i,a[i+1])*1ll);
             ///dp[i][j][1]
             MINX(dp[i+1][j][0],dp[i][j][1]+f(i+1,a[i])*1ll);
             MINX(dp[i+2][j+1][1],dp[i][j][1]+f(i+1,min(a[i],a[i+2]))*1ll);
        }
    }
    for (int i=1;i<=maxk;i++){
        cout<<min(dp[n][i][0],dp[n][i][1])<<" ";
    }
    return 0;
}
//2 6 -2 -6  2