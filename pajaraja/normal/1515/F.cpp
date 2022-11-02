#include <bits/stdc++.h>
#define MAXN 300007
using namespace std;
int n,m,dsu[MAXN];
long long x,a[MAXN],gas[MAXN];
bool vi[MAXN],vc[MAXN];
vector<int> gp[MAXN],indp[MAXN],g[MAXN],ind[MAXN];
void dfstree(int s)
{
    vi[s]=true;
    for(int i=0;i<gp[s].size();i++) if(!vi[gp[s][i]])
    {
        g[s].push_back(gp[s][i]);
        g[gp[s][i]].push_back(s);
        ind[s].push_back(indp[s][i]);
        ind[gp[s][i]].push_back(indp[s][i]);
        dfstree(gp[s][i]);
    }
}
inline int root(int u)
{
    while(dsu[u]!=u)
    {
        dsu[u]=dsu[dsu[u]];
        u=dsu[u];
    }
    return u;
}
inline bool moze(int u,int v) {return gas[root(u)]+gas[root(v)]>=x;}
inline void connect(int u,int v)
{
    u=root(u); v=root(v);
    if(gas[u]>gas[v])
    {
        dsu[v]=u;
        gas[u]+=gas[v]-x;
    }
    else
    {
        dsu[u]=v;
        gas[v]+=gas[u]-x;
    }
}
int c,sajz;
inline int dfssz(int s,int f)
{
    int sz=1;
    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f && !vc[g[s][i]]) sz+=dfssz(g[s][i],s);
    return sz;
}
inline int dfsc(int s,int f)
{
    int sz=1;
    bool cent=true;
    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f && !vc[g[s][i]])
    {
        int zzz=dfsc(g[s][i],s);
        if(zzz>sajz/2) cent=false;
        sz+=zzz;
    }
    if(sajz-sz>sajz/2) cent=false;
    if(cent) c=s;
    return sz;
}
inline long long dfssum(int s,int f)
{
    long long sz=gas[root(s)];
    for(int i=0;i<g[s].size();i++) if(g[s][i]!=f && !vc[g[s][i]]) sz+=dfssum(g[s][i],s);
    return sz;
}
inline void centrodecomp(int s,int sz)
{
    sajz=sz;
    dfsc(s,s);
    int cr=c;
    vc[cr]=true;
    int szc=g[cr].size();
    for(int i=0;i<2*szc;i++) if(!vc[g[cr][i%szc]])
    {
        int y=g[cr][i%szc];
        int segamega = dfssz(y,y);
        if(dfssum(y,y)+gas[root(cr)]>=segamega*x)
        {
            if(moze(cr,y))
            {
                connect(cr,y);
                printf("%d\n",ind[cr][i%szc]);
                if(segamega!=1) centrodecomp(y,segamega);
                else vc[y]=true;
            }
            else
            {
                if(segamega!=1) centrodecomp(y,segamega);
                else vc[y]=true;
                connect(cr,y);
                printf("%d\n",ind[cr][i%szc]);
            }
        }
    }
}
int main()
{
    scanf("%d%d%lld",&n,&m,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    long long sum=0;
    for(int i=1;i<=n;i++) sum+=a[i];
    if(sum<(n-1)*x) {printf("NO"); return 0;}
    printf("YES\n");
    for(int i=1;i<=m;i++)
    {
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        gp[t1].push_back(t2);
        gp[t2].push_back(t1);
        indp[t1].push_back(i);
        indp[t2].push_back(i);
    }
    dfstree(1);
    iota(dsu,dsu+n+1,0);
    for(int i=1;i<=n;i++) gas[i]=a[i];
    centrodecomp(1,n);
}