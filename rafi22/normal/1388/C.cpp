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

vector <int> G[200007];
int sum[200007];
int tab[200007];
int val[200007];
int sz[200007];
bool odw[200007];
bool ok=1;

void dfs(int v,int o)
{
    odw[v]=1;
    sum[v]=tab[v];
    int ile=0;
    for(int u:G[v])
    {
        if(!odw[u])
        {
            dfs(u,v);
            sum[v]+=sum[u];
            ile+=sz[u];
        }
    }
    sz[v]=(sum[v]+val[v])/2;
    if(abs(val[v])>sum[v]) ok=0;
    if(abs(val[v])%2!=sum[v]%2) ok=0;
    if(ile>sz[v]) ok=0;
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
        int n,m,a,b;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=1;i<=n;i++) cin>>val[i];
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        val[0]=inf;
        dfs(1,0);
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        ok=1;
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            odw[i]=0;
        }
    }
    return 0;
}