#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
long long dp[50005][505]={0};
vector<int>v[50005];
bool mark[50005]={0};
long long ans=0;
int n,k;
void dfs(int x)
{
    mark[x]=true;
    for(int i=0;i<v[x].size();i++)
    if(!mark[v[x][i]])
    {
        mark[v[x][i]]=true;
        dfs(v[x][i]);
        for(int j=0;j<=k-1;j++)
            ans+=dp[v[x][i]][j]*dp[x][k-j-1];
        for(int j=0;j<=k-1;j++)
            dp[x][j+1]+=dp[v[x][i]][j];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        dp[i][0]=1;
    dfs(1);
    cout<<ans<<endl;
}