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

int d[100007];
vector<pair<int,int>>G[100007];
int x[100007],y[100007];
set<pair<int,int>>PX;
set<pair<int,int>>PY;

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
        int n,m,sx,sy,fx,fy;
        cin>>n>>m>>sx>>sy>>fx>>fy;
        PX.insert({0,0});
        PX.insert({inf,0});
        PY.insert({0,0});
        PY.insert({inf,0});
        for(int i=1;i<=m;i++)
        {
            cin>>x[i]>>y[i];
            PX.insert({x[i],i});
            PY.insert({y[i],i});
        }
        for(int i=1;i<=m;i++)
        {
            pair<int,int>p;
            p=*PX.upper_bound({x[i],i});
            if(p.nd!=0) G[i].pb({p.nd,p.st-x[i]});
            p=*(--PX.lower_bound({x[i],i}));
            if(p.nd!=0) G[i].pb({p.nd,x[i]-p.st});
            p=*PY.upper_bound({y[i],i});
            if(p.nd!=0) G[i].pb({p.nd,p.st-y[i]});
            p=*(--PY.lower_bound({y[i],i}));
            if(p.nd!=0) G[i].pb({p.nd,y[i]-p.st});
        }
        set<pair<int,int>>Q;
        for(int i=1;i<=m;i++)
        {
            d[i]=min(abs(sx-x[i]),abs(sy-y[i]));
            Q.insert({d[i],i});
        }
        while(!Q.empty())
        {
            pair<int,int>p=*Q.begin();
            Q.erase(p);
            int v=p.nd;
            for(auto u:G[v])
            {
                if(d[v]+u.nd<d[u.st])
                {
                    Q.erase({d[u.st],u.st});
                    d[u.st]=d[v]+u.nd;
                    Q.insert({d[u.st],u.st});
                }
            }
        }
        int ans=abs(sx-fx)+abs(sy-fy);
        for(int i=1;i<=m;i++) ans=min(ans,d[i]+abs(x[i]-fx)+abs(y[i]-fy));
        cout<<ans;
    }

    return 0;
}