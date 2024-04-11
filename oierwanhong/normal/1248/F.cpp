#include<bits/stdc++.h>
#define N 1000011
std::vector<int>g[N];
int t,n,m,dfn[N],low[N],scc[N], scnt=0;
bool ins[N];int s[N],cur=0,top=0;
void tarjan(int u)
{
    dfn[u]=low[u]=++cur;
    s[++top]=u,ins[u]=1;
    for(int v:g[u])
        if(!dfn[v])tarjan(v),low[u]=std::min(low[u],low[v]);
        else if(ins[v])low[u]=std::min(low[u],low[v]);
    if(low[u]==dfn[u])
    {
        ++scnt;
        while(s[top]!=u)scc[s[top]]=scnt,ins[s[top--]]=0;
        scc[s[top]]=scnt,ins[s[top--]]=0;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scnt=top=cur=0;scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)dfn[i]=low[i]=scc[i]=0,g[i].clear();
        for(int i=1;i<=m;++i)
        {
            int u,v;scanf("%d%d",&u,&v);g[u].push_back(v);
        }
        for(int i=1;i<=n;++i)
            if(!dfn[i])tarjan(i);
        int c=0;
        for(int i=1;i<=n;++i)c+=scc[i]==1;
        if(c==n){puts("No");continue;}
        printf("Yes\n%d %d\n",c,n-c);
        for(int i=1;i<=n;++i)
            if(scc[i]==1)printf("%d ",i);
        puts("");
        for(int i=1;i<=n;++i)
            if(scc[i]!=1)printf("%d ",i);
        puts("");
    }
}