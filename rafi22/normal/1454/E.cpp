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

const bool multi=1;

vector<int>G[200007];
int o[200007];
bool odw[200007],odw1[200007];
bool cycle[200007];
bool f;
int c;
void dfsC(int v)
{
    odw[v]=1;
    for(auto u:G[v])
    {
        if(!odw[u])
        {
            o[u]=v;
            dfsC(u);
        }
        else if(u!=o[v]&&!f)
        {
            int p=v;
            while(true)
            {
                cycle[p]=1;
                if(p==u) break;
                p=o[p];
            }
            f=1;
        }
    }
}
void dfs(int v)
{
    odw1[v]=1;
    c++;
    for(auto u:G[v]) if(!odw1[u]&&!cycle[u]) dfs(u);
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
        int n,a,b,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfsC(1);
        for(int i=1;i<=n;i++)
        {
            if(cycle[i])
            {
                c=0;
                for(auto u:G[i]) if(!cycle[u]) dfs(u);
                ans+=(c+1)*(c+(n-c-1)*2);
            }
        }
        cout<<ans/2<<endl;
        for(int i=0;i<=n;i++)
        {
            G[i].clear();
            odw[i]=0;
            odw1[i]=0;
            cycle[i]=0;
            f=0;
        }
    }
    return 0;
}