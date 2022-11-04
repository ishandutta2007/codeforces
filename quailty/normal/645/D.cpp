#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=100005;
const int MAXM=100005;
int u[MAXM],v[MAXM];
struct edge
{
    int to,nxt;
}edge[MAXM];
int head[MAXN],in[MAXN],tot;
void init()
{
    memset(head,-1,sizeof(head));
    memset(in,0,sizeof(in));
    tot=0;
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot++;
    in[v]++;
}
bool check(int n,int m)
{
    init();
    for(int i=1;i<=m;i++)
        addedge(u[i],v[i]);
    queue<int>q;
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++)
        if(!in[i])q.push(i);
    while(!q.empty())
    {
        if((int)q.size()>1)return 0;
        int u=q.front();
        q.pop();
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].to;
            if(--in[v]==0)q.push(v);
        }
    }
    return 1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&u[i],&v[i]);
    int l=1,r=m+1;
    while(l<r)
    {
        int t=(l+r)>>1;
        if(check(n,t))r=t;
        else l=t+1;
    }
    printf("%d\n",r>m ? -1 : r);
    return 0;
}