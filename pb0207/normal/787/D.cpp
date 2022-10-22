#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
#include<list>
#include<set>
#include<map>
using namespace std;
#define ll long long
const int N=1e5+10,M=1e6+10,inf=2147483647;
const ll INF=1e17+10,mod=1e9+7;
struct is
{
    int v,next;
    ll w;
}edge[M*4];
int head[N*5],edg,vis[M];
void init()
{
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    edg=0;
}
void add(int u,int v,ll w)
{
    edg++;
    edge[edg].v=v;
    edge[edg].w=w;
    edge[edg].next=head[u];
    head[u]=edg;
}
struct SGT
{
    int ls[N*5][2],rs[N*5][2],root[2];
    int tot;
    void build(int l,int r,int &pos,int type)
    {
        pos=tot++;
        if(l==r)
        {
            if(type)
                add(l,pos,0);
            else
                add(pos,l,0);
            return;
        }
        int mid=(l+r)>>1;
        build(l,mid,ls[pos][type],type);
        build(mid+1,r,rs[pos][type],type);
        if(type)
            add(ls[pos][type],pos,0),add(rs[pos][type],pos,0);
        else
            add(pos,ls[pos][type],0),add(pos,rs[pos][type],0);
    }
    void up(int v,int L,int R,ll c,int l,int r,int pos)
    {
        if(L<=l&&r<=R)
        {
            //cout<<"add"<<v<<" "<<pos<<endl;
            add(pos,v,c);
            return;
        }
        int mid=(l+r)>>1;
        if(L<=mid)
            up(v,L,R,c,l,mid,ls[pos][1]);
        if(R>mid)
            up(v,L,R,c,mid+1,r,rs[pos][1]);
    }
    void down(int v,int L,int R,ll c,int l,int r,int pos)
    {
        if(L<=l&&r<=R)
        {
            //cout<<"add"<<v<<" "<<pos<<endl;
            add(v,pos,c);
            return;
        }
        int mid=(l+r)>>1;
        if(L<=mid)
            down(v,L,R,c,l,mid,ls[pos][0]);
        if(R>mid)
            down(v,L,R,c,mid+1,r,rs[pos][0]);
    }
};
SGT tree;
struct mmp
{
    int s;
    ll dis;
    mmp(){}
    mmp(int ss,ll d){s=ss,dis=d;}
    bool operator <(const  mmp &b)const
    {
        return dis>b.dis;
    }
};
ll ans[N*5];
priority_queue<mmp>q;
void dij(int s)
{
    ans[s]=0;
    q.push(mmp(s,0LL));
    while(!q.empty())
    {
        mmp now = q.top();
        q.pop();
        if(vis[now.s])continue;
        vis[now.s]=1;
        for(int i = head[now.s]; i !=-1; i = edge[i].next)
        {
            int v=edge[i].v;
            ll w=edge[i].w;
            if(ans[v] > ans[now.s] + w)
            {
                q.push(mmp(v,ans[now.s]+w));
                ans[v]=ans[now.s]+w;
            }
        }
    }
}
int main()
{
    init();
    int n,q,s;
    scanf("%d%d%d",&n,&q,&s);
    for(int i=1;i<=n*5;i++)
        ans[i]=INF;
    tree.tot=n+1;
    tree.build(1,n,tree.root[1],1);
    tree.build(1,n,tree.root[0],0);
    for(int i=1;i<=q;i++)
    {
        int t,v,u,l,r;
        ll w;
        scanf("%d%d",&t,&v);
        if(t==1)
            scanf("%d%lld",&u,&w),add(v,u,w);
        else if(t==2)
            scanf("%d%d%lld",&l,&r,&w),tree.down(v,l,r,w,1,n,tree.root[0]);
        else
            scanf("%d%d%lld",&l,&r,&w),tree.up(v,l,r,w,1,n,tree.root[1]);
    }
    dij(s);
    for(int i=1;i<=n;i++)
    {
        if(ans[i]>=INF)printf("-1 ");
        else printf("%lld ",ans[i]);
    }
    printf("\n");
    return 0;
}