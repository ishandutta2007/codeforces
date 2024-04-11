#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
const ll INF=1ll<<58;
#define MAXN 200011
ll n,m,k;
struct Segment_Tree
{
	struct node
	{
		ll tag,maxv;
	}t[MAXN<<2|1];
	#define rt t[num]
	#define tl t[num<<1]
	#define tr t[num<<1|1]
	void build(ll* arr,un l=1,un r=n,un num=1)
	{
		if(l==r)rt.maxv=arr[l];
		else
		{
			un mid=(l+r)>>1;
			build(arr,l,mid,num<<1),build(arr,mid+1,r,num<<1|1);
			rt.maxv=max(tl.maxv,tr.maxv);
		}
	}
	void pushdown(un num)
	{
		if(!rt.tag)return;
		tl.maxv+=rt.tag,tl.tag+=rt.tag;
		tr.maxv+=rt.tag,tr.tag+=rt.tag;
		rt.tag=0;
	}
	void modify(un ql,un qr,ll k,un l=1,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)
		{
			rt.tag+=k,rt.maxv+=k;return;
		}
		pushdown(num);
		un mid=(l+r)>>1;
		if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
		if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
		rt.maxv=max(tl.maxv,tr.maxv);
	}
	ll Qmax(){return t[1].maxv;}
}sgt;
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
ll dfn[MAXN],ed[MAXN],arr[MAXN], cur=0,ans=0;
void dfs(ll u,ll now_dep,ll fa=0)
{
	dfn[u]=++cur;arr[cur]=now_dep;
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v==fa)continue;
		dfs(v,now_dep+1, u);
	}
	ed[u]=cur;
}
void solve(ll u,ll fa=0)
{
	sgt.modify(1,n,1),sgt.modify(dfn[u],ed[u],-2ll);
	if(sgt.Qmax()<=k)++ans;
	for(ll i=last[u];i;i=e[i].nxt)
	{
		ll v=e[i].v;
		if(v!=fa)solve(v,u);
	}
	sgt.modify(1,n,-1ll),sgt.modify(dfn[u],ed[u],2ll);
}
bool black[MAXN];
int main()
{
	n=read(),m=read(),k=read();
	for(ll i=1;i<=m;++i)black[read()]=1;
	for(ll i=1;i<n;++i)
	{
		ll u=read(),v=read();
		adde(u,v),adde(v,u);
	}
	dfs(1,1);
	for(ll i=1;i<=n;++i)
		if(!black[i])arr[dfn[i]]=-INF;
	sgt.build(arr);
	solve(1);
	printf("%lld\n",ans );
	return 0;
}