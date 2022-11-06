#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=500005;
struct Edge
{
    int to,nxt;
}edge[MAXN<<1];
int head[MAXN],tot;
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}
const int root=1;
int res;
priority_queue<pair<int,int> >q;
void work()
{
    while(!q.empty())
    {
        int now=q.top().first;
        int cnt=0;
        while(!q.empty() && q.top().first==now)
        {
            cnt+=q.top().second;
            q.pop();
        }
        res=max(res,-(now-1));
        if(cnt>1)q.push(make_pair(now-1,cnt-1));
    }
}
void dfs(int u,int fa,int dep)
{
    bool leaf=1;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(v==fa)continue;
        leaf=0;
        dfs(v,u,dep+1);
        if(u==root && !q.empty())
        {
            work();
            while(!q.empty())q.pop();
        }
    }
    if(leaf)q.push(make_pair(-dep,1));
}
int main()
{
    int n;
    scanf("%d",&n);
    init();
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    res=0;
    dfs(root,0,0);
    printf("%d\n",res-1);
    return 0;
}