#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
ll cnt,n,m,i,j,k,t,t1,u,v,a,b,res=0,st,en;
vector<ll> buc[200001];
ll par[200001];
vector<pair<pair<ll,ll>,ll>> under,over;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n>>m>>k;
        under.clear();
        over.clear();
        for (i=1;i<=m;i++)
        {
            cin>>u>>v>>a;
            if (a<=k) under.push_back({{u,v},a});
            else over.push_back({{u,v},a});
        }
        sort(under.begin(),under.end(),[](pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){
            return (a.se<b.se);
        });
        sort(over.begin(),over.end(),[](pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){
            return (a.se<b.se);
        });
        for (i=1;i<=n;i++)
        {
            buc[i].clear();
            buc[i].push_back(i);
            par[i]=i;
        }
        cnt=n;
        for (auto g : under)
        {
            u=g.fi.fi;
            v=g.fi.se;
            u=par[u];
            v=par[v];
            if (u!=v)
            {
                cnt--;
                if (buc[u].size()>buc[v].size())
                {
                    for (int g : buc[v])
                    {
                        buc[u].push_back(g);
                        par[g]=u;
                    }
                    buc[v].clear();
                }
                else
                {
                    for (int g : buc[u])
                    {
                        buc[v].push_back(g);
                        par[g]=v;
                    }
                    buc[u].clear();
                }
            }
        }
        if (cnt==1) 
        {
            u=1e9;
            for (auto g : under) u=min(u,k-g.se);
            for (auto g : over) u=min(u,g.se-k);
            cout<<u<<endl;
        }
        else
        {
            a=0;
        for (auto g : over)
        {
            u=g.fi.fi;
            v=g.fi.se;
            u=par[u];
            v=par[v];
            if (u!=v)
            {
                a+=g.se-k;
                cnt--;
                if (buc[u].size()>buc[v].size())
                {
                    for (int g : buc[v])
                    {
                        buc[u].push_back(g);
                        par[g]=u;
                    }
                    buc[v].clear();
                }
                else
                {
                    for (int g : buc[u])
                    {
                        buc[v].push_back(g);
                        par[g]=v;
                    }
                    buc[u].clear();
                }
            }
        }
        cout<<a<<endl;
        }
    }
}