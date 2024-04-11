#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef int ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
const ll INF=1ll<<58;
#define MAXN 200011
struct edge
{
	ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
	e[++cnt].v=v;
	e[cnt].nxt=last[u],last[u]=cnt;
}

ll size[MAXN],mson[MAXN],fa[MAXN],dep[MAXN],len[MAXN];
void dfs1(ll u,ll now_dep)
{
	size[u]=1,dep[u]=now_dep;
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v==fa[u])continue;
		fa[v]=u;
		dfs1(v,dep[u]+1);
		size[u]+=size[v];
		if(size[v]>size[mson[u]])mson[u]=v;
	}
}
ll top[MAXN];
void dfs2(ll u,ll now_top)
{
	top[u]=now_top;
	if(mson[u])dfs2(mson[u],now_top);
	for(ll i=last[u];i;i=e[i].nxt)
		if(e[i].v!=fa[u]&&e[i].v!=mson[u])dfs2(e[i].v,e[i].v);
}
ll LCA(ll u,ll v)
{
	while(top[u]!=top[v])
		if(dep[top[u]]>=dep[top[v]])u=fa[top[u]];
		else v=fa[top[v]];
	return dep[u]>dep[v]?v:u;
}
//
bool check_on(ll u,ll v,ll x)
{
	ll r=LCA(u,v);
	return (LCA(u,x)==x||LCA(v,x)==x)&&(LCA(x,r)==r);
}
ll n,pos[MAXN];
struct Segment_Tree
{
	struct node
	{
		ll u,v,pos;
		node(){}
		node(ll type){pos=0;}
		node(ll _u,ll _v,ll p){u=_u,v=_v,pos=p;}
		node operator +(node t)
		{
			if(!pos||!t.pos)return node(0);
			ll p=max(pos,t.pos);
			if(check_on(u,v,t.u)&&check_on(u,v,t.v))return node(u,v,p);
			if(check_on(t.u,t.v,u)&&check_on(t.u,t.v,v))return node(t.u,t.v,p);
			if(check_on(t.u,v,t.v)&&check_on(t.u,v,u))return node(t.u,v,p);
			if(check_on(t.u,u,t.v)&&check_on(t.u,u,v))return node(t.u,u,p);
			if(check_on(t.v,u,t.u)&&check_on(t.v,u,v))return node(t.v,u,p);
			if(check_on(t.v,v,t.u)&&check_on(t.v,v,u))return node(t.v,v,p);
			return node(0);
		}
	}t[MAXN<<2|1];
	#define rt t[num]
	#define tl t[num<<1]
	#define tr t[num<<1|1]
	void build(un l=1,un r=n,un num=1)
	{
		if(l==r)rt=node(pos[l],pos[l],l);
		else
		{
			un mid=(l+r)>>1;
			build(l,mid,num<<1),build(mid+1,r,num<<1|1);
			rt=tl+tr;
		}
	}
	node _Query(node pre,un l,un r,un num)
	{
		if((pre+rt).pos)return pre+rt;
		if(l==r)return pre;
		un mid=(l+r)>>1;
		if((pre+tl).pos)return _Query(pre+tl,mid+1,r,num<<1|1);
		else return _Query(pre,l,mid,num<<1);
	}
	node _Query(un l,un r,un num)
	{
		if(rt.pos)return rt;
		un mid=(l+r)>>1;
		if(tl.pos)return _Query(tl,mid+1,r,num<<1|1);
		return _Query(l,mid,num<<1);
	}
	ll Query(){return _Query(1,n,1).pos;}
	void modify(ll x,un l=1,un r=n,un num=1)
	{
		if(l==r)return (void)(rt=node(pos[x],pos[x],l));
		un mid=(l+r)>>1;
		if(x<=mid)modify(x,l,mid,num<<1);
		else modify(x,mid+1,r,num<<1|1);
		rt=tl+tr;
	}
}sgt;
ll w[MAXN];
int main()
{
	n=read();
	for(ll i=1;i<=n;++i)w[i]=read()+1,pos[w[i]]=i;
	for(ll i=2;i<=n;++i)adde(read(),i);
	dfs1(1,1),dfs2(1,1);
	sgt.build();
	ll query=read();
	while(query--)
	{
		ll op=read();
		if(op==2)printf("%d\n",sgt.Query());
		else
		{
			ll u=read(),v=read();
			std::swap(w[u],w[v]);
			pos[w[u]]=u,pos[w[v]]=v;
			sgt.modify(w[u]),sgt.modify(w[v]);
		}
	}
	return 0;
}