
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int ans[50][50][50][50],dp[1001][1001],a[1001][1001];
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j,n,m,q1,p,q,r,s,x,y;
    string str;
    cin>>n>>m>>q1;
    for(i=1;i<=n;i++)
    {
        cin>>str;
        str=" "+str;
        for(j=1;j<=m;j++)
        a[i][j]=str[j]-'0';
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            for(x=i;x>=1;x--)
            {
                for(y=j;y>=1;y--)
                {
                    if(dp[i][j]+dp[x-1][y-1]==dp[i][y-1]+dp[x-1][j])
                    ans[x][y][i][j]++;
                    ans[x][y][i][j]+=ans[x+1][y][i][j]+ans[x][y+1][i][j]-ans[x+1][y+1][i][j];
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            for(x=i;x<=n;x++)
            {
                for(y=j;y<=m;y++)
                ans[i][j][x][y]+=ans[i][j][x-1][y]+ans[i][j][x][y-1]-ans[i][j][x-1][y-1];
            }
        }
    }
    
    while(q1--)
    {
        cin>>p>>q>>r>>s;
        cout<<ans[p][q][r][s]<<endl;
    }
}