#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int d[3007][3007];
int s[3007][3007];
int DP[3007][3007];
vector<int>G[3007];

void dfs(int v,int o,int x,int r)
{
    d[r][v]=x;
    s[r][v]=1;
    for(auto u:G[v])
    {
        if(u==o) continue;
        dfs(u,v,x+1,r);
        s[r][v]+=s[r][u];
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,a,b;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        for(int i=1;i<=n;i++) dfs(i,-1,0,i);
        for(int i=1;i<=n;i++)
        {
            for(auto j:G[i])
            {
                DP[i][j]=s[i][j]*s[j][i];
            }
        }
        vector<pair<int,pair<int,int>>>vec;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                vec.pb({d[i][j],{i,j}});
            }
        }
        sort(vec.begin(),vec.end());
        for(auto p:vec)
        {
            int u=p.nd.st,v=p.nd.nd;
            for(auto o:G[u])
            {
                if(d[o][v]>d[u][v]) continue;
                DP[u][v]=max(DP[u][v],DP[o][v]+s[v][u]*s[u][v]);
            }
            for(auto o:G[v])
            {
                if(d[o][u]>d[u][v]) continue;
                DP[u][v]=max(DP[u][v],DP[u][o]+s[v][u]*s[u][v]);
            }
            DP[v][u]=DP[u][v];
           // cout<<u<<" "<<v<<" "<<DP[u][v]<<endl;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ans=max(ans,DP[i][j]);
            }
        }
        cout<<ans;
    }

    return 0;
}