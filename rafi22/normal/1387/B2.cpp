#include <bits/stdc++.h>

using namespace std;

vector <int> G[100007];
bool odw[100007];
int ans[100007];
int pre[100007];
int post[100007];
int skoki[100007][25];
int lista[100007];
int g[100007];
int c=1,it=0;
long long res=0;

void dfs(int v,int o,int x)
{
    lista[it]=v;
    it++;
    pre[v]=c++;
    odw[v]=1;
    g[v]=x;
    if(v!=1)
    {
        skoki[v][0]=o;
        for(int i=1;i<=20;i++)
        {
            skoki[v][i]=skoki[skoki[v][i-1]][i-1];
        }
    }
    else
    {
        for(int i=0;i<=20;i++) skoki[1][i]=1;
    }
    for(auto u:G[v])
    {
        if(!odw[u]) dfs(u,v,x+1);
    }
    post[v]=c++;
}

bool child(int a,int b)
{
    if(pre[b]>=pre[a]&&post[b]<=post[a]) return 1;
    return 0;
}

int lca(int a,int b)
{
    if(child(b,a)) swap(a,b);
    int it=20,p=b;
    while(true)
    {
        bool x=0;
        for(; it>=0; it--)
        {
            if(!child(skoki[p][it],a))
            {
                x=1;
                p=skoki[p][it];
                break;
            }
        }
        if(!x) return skoki[p][0];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,0,0);
    for(int i=0;i<n;i++)
    {
        ans[lista[i]]=lista[(i+n/2)%n];
    }
    for(int i=1;i<=n;i++)
    {
        int l=lca(i,ans[i]),d;
        d=g[i]+g[ans[i]]-2*g[l];
        res+=d;
    }
    cout<<res<<endl;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";


    return 0;
}