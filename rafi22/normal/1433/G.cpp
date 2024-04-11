#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int d[1007][1007];
vector<pair<int,int>>G[1007];
set<pair<int,int>>q;
int ans[1007];
int e1[1007];
int e2[1007];

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
        int n,m,k,a,b,c;
        cin>>n>>m>>k;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b>>c;
            G[a].pb({b,c});
            G[b].pb({a,c});
            e1[i]=a;
            e2[i]=b;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) d[i][j]=inf;
            d[i][i]=0;
            q.insert({0,i});
            while(!q.empty())
            {
                pair<int,int> pr=*q.begin();
                int v=pr.nd;
                q.erase(q.begin());
                for(auto u:G[v])
                {
                    if(d[i][u.st]>d[i][v]+u.nd)
                    {
                        q.erase({d[i][u.st],u.st});
                        d[i][u.st]=d[i][v]+u.nd;
                        q.insert({d[i][u.st],u.st});
                    }
                }
            }
        }
        for(int i=0;i<k;i++)
        {
            cin>>a>>b;
            for(int j=1;j<=m;j++)
            {
                ans[j]+=min(d[a][b],min(d[a][e1[j]]+d[b][e2[j]],d[a][e2[j]]+d[b][e1[j]]));
            }
        }
        int mini=inf;
        for(int i=1;i<=m;i++) mini=min(mini,ans[i]);
        cout<<mini;
    }

    return 0;
}