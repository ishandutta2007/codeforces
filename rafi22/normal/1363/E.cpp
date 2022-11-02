#include <bits/stdc++.h>

using namespace std;

vector <long long> G[200007];
bool odw[200007];
long long mini[200007];
long long cost[200007];
long long ile[200007][2];
long long ans=0;

void dfs(long long v,long long o,long long mn)
{
    odw[v]=1;
    for(long long i=0;i<G[v].size();i++)
    {
        if(!odw[G[v][i]])
        {
            dfs(G[v][i],v,min(mn,cost[v]));
        }
    }
    if(cost[v]<mn)
    {
        long long x=min(ile[v][0],ile[v][1]);
        ans+=2*x*cost[v];
        ile[v][0]-=x;
        ile[v][1]-=x;
    }
    ile[o][0]+=ile[v][0];
    ile[o][1]+=ile[v][1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,a,b;
    cin>>n;
    bool x,y;
    long long c1=0,c2=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>cost[i]>>x>>y;
        if(x==1&&y==0)
        {
            ile[i][0]++;
            c1++;
        }
        else if(x==0&&y==1)
        {
            ile[i][1]++;
            c2++;
        }
    }
    for(long long i=1;i<n;i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,0,1000000007);
    if(c1!=c2) cout<<-1;
    else cout<<ans;
    return 0;
}