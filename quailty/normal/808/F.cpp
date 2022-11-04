#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
const int MAXM=100005;
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
int p[MAXN],c[MAXN],v[MAXN],np[MAXM];
void build()
{
    for(int i=2;i<MAXM;i++)if(!np[i])
        for(int j=i*2;j<MAXM;j+=i)np[j]=1;
}
int main()
{
    build();
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&p[i],&c[i],&v[i]);
    int l=1,r=n+1;
    while(l<r)
    {
        int m=(l+r)/2,isok=0,sum=0;
        init();
        for(int i=1;i<=n;i++)
        {
            if(c[i]==1 || v[i]>m)continue;
            sum+=p[i];
            if(c[i]&1)addedge(0,i,p[i]);
            else addedge(i,n+1,p[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i]==1 || (~c[i]&1) || v[i]>m)continue;
            for(int j=1;j<=n;j++)
            {
                if((c[j]&1) || v[j]>m || np[c[i]+c[j]])continue;
                addedge(i,j,INF);
            }
        }
        isok|=(sum-sap(0,n+1,n+2)>=k);
        init();
        sum=0;
        for(int i=1;i<=n;i++)
        {
            if(v[i]>m)continue;
            if(c[i]==1)sum=max(sum,p[i]);
            if(!np[c[i]+1])continue;
            sum+=p[i];
            if(c[i]&1)addedge(0,i,p[i]);
            else addedge(i,n+1,p[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i]==1 || (~c[i]&1) || v[i]>m)continue;
            for(int j=1;j<=n;j++)
            {
                if((c[j]&1) || v[j]>m || np[c[i]+c[j]])continue;
                addedge(i,j,INF);
            }
        }
        isok|=(sum-sap(0,n+1,n+2)>=k);
        if(isok)r=m;
        else l=m+1;
    }
    return 0*printf("%d",(l>n ? -1 : l));
}