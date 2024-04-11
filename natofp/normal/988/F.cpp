#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int * weight;
    int a,n,m;
    cin>>a>>n>>m;
    vector <bool> rain (a);
    for(int i=0;i<a;i++)
        rain[i]=false;
    weight=new int[m+1];
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        for(int i=l;i<r;i++)
            rain[i]=true;
    }
    vector<pair<int,int> > umbrella(a+1,make_pair(2000000000,-1));
    for(int i=0;i<m;i++)
    {
        int x,p;
        cin>>x>>p;
        weight[i]=p;
        umbrella[x]=min(umbrella[x],make_pair(p,i));
    }
    int dp[a+1][m+1];
    for(int i=0;i<=a;i++)
        for(int j=0;j<m+1;j++)

        {
            dp[i][j]=2000000000;
        }
    dp[0][0]=0;
    for(int i=0;i<a;i++)
        for(int j=0;j<=m;j++)
    {
        if(dp[i][j]==2000000000) continue;
        if(rain[i]==0) dp[i+1][0]=min(dp[i+1][0],dp[i][j]);
        if(j!=0)dp[i+1][j]=min(dp[i+1][j],dp[i][j]+weight[j-1]);
        if(umbrella[i].first!=2000000000) dp[i+1][umbrella[i].second+1]=min(dp[i+1][umbrella[i].second+1],dp[i][j]+umbrella[i].first);


    }
    int naj=dp[a][0];
    for(int i=1;i<=m;i++)
        naj=min(naj,dp[a][i]);
    if(naj==2000000000) naj=-1;
    cout<<naj;
    return 0;
}