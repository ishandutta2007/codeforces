#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=500005;
const int INF=0x3f3f3f3f;
#define ft first
#define sd second
vector<pair<int,int> >e[MAXN];
int p[MAXN],cnt[MAXN],mx[MAXN],usd[MAXN];
void dfs1(int u,int la)
{
    cnt[u]=1,mx[u]=0;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(v==la || usd[v])continue;
        dfs1(v,u);
        cnt[u]+=cnt[v];
    }
}
void dfs2(int u,int la,int rt,int &res)
{
    if(u!=rt)mx[u]=max(mx[u],cnt[rt]-cnt[u]);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(v==la || usd[v])continue;
        dfs2(v,u,rt,res);
        mx[u]=max(mx[u],cnt[v]);
    }
    if(mx[u]<=cnt[rt]/2)res=u;
}
int getRoot(int u)
{
    dfs1(u,0);
    int rt=u;
    dfs2(u,0,u,rt);
    return rt;
}
int res[MAXN],val[1<<22];
void dfs3(int u,int la,int up,int dep,int mk)
{
    int tmp=dep+val[mk];
    for(int i=0;i<22;i++)
        tmp=max(tmp,dep+val[mk^(1<<i)]);
    res[up]=max(res[up],tmp);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(v==la || usd[v])continue;
        dfs3(v,u,(v==p[u] ? v : up),dep+1,mk^(1<<e[u][i].sd));
    }
}
stack<int>stk;
void dfs4(int u,int la,int dep,int mk)
{
    val[mk]=max(val[mk],dep);
    stk.push(mk);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(v==la || usd[v])continue;
        dfs4(v,u,dep+1,mk^(1<<e[u][i].sd));
    }
}
void solve(int u)
{
    usd[u=getRoot(u)]=1;
    while(!stk.empty())
    {
        val[stk.top()]=-INF;
        stk.pop();
    }
    val[0]=0;
    stk.push(0);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(usd[v] || v==p[u])continue;
        dfs3(v,u,u,1,1<<e[u][i].sd);
        dfs4(v,u,1,1<<e[u][i].sd);
    }
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(usd[v] || v!=p[u])continue;
        dfs3(v,u,v,1,1<<e[u][i].sd);
    }
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(usd[v])continue;
        solve(v);
    }
}
void dfs5(int u,int la)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(v==la)continue;
        dfs5(v,u);
        res[u]=max(res[u],res[v]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        char ty[5];
        scanf("%d%s",&p[i],ty);
        e[p[i]].push_back(make_pair(i,*ty-'a'));
        e[i].push_back(make_pair(p[i],*ty-'a'));
    }
    for(int i=0;i<(1<<22);i++)val[i]=-INF;
    solve(1);
    dfs5(1,0);
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}