#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1005;
const int MAXM=100005;
const int INF=0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];
int tot;
int head[MAXN];
int gap[MAXN],dep[MAXN],pre[MAXN],cur[MAXN];
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0)
{
    edge[tot].to=v;
    edge[tot].cap=w;
    edge[tot].next=head[u];
    edge[tot].flow=0;
    head[u]=tot++;
    edge[tot].to=u;
    edge[tot].cap=rw;
    edge[tot].next=head[v];
    edge[tot].flow=0;
    head[v]=tot++;
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
int cnt,a[MAXN],now[MAXN];
vector<int>e[MAXN];
bool vis[MAXN];
queue<int>ans[MAXN];
bool is_prime(int k)
{
    if(k==1)return 0;
    for(int i=2;i<=(int)sqrt(k);i++)
        if(k%i==0)return 0;
    return 1;
}
void dfs(int u)
{
    vis[u]=1;
    ans[cnt].push(u);
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(!vis[v])dfs(v);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    init();
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1)addedge(0,i,2);
        else addedge(i,n+1,2);
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(is_prime(a[i]+a[j]))
            {
                if(a[i]&1)addedge(i,j,1);
                else addedge(j,i,1);
            }
    if(sap(0,n+1,n+2)!=n)printf("Impossible");
    else
    {
        //printf("ok\n");
        for(int i=0;i<tot;i+=2)
            if(edge[i].flow==edge[i].cap)
                if(edge[i].to>=1 && edge[i].to<=n && edge[i^1].to>=1 && edge[i^1].to<=n)
                {
                    e[edge[i].to].push_back(edge[i^1].to);
                    e[edge[i^1].to].push_back(edge[i].to);
                }
        for(int i=1;i<=n;i++)
            if(!vis[i])
            {
                cnt++;
                dfs(i);
            }
        printf("%d\n",cnt);
        for(int i=1;i<=cnt;i++)
        {
            printf("%d",ans[i].size());
            while(!ans[i].empty())
            {
                printf(" %d",ans[i].front());
                ans[i].pop();
            }
            printf("\n");
        }
    }
    return 0;
}