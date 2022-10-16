#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=5e5+5;
int n,k;
ll dp[nax][2];
vector<pair<int,int> > adj[nax];

void dfs(int v,int p,int waga)
{
    for(int i=0;i<adj[v].size();i++)
    {
        int cel=adj[v][i].first;
        if(cel!=p) dfs(cel,v,adj[v][i].second);
    }
    vector<pair<ll,int> >ziomale;
    for(int i=0;i<adj[v].size();i++)
    {
        int cel=adj[v][i].first;
        if(cel==p) continue;
        ziomale.push_back({dp[cel][1]-dp[cel][0],cel});
    }
    sort(ziomale.begin(),ziomale.end());
    ll sum=0;
    reverse(ziomale.begin(),ziomale.end());
    for(int i=0;i<ziomale.size();i++)
    {
        if(i<k)
        {
            int akt=ziomale[i].second;
            sum+=max(dp[akt][1],dp[akt][0]);
        }
        else sum+=dp[ziomale[i].second][0];
    }
    dp[v][0]=sum;
    sum=waga;
    for(int i=0;i<ziomale.size();i++)
    {
        if(i<k-1)
        {
            int akt=ziomale[i].second;
            sum+=max(dp[akt][1],dp[akt][0]);
        }
        else sum+=dp[ziomale[i].second][0];
    }
    dp[v][1]=sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>>q;
    while(q--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int a,b,c; cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        dfs(1,0,0);
        cout<<max(dp[1][1],dp[1][0])<<"\n";
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=dp[i][1]=0;
            adj[i].clear();
        }
    }
    return 0;
}