#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int,int> pii;
const int maxn=100005;
vector<pii> g[maxn];
pii pre[maxn];
int dist[maxn],dp[maxn],n,m;
int sta[maxn],cnt,from[maxn],to[maxn];
bool use[maxn];
int que[maxn];
void bfs(int x)
{
    memset(dist,-1,sizeof(dist));
    dist[x]=0;
    int front=0,rear=1;
    que[0]=x;
    while(front!=rear)
    {
        x=que[front++];
        for(int i=0;i<g[x].size();i++)
            if(dist[g[x][i].ff]<0)
            {
                dist[g[x][i].ff]=dist[x]+1;
                dp[g[x][i].ff]=dp[x]+(sta[g[x][i].ss]==0);
                pre[g[x][i].ff]=make_pair(x,g[x][i].ss);
                que[rear++]=g[x][i].ff;
            }
            else if(dp[g[x][i].ff]>dp[x]+(sta[g[x][i].ss]==0)&&dist[g[x][i].ff]==dist[x]+1)
            {
                dp[g[x][i].ff]=dp[x]+(sta[g[x][i].ss]==0);
                pre[g[x][i].ff]=make_pair(x,g[x][i].ss);
            }
    }
}
void path()
{
    int x=n;
    while(x!=1)
    {
        use[pre[x].ss]=true;
        x=pre[x].ff;
    }
}
void out()
{
    printf("%d\n",dp[n]+dp[n]+m-dist[n]-cnt);
    for(int i=1;i<=m;i++)
        if(sta[i]==1&&!use[i])
            printf("%d %d 0\n",from[i],to[i]);
        else if(sta[i]==0&&use[i])
            printf("%d %d 1\n",from[i],to[i]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y,z;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        sta[i]=z;
        from[i]=x;
        to[i]=y;
        g[x].push_back(make_pair(y,i));
        g[y].push_back(make_pair(x,i));
        if(z==0)++cnt;
    }
    bfs(1);
    path();
    out();
    return 0;
}