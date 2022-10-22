//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef int un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<58;
/**********/
#define MAXN 200011
struct edge
{
    ll v,nxt;
}e[MAXN];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v;
    e[cnt].nxt=last[u],last[u]=cnt;
}

ll fa[MAXN],size[MAXN],mson[MAXN],dep[MAXN];
void dfs1(ll u,ll now_dep=1)
{
    dep[u]=now_dep,size[u]=1;
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        dfs1(v,now_dep+1);
        if(size[v]>size[mson[u]])mson[u]=v;
        size[u]+=size[v];
    }
}
ll top[MAXN],dfn[MAXN],ed[MAXN],cur=0;
void dfs2(ll u,ll now_top)
{
    top[u]=now_top,dfn[u]=++cur;
    //printf("top[%lld] = %lld\n",u,top[u]);
    if(mson[u])dfs2(mson[u],now_top);
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==mson[u])continue;
        dfs2(v,v);
    }
    ed[u]=cur;
}
ll n;
struct node
    {
        ll sum,maxsuf,clear;
        node(){sum=clear=0,maxsuf=-1;}
        node operator +(node t)
        {
            node res;
            res.sum=sum+t.sum;
            res.maxsuf=max(maxsuf+t.sum,t.maxsuf);
            return res;
        }
    }t[MAXN<<2|1];
struct Segment_Tree
{
    
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    void build(un l=1,un r=n,un num=1)
    {
        if(l==r)rt.sum=rt.maxsuf=-1;
        else
        {
            un mid=(l+r)>>1;
            build(l,mid,num<<1),build(mid+1,r,num<<1|1);
            rt=tl+tr;
        }
    }
    void pushdown(un l,un r,un num)
    {
        if(!rt.clear)return;
        un mid=(l+r)>>1;
        tl.sum=-(mid-l+1),tl.maxsuf=-1, tl.clear=1;
        tr.sum=-(r-mid),  tr.maxsuf=-1, tr.clear=1;
        rt.clear=0;
    }
    void modify(un pos,ll k,un l=1,un r=n,un num=1)
    {
    	//if(l==3&&r==3)puts("modify [3,3]");
        if(l==r){rt.sum+=k,rt.maxsuf+=k;return;}
        pushdown(l,r,num);
        un mid=(l+r)>>1;
        if(pos<=mid)modify(pos,k,l,mid,num<<1);
        else modify(pos,k,mid+1,r,num<<1|1);
        rt=tl+tr;
    }
    void clear(un ql,un qr,un l=1,un r=n,un num=1)
    {
        if(ql<=l&&r<=qr){rt.sum=-(r-l+1),rt.maxsuf=-1,rt.clear=1;return;}
        pushdown(l,r,num);
        un mid=(l+r)>>1;
        if(ql<=mid)clear(ql,qr,l,mid,num<<1);
        if(qr>mid)clear(ql,qr,mid+1,r,num<<1|1);
        rt=tl+tr;
    }
    node Query(un ql,un qr,un l=1,un r=n,un num=1)
    {
        if(ql<=l&&r<=qr)return rt;
        pushdown(l,r,num);
        un mid=(l+r)>>1;node res;
        if(ql<=mid)res=res+Query(ql,qr,l,mid,num<<1);
        if(qr>mid)res=res+Query(ql,qr,mid+1,r,num<<1|1);
        return res;
    }
}sgt;
ll Qmaxsuf_to_root(ll u)
{
    node r;
    while(top[u]!=1)
    {
    	r=sgt.Query(dfn[top[u]],dfn[u])+r;
        u=fa[top[u]];
    }
    return (sgt.Query(1,dfn[u])+r).maxsuf;
}
int main()
{
	//freopen("input.txt","r",stdin);
    n=read();
    ll m=read();
    for(ll i=2;i<=n;++i)adde(fa[i]=read(),i);
    dfs1(1),dfs2(1,1);
    sgt.build();
    while(m--)
    {
        ll op=read(),u=read();
        if(op==1)sgt.modify(dfn[u],1);
        else if(op==2)
		{
			ll p=sgt.Query(dfn[u],ed[u]).maxsuf;
			sgt.clear(dfn[u],ed[u]);
			sgt.modify(dfn[u],-Qmaxsuf_to_root(u)-1);
		}
        else puts(Qmaxsuf_to_root(u)>=0?"black":"white");
    }
    return 0;
}