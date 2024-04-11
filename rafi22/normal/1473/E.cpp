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
int d[200007][4];
vector<pair<int,int>>G[200007];

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
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            G[a].pb({b,c});
            G[b].pb({a,c});
        }
        set<pair<int,pair<int,int>>>Q;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<4;j++)
            {
                d[i][j]=inf;
            }
        }
        Q.insert({0,{1,0}});
        d[1][0]=0;
        int xd=1;
        while(!Q.empty())
        {
            pair<int,pair<int,int>>p=*Q.begin();
            Q.erase(Q.begin());
            int v=p.nd.st;
            int t=p.nd.nd;
            for(auto u:G[v])
            {
                if(t==0&&d[u.st][3]>d[v][t]+u.nd)
                {
                    Q.erase({d[u.st][3],{u.st,3}});
                    d[u.st][3]=d[v][t]+u.nd;
                    Q.insert({d[u.st][3],{u.st,3}});
                }
                if((t&1)==0&&d[u.st][t|1]>d[v][t])
                {
                    Q.erase({d[u.st][t|1],{u.st,t|1}});
                    d[u.st][t|1]=d[v][t];
                    Q.insert({d[u.st][t|1],{u.st,t|1}});
                }
                if((t&2)==0&&d[u.st][t|2]>d[v][t]+2*u.nd)
                {
                    Q.erase({d[u.st][t|2],{u.st,t|2}});
                    d[u.st][t|2]=d[v][t]+2*u.nd;
                    Q.insert({d[u.st][t|2],{u.st,t|2}});
                }
                if(d[u.st][t]>d[v][t]+u.nd)
                {
                    Q.erase({d[u.st][t],{u.st,t}});
                    d[u.st][t]=d[v][t]+u.nd;
                    Q.insert({d[u.st][t],{u.st,t}});
                }
            }
        }
        for(int i=2;i<=n;i++) cout<<d[i][3]<<" ";
    }

    return 0;
}