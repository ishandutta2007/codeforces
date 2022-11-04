#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1000005;
const int DEG=20;
const int MOD=1000000007;
struct Edge
{
    int to,next,type;
}edge[MAXN*2];
int head[MAXN],tot;
void addedge(int u,int v,int type)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    edge[tot].type=type;
    head[u]=tot++;
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
int fa[MAXN][DEG];
int deg[MAXN],up[MAXN];
int cnt[2][MAXN];
void BFS(int root)
{
    queue<int>q;
    deg[root]=0;
    fa[root][0]=root;
    up[root]=0;
    q.push(root);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=1;i<DEG;i++)
            fa[u][i]=fa[fa[u][i-1]][i-1];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(v==fa[u][0])continue;
            deg[v]=deg[u]+1;
            fa[v][0]=u;
            up[v]=-edge[i].type;
            q.push(v);
        }
    }
}
void DFS(int u)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa[u][0])continue;
        DFS(v);
        for(int j=0;j<2;j++)
            cnt[j][u]+=cnt[j][v];
    }
}
int LCA(int u,int v)
{
    if(deg[u]>deg[v])swap(u,v);
    int hu=deg[u],hv=deg[v];
    int tu=u,tv=v;
    for(int det=hv-hu,i=0;det;det>>=1,i++)
        if(det&1)
            tv=fa[tv][i];
    if(tu==tv)return tu;
    for(int i=DEG-1;i>=0;i--)
    {
        if(fa[tu][i]==fa[tv][i])continue;
        tu=fa[tu][i];
        tv=fa[tv][i];
    }
    return fa[tu][0];
}
int fp(int a,int k)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%MOD;
        a=1LL*a*a%MOD;
        k>>=1;
    }
    return res;
}
int main()
{
    init();
    int n;
    scanf("%d",&n);
    int a,b,x;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&x);
        if(x==0)
        {
            addedge(a,b,0);
            addedge(b,a,0);
        }
        else
        {
            addedge(a,b,1);
            addedge(b,a,-1);
        }
    }
    int root=1;
    BFS(root);
    int k,la=1,now;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&now);
        if(la==now)continue;
        int tp=LCA(la,now);
        cnt[0][la]++;
        cnt[0][tp]--;
        cnt[1][now]++;
        cnt[1][tp]--;
        la=now;
    }
    DFS(root);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!up[i])continue;
        if(up[i]==-1)
            ans=(ans+fp(2,cnt[0][i])-1)%MOD;
        else
            ans=(ans+fp(2,cnt[1][i])-1)%MOD;
    }
    ans=(ans+MOD)%MOD;
    printf("%d\n",ans);
    return 0;
}