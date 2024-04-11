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

const int MAXN = 1000011;
struct DSU
{
	int fa[MAXN],val[MAXN],size[MAXN];
	void init(int n,int maxn)
	{
		for(int i=1;i<=n;++i)fa[i]=i,val[i]=0,size[i]=1;
		for(int i=n+1;i<=maxn;++i)fa[i]=i;
	}
	int find(int x)
	{
		if(fa[x]==x)return x;
		int r=find(fa[x]);
		umax(val[x],val[fa[x]]);
		return fa[x]=r;
	}
	void uni(int x,int y)
	{
		x=find(x),y=find(y);
		if(x!=y)fa[x]=y,size[y]+=size[x];
	}
}dsu1,dsu2;
struct LCT
{
	int fa[MAXN],son[MAXN][2],val[MAXN],maxv[MAXN];
	ll sum[MAXN],add[MAXN];
	bool not_root(int x){return son[fa[x]][0]==x||son[fa[x]][1]==x;}
	void pushup(int x)
	{
		maxv[x]=max(max(maxv[son[x][0]],maxv[son[x][1]]),val[x]);
		sum[x]=sum[son[x][0]]+sum[son[x][1]]+add[x];
	}
	void rotate(int x)
	{
		int y=fa[x],z=fa[y],k=(son[y][1]==x);
		if(not_root(y))son[z][son[z][1]==y]=x;
		fa[x]=z;
		son[y][k]=son[x][!k],fa[son[x][!k]]=y;
		son[x][!k]=y,fa[y]=x;
		pushup(y),pushup(x);
	}
	void splay(int x)
	{
		while(not_root(x))
		{
			int y=fa[x];
			if(not_root(y))rotate((son[y][1]==x)==(son[fa[y]][1]==y)?y:x);
			rotate(x);
		}
	}
	void access(int x)
	{
		for(int y=0;x;y=x,x=fa[x])
			splay(x),son[x][1]=y,pushup(x);
	}
	void link(int x,int y){access(x),splay(x),fa[x]=y;}
	ll Query(int x,int lim)
	{
		access(x),splay(x);
		if(!lim)return sum[x];
		while(x)
		{
			if(maxv[son[x][1]]>=lim)x=son[x][1];
			else if(val[x]>=lim)break;
			else x=son[x][0];
		}
		if(!x)return 0;
		access(x),splay(x);
		return sum[x];
	}
}lct;
int n,m;
int tim[MAXN],tag[MAXN];
int main()
{
	n=read(),m=read();
	dsu1.init(n,1000000),dsu2.init(n,1000000);
	for(int T=n+1;T<=n+m;++T)
	{
		char op[15];
		scanf("%s",op);
		if(op[0]=='U')
		{
			int x=dsu1.find(read()),y=dsu1.find(read());
			if(x==y)continue;
			lct.link(x,T),lct.link(y,T);
			dsu1.uni(x,T),dsu1.uni(y,T);
		}
		else if(op[0]=='M')
		{
			int x=dsu2.find(read()),y=dsu2.find(read());
			if(x==y)continue;
			dsu2.uni(x,T),dsu2.uni(y,T);
		}
		else if(op[0]=='A')
		{
			int x=dsu1.find(read());
			//printf("x=%d,size=%d\n",x,dsu1.size[x]);
			lct.add[T]=dsu1.size[x];
			lct.val[T]=T,lct.pushup(T);
			//printf("Tag[%d]=%d,size[%d]=%d\n",tot1,tag[tot1],x,dsu1.size[x]);
			lct.link(x,T);
			dsu1.uni(x,T);
		}
		else if(op[0]=='Z')
		{
			int x=dsu2.find(read());
			dsu2.val[T]=T;
			dsu2.uni(x,T);
			//printf("Val2[%d]=%d\n",T,T);
		}
		else
		{
			int x=read();
			dsu2.find(x);
			int lim=dsu2.val[x];
			//printf("x=%d,lim=%d\n",x,lim);
			printf("%lld\n",lct.Query(x,lim));
		}
		//printf("T=%d:\n",T);
		//for(int i=1;i<=n+T;++i)printf("i=%d,tim=%d,tag=%d,fa=%d\n",i,tim[i],tag[i],fa[i]);
	}
	return 0;
}