#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 2007;
int A[DIM],dp[DIM][DIM];
int solve(){
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    int res = n*2;
    for(int i = 1;i<=n;++i){
        for(int j = 0;j<i;++j){
            int m = dp[i-1][j];
            if (i>1 && j>0)
                m = max(m,dp[i-2][j-1]);
            dp[i][j] = m+(A[i]==i-j);
            if (j>0)
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
            if (dp[i][j]>=k)
                res = min(res,j);
        }
        dp[i][i] = 0;
       // cout<<res<<endl;
    }
    if (res==n*2)
        cout<<-1<<endl;
    else cout<<res<<endl;
    //exit(0);
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}