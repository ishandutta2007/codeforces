#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int dp[82][100001];
int x[82];
int r[82];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++) {
        int x,r;cin>>x>>r;
        v.push_back({x,r});
    }
    sort(v.begin(),v.end());
    for (int i=0;i<n;i++){
        x[i+1]=v[i].first;
        r[i+1]=v[i].second;
    }
    for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) dp[i][j]=m+1;
    dp[0][0]=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=m;j++) dp[i][j]=dp[i-1][j];
        for (int j=x[i]+r[i];j<=x[i]+r[i]+m;j++){
            dp[i][min(j,m)]=min(dp[i][min(j,m)],dp[i-1][max(0,x[i]-j+x[i]-1)]+(j-x[i]-r[i]));
        }
        for (int j=m-1;j>=0;j--) dp[i][j]=min(dp[i][j],dp[i][j+1]);
    }
    cout<<dp[n][m];
    return 0;
}