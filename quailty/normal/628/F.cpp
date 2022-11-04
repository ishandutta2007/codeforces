#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=50005;
const int MAXM=500005;
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
pair<int,int>p[10005];
int main()
{
    int n,b,q;
    scanf("%d%d%d",&n,&b,&q);
    for(int i=1;i<=q;i++)
        scanf("%d%d",&p[i].first,&p[i].second);
    p[++q]=make_pair(b,n);
    sort(p,p+q+1);
    q=unique(p,p+q+1)-p-1;
    for(int i=q;i>=1;i--)
        p[i]=make_pair(p[i].first-p[i-1].first,p[i].second-p[i-1].second);
    for(int i=1;i<=q;i++)
        if(p[i].first==0 || p[i].second<0 || p[i].second>p[i].first)
            return 0*printf("unfair");
    init();
    for(int i=1;i<=q;i++)
        addedge(0,i,p[i].second);
    int now=0;
    for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=p[i].first;j++)
            addedge(i,q+now+j,1);
        now+=p[i].first;
    }
    for(int i=1;i<=b;i++)
        addedge(q+i,q+b+(i-1)%5+1,1);
    for(int i=1;i<=5;i++)
        addedge(q+b+i,q+b+6,n/5);
    if(sap(0,q+b+6,q+b+7)==n)printf("fair");
    else printf("unfair");
    return 0;
}