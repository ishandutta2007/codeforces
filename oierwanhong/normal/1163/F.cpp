#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 400011;
const ll LINF = 1.233e18;
struct edge{int v,w,nxt;}e[MAXN<<1|1];
int cnt=1,last[MAXN];
void adde(int u,int v,int w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}

struct node
{
	int u;
	ll dis;
	node(){}
	node(int u,ll dis):u(u),dis(dis) {}
	bool operator< (const node& you)const{return dis>you.dis;}
};
ll ds[MAXN],dt[MAXN];
int pre[MAXN];
void Dij(ll* dis,int s,int n)
{
	static std::priority_queue<node>q;
	for(int i=1;i<=n;++i)dis[i]=LINF,pre[i]=0;
	dis[s]=0,q.push(node(s,0));
	while(q.size())
	{
		node tp=q.top();q.pop();
		int u=tp.u;
		if(dis[u]!=tp.dis)continue;
		for(int i=last[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(umin(dis[v],dis[u]+e[i].w))pre[v]=i,q.push(node(v,dis[v]));
		}
	}
}
bool mark[MAXN];
int T[MAXN],bel[MAXN], cur;
void Mark(int u)
{
	if(u>1)Mark(e[pre[u]^1].v);
	T[u]=++cur,bel[u]=T[u];
}

int n,m,q;
ll f[MAXN];
struct Segment_Tree
{
	ll t[MAXN<<2|1];
#define rt t[num]
	Segment_Tree(){memset(t,0x3f,sizeof t);}
	void pushdown(un num)
	{
		umin(t[num<<1],rt),umin(t[num<<1|1],rt);
	}
	void Chkmin(un ql,un qr,ll k,un l=1,un r=n,un num=1)
	{
		//if(num==1){printf("chkmin [%u,%u]\n",ql,qr);}
		if(ql>qr)return;
		if(ql<=l&&r<=qr){umin(rt,k);return;}
		pushdown(num);
		un mid=(l+r)>>1;
		if(ql<=mid)Chkmin(ql,qr,k,l,mid,num<<1);
		if(qr>mid)Chkmin(ql,qr,k,mid+1,r,num<<1|1);
	}
	void pushall(ll* f,un l=1,un r=n,un num=1)
	{
		if(l==r){f[l]=rt;return;}
		pushdown(num);
		un mid=(l+r)>>1;
		pushall(f,l,mid,num<<1),pushall(f,mid+1,r,num<<1|1);
	}
}sgt;
int main()
{
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;++i){int u=read(),v=read(),w=read();adde(u,v,w),adde(v,u,w);}
	Dij(dt,n,n);
	Dij(ds,1,n);
	Mark(n);
	for(int u=1;u<=n;++u)
		if(!bel[u]&&ds[u]<LINF)
		{
			int x=u;
			while(!bel[x])x=e[pre[x]^1].v;
			int y=u;
			while(!bel[y])bel[y]=bel[x],y=e[pre[y]^1].v;
		}
	//puts("Pass 108");
	for(int i=1;i<=m;++i)
	{
		int u=e[i<<1|1].v,v=e[i<<1].v;
		if(ds[u]==LINF||ds[v]==LINF|| (pre[v]>>1)==i||(pre[u]>>1)==i)continue;
		int x=bel[u],y=bel[v];
		if(x<y)sgt.Chkmin(x,y-1,ds[u]+e[i<<1].w+dt[v]);
		else if(y<x)sgt.Chkmin(y,x-1,ds[v]+e[i<<1].w+dt[u]);
	}
	sgt.pushall(f);
	while(q--)
	{
		int i=read(),w=read();
		int u=e[i<<1|1].v,v=e[i<<1].v;
		if(ds[u]==LINF||ds[v]==LINF)
		{
			printf("%lld\n",ds[n]);
			continue;
		}
		ll res=min(ds[u]+w+dt[v],ds[v]+w+dt[u]);
		if(T[u]&&T[v]&&(pre[v]>>1)==i)umin(res,f[bel[u]]);
		else if(T[u]&&T[v]&&(pre[u]>>1)==i)umin(res,f[bel[v]]);
		else umin(res,ds[n]);
		printf("%lld\n",res);
	}
	return 0;
}