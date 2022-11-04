#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN];
int in[MAXN],out[MAXN],ts;
int up[MAXN][19],dep[MAXN];
int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    for(int d=dep[u]-dep[v],i=0;i<19;i++)
        if(d>>i&1)u=up[u][i];
    if(u==v)return u;
    for(int i=18;i>=0;i--)
        if(up[u][i]!=up[v][i])
            u=up[u][i],v=up[v][i];
    return up[u][0];
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1,up[u][0]=fa;
    for(int i=1;i<19;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    in[u]=++ts;
    for(auto v : e[u])
        if(v!=fa)dfs(v,u);
    out[u]=ts;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int k;
        scanf("%d",&k);
        vector<int> p(k);
        for(int i=0;i<k;i++)
            scanf("%d",&p[i]);
        sort(p.begin(),p.end(),[](int u,int v){
            return in[u]<in[v];
        });
        p.erase(unique(p.begin(),p.end()),p.end());
        {
            vector<int> pp=p;
            for(size_t i=0;i+1<p.size();i++)
                pp.push_back(lca(p[i],p[i+1]));
            p.swap(pp);
        }
        sort(p.begin(),p.end(),[](int u,int v){
            return in[u]<in[v];
        });
        p.erase(unique(p.begin(),p.end()),p.end());
        vector<int> pr;
        if(p.size()>1u)pr.push_back(p[1]);
        for(size_t i=2;i<p.size();i++)
            if(in[p[i]]<in[p[i-1]] || in[p[i]]>out[p[i-1]])
                pr.push_back(p[i]);
        if(pr.size()>2u)printf("NO\n");
        else if(pr.size()<2u)printf("YES\n");
        else printf("%s\n",lca(pr[0],pr[1])==p[0] ? "YES" : "NO");
    }
    return 0;
}