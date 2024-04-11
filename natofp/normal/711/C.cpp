#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=105;
ll dp[nax][nax][nax];
ll inf = 1e18+5;
int n,m,k;
ll a[nax];
ll cost[nax][nax];

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>cost[i][j];
    }
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
        {
            for(int z=0;z<=100;z++)
            {
                dp[i][j][z]=inf;
            }
        }
    }
    if(a[1]==0)
    {
        for(int i=1;i<=m;i++)
        {
            dp[1][i][1]=cost[1][i];
        }
    }
    else
    {
        dp[1][a[1]][1]=0;
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=0)
        {
            int cc=a[i];
            for(int pop=1;pop<=m;pop++)
            {
                for(int spojne=1;spojne<=k;spojne++)
                {
                    if(pop==cc)
                    {
                        dp[i][cc][spojne]=min(dp[i][cc][spojne],dp[i-1][cc][spojne]);
                    }
                    else dp[i][cc][spojne]=min(dp[i][cc][spojne],dp[i-1][pop][spojne-1]);
                }
            }
        }
        else if(a[i]==0)
        {
            vector<pair<ll,int> > ziomale;
            for(int spojne=1;spojne<=k;spojne++)
            {
                ziomale.clear();
                for(int j=1;j<=m;j++)
                {
                    ziomale.push_back({dp[i-1][j][spojne-1],j});
                }
                sort(ziomale.begin(),ziomale.end());
                for(int cc=1;cc<=m;cc++)
                {
                    dp[i][cc][spojne]=min(dp[i][cc][spojne],dp[i-1][cc][spojne]+cost[i][cc]);
                    if(m==1) continue;
                    ll val=ziomale[0].first;
                    if(cc==ziomale[0].second) val=ziomale[1].first;
                    dp[i][cc][spojne]=min(dp[i][cc][spojne],val+cost[i][cc]);
                }
            }
        }
    }
    ll res=inf;
    for(int i=1;i<=m;i++)
    {
        res=min(res,dp[n][i][k]);
    }
    if(res==inf) cout<<-1;
    else cout<<res;
    return 0;
}