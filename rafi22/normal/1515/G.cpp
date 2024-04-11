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

vector<pair<int,int>>G[200007],RG[200007];
vector<int>stos;
bool odw[200007];
int SCC_GCD[200007];
int scc[200007],c=0;
int dis[200007];

void dfs(int v)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(odw[u.st]) continue;
        dfs(u.st);
    }
    stos.pb(v);
}

void dfs1(int v,int d)
{
    scc[v]=c;
    dis[v]=d;
    for(auto u:RG[v])
    {
        if(scc[u.st]==0) dfs1(u.st,d+u.nd);
        else if(scc[u.st]==c)
        {
            if(SCC_GCD[c]==-1) SCC_GCD[c]=abs(dis[v]-dis[u.st]+u.nd);
            else SCC_GCD[c]=__gcd(SCC_GCD[c],abs(dis[v]-dis[u.st]+u.nd));
        }
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
        int n,m,a,b,d;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>d;
            G[a].pb({b,d});
            RG[b].pb({a,d});
        }
        for(int i=1;i<=n;i++) if(!odw[i]) dfs(i);
        reverse(stos.begin(),stos.end());
        for(auto i:stos)
        {
            if(!scc[i])
            {
                c++;
                SCC_GCD[c]=-1;
                dfs1(i,0);
            }
        }
       // for(int i=1;i<=c;i++) cout<<SCC_GCD[i]<<endl;
        int q=0;
        cin>>q;
        while(q--)
        {
            int v,s,t;
            cin>>v>>s>>t;
            if(s==0||(SCC_GCD[scc[v]]!=-1&&s%__gcd(t,SCC_GCD[scc[v]])==0)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

    }

    return 0;
}