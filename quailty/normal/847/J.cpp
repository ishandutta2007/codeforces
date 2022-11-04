#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10010
#define M 40010
int n,m;
int head[M],last[M],flow[M],p[N],e;
int d[N];
int st,ed;
struct edge
{
    int x,y;
} E[N];
void add(int x,int y,int f)
{
    head[++e]=y;
    flow[e]=f;
    last[e]=p[x];
    p[x]=e;
    head[++e]=x;
    flow[e]=0;
    last[e]=p[y];
    p[y]=e;
}
int q[N];
bool bfs()
{
    memset(d,0,sizeof(d));
    int l=0,r=0;
    d[st]=1;
    q[r++]=st;
    while(l!=r)
    {
        int x=q[l++];
        for(int j=p[x];j;j=last[j])
            if(!d[head[j]] && flow[j]>0)
            {
                d[head[j]]=d[x]+1;
                if(head[j]==ed) return true;
                q[r++]=head[j];
            }
    }
    return false;
}
int dinic(int x,int f)
{
    if(x==ed) return f;
    int tem=f,k;
    for(int j=p[x];tem>0 && j;j=last[j])
        if(d[head[j]]==d[x]+1 && flow[j]>0)
        {
            k=dinic(head[j],min(tem,flow[j]));
            if(!k) d[head[j]]=0;
            tem-=k;
            flow[j]-=k;
            flow[j^1]+=k;
        }
    return f-tem;
}
bool ok(int mid)
{
    e=1;
    memset(p,0,sizeof(p));
    st=0;
    ed=n+m+1;
    for(int i=1;i<=m;++i) add(st,i,1);
    for(int i=1;i<=m;++i)
    {
        add(i,E[i].x+m,1);
        add(i,E[i].y+m,1);
    }
    for(int i=1;i<=n;++i)
        add(i+m,ed,mid);
    int i,ans=0;
    while(bfs())
        while(i=dinic(st,1000000000)) ans+=i;
    return ans==m;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&E[i].x,&E[i].y);
    }
    if(m==0) return 0*puts("0");
    int l=1,r=n;
    while(l<r)
    {
        int mid=l+r>>1;
        if(ok(mid)) r=mid;
        else l=mid+1;
    }
    ok(l);
    printf("%d\n",l);
    for(int i=1;i<=m;++i)
    {
        for(int j=p[i];j;j=last[j])
        {
            if(head[j]==st) continue;
            if(flow[j]==0)
            {
                printf("%d ",head[j]-m);
                if(head[j]-m==E[i].x) printf("%d\n",E[i].y);
                else printf("%d\n",E[i].x);
            }
        }
    }
    return 0;
}