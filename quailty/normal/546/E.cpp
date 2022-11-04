#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int MAXM=3005;
const int INF=0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];
int tol,head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to=v;
    edge[tol].cap=w;
    edge[tol].next=head[u];
    edge[tol].flow=0;
    head[u]=tol++;
    edge[tol].to=u;
    edge[tol].cap=rw;
    edge[tol].next=head[v];
    edge[tol].flow=0;
    head[v]=tol++;
}
int sap(int st,int ed,int N)
{
    memset(gap,0,sizeof(gap));
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(head));
    int u=st;
    pre[u]=-1;
    gap[0]=N;
    int ans=0;
    while(dep[st]<N)
    {
        if(u==ed)
        {
            int Min=INF;
            for(int i=pre[u];i!=-1;i=pre[edge[i^1].to])
                if(Min>edge[i].cap-edge[i].flow)
                    Min=edge[i].cap-edge[i].flow;
            for(int i=pre[u];i!=-1;i=pre[edge[i^1].to])
            {
                edge[i].flow+=Min;
                edge[i^1].flow-=Min;
            }
            u=st;
            ans+=Min;
            continue;
        }
        bool flag=0;
        int v;
        for(int i=cur[u];i!=-1;i=edge[i].next)
        {
            v=edge[i].to;
            if(edge[i].cap-edge[i].flow && dep[v]+1==dep[u])
            {
                flag=1;
                cur[u]=pre[v]=i;
                break;
            }
        }
        if(flag)
        {
            u=v;
            continue;
        }
        int Min=N;
        for(int i=head[u];i!=-1;i=edge[i].next)
            if(edge[i].cap-edge[i].flow && dep[edge[i].to]<Min)
            {
                Min=dep[edge[i].to];
                cur[u]=i;
            }
        gap[dep[u]]--;
        if(!gap[dep[u]])return ans;
        dep[u]=Min+1;
        gap[dep[u]]++;
        if(u!=st)u=edge[pre[u]^1].to;
    }
    return ans;
}
int f[105][105];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b,ta=0,tb=0;
    init();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        addedge(0,i,a);
        ta+=a;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b);
        addedge(i+n,2*n+1,b);
        tb+=b;
    }
    for(int i=1;i<=n;i++)
    {
        addedge(i,i+n,INF);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        addedge(a,b+n,INF);
        addedge(b,a+n,INF);
    }
    int mf=sap(0,2*n+1,2*n+2);
    int u,v;
    if(mf==ta && mf==tb)
    {
        printf("YES\n");
        //printf("%d\n",tol);
        for(int i=0;i<tol;i+=2)
        {
            v=edge[i].to;
            u=edge[i^1].to;
            if(u>=1 && u<=n)
            {
                f[u][v-n]=edge[i].flow;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%s%d",(j==1 ? "" : " "),f[i][j]);
            }
            printf("\n");
        }
    }
    else printf("NO\n");
    return 0;
}