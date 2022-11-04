#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=400005;
vector<int>e[MAXN];
int cnt[MAXN],mx[MAXN];
void dfs1(int u,int la)
{
    cnt[u]=1,mx[u]=0;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==la)continue;
        dfs1(v,u);
        cnt[u]+=cnt[v];
    }
}
void dfs2(int u,int la,int rt,vector<int>&res)
{
    if(u!=rt)mx[u]=max(mx[u],cnt[rt]-cnt[u]);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==la)continue;
        dfs2(v,u,rt,res);
        mx[u]=max(mx[u],cnt[v]);
    }
    if(mx[u]<=cnt[rt]/2)res.push_back(u);
}
int res[MAXN];
void dfs3(int u,int la,int n,int c)
{
    res[u]=(n-c-cnt[u]<=n/2);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==la)continue;
        dfs3(v,u,n,c);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int>rt;
    dfs1(1,0);
    dfs2(1,0,1,rt);
    if((int)rt.size()>1)
    {
        for(int i=1;i<=n;i++)
            printf("1 ");
        return 0;
    }
    res[rt[0]]=1;
    dfs1(rt[0],0);
    int mx[2]={0,0};
    for(int i=0;i<(int)e[rt[0]].size();i++)
    {
        int t=cnt[e[rt[0]][i]];
        if(t>mx[0])
        {
            mx[1]=mx[0];
            mx[0]=t;
        }
        else if(t>mx[1])
            mx[1]=t;
    }
    for(int i=0;i<(int)e[rt[0]].size();i++)
        dfs3(e[rt[0]][i],rt[0],n,mx[cnt[e[rt[0]][i]]==mx[0]]);
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}