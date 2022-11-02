#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=2*1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int N=207;

struct edge
{
    int u,v,a,b;
};
bool cmp(edge L,edge R)
{
    return L.a<R.a;
}

int d[N],o[N],c[N];
bool odw[N];
set<pair<int,int>>G[N];
int r[N];

int Find(int v)
{
    if(r[v]==v) return v;
    return r[v]=Find(r[v]);
}
void Union(int u,int v)
{
    r[u]=v;
}

void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(u.st==o[v]) continue;
        d[u.st]=d[v]+1;
        o[u.st]=v;
        c[u.st]=u.nd;
        dfs(u.st);
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
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        vector<edge>V;
        for(int i=0;i<m;i++)
        {
            int u,v,a,b;
            cin>>u>>v>>a>>b;
            V.pb({u,v,a,b});
        }
        sort(all(V),cmp);
        int ans=inf;
        int cnt=0;
        multiset<int>S;
        for(int i=1;i<=n;i++) r[i]=i;
        for(auto e:V)
        {
            if(Find(e.u)!=Find(e.v))
            {
                Union(Find(e.u),Find(e.v));
                S.insert(e.b);
                G[e.u].insert({e.v,e.b});
                G[e.v].insert({e.u,e.b});
                cnt++;
            }
            else
            {
                int best=-1,U,V,u=e.u,v=e.v;
           //     cout<<u<<" "<<v<<endl;
                while(u!=v)
                {
                    if(d[u]<d[v]) swap(u,v);
                    if(c[u]>best)
                    {
                        best=c[u];
                        U=u;
                        V=o[u];
                    }
                    u=o[u];
                }
                if(best>e.b)
                {
                    S.erase(S.find(best));
                    G[U].erase({V,best});
                    G[V].erase({U,best});
                    S.insert(e.b);
                    G[e.u].insert({e.v,e.b});
                    G[e.v].insert({e.u,e.b});
                }
            }
            memset(odw,0,sizeof odw);
            memset(d,0,sizeof d);
            memset(o,0,sizeof o);
            for(int i=1;i<=n;i++) if(!odw[i]) dfs(i);
            if(cnt==n-1) ans=min(ans,e.a*x+(*--S.end())*y);
        }
        if(ans==inf) cout<<-1;
        else cout<<ans;
    }

    return 0;
}