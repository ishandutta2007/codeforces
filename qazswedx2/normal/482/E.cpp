#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[500005];
int n,m,val[100005],sz[100005],szi[100005],f[100005],ch[100005][2];
int rev[100005],p[100005],lazy[100005],h[100005],t;
ll sum[100005],ans,c[100005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void pushup(int x)
{
	sz[x]=1+sz[ch[x][0]]+sz[ch[x][1]]+szi[x];
	sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+1ll*val[x]*(szi[x]+1);
}
bool nroot(int x)
{
	return ch[f[x]][0]==x||ch[f[x]][1]==x;
}
void rotate(int x)
{
	int y=f[x],z=f[y],k=ch[y][1]==x,r=ch[x][!k];
	if(nroot(y)) ch[z][ch[z][1]==y]=x;
	ch[x][!k]=y;
	ch[y][k]=r;
	f[r]=y;
	f[y]=x;
	f[x]=z;
	pushup(y);
	pushup(x);
}
void pushr(int x)
{
	rev[x]^=1;
	swap(ch[x][0],ch[x][1]);
}
void col(int x,int v)
{
	c[x]+=2ll*v*(szi[x]+1);
	lazy[x]+=v;
}
void pushdown(int x)
{
	if(rev[x])
	{
		if(ch[x][0]) pushr(ch[x][0]);
		if(ch[x][1]) pushr(ch[x][1]);
		rev[x]=0;
	}
	if(lazy[x])
	{
		if(ch[x][0]) col(ch[x][0],lazy[x]);
		if(ch[x][1]) col(ch[x][1],lazy[x]);
		lazy[x]=0;
	}
}
void pushall(int x)
{
	if(nroot(x)) pushall(f[x]);
	pushdown(x);
}
void splay(int x)
{
	pushall(x);
	while(nroot(x))
	{
		int y=f[x],z=f[y];
		if(nroot(y)) rotate((ch[z][1]==y)^(ch[y][1]==x)?x:y);
		rotate(x);
	}
}
void access(int x)
{
	for(int y=0;x;y=x,x=f[x])
	{
		splay(x);
		szi[x]=szi[x]+sz[ch[x][1]]-sz[y];
		ch[x][1]=y;
		pushup(x);
	}
}
void makeroot(int x)
{
	access(x);
	splay(x);
	pushr(x);
}
int findroot(int x)
{
	access(x);
	splay(x);
	while(ch[x][0]) pushdown(x),x=ch[x][0];
	splay(x);
	return x;
}
void split(int x,int y)
{
	makeroot(x);
	access(y);
	splay(y);
}
void link(int x,int y)
{
	split(x,y);
	if(!f[x]&&x!=y)
	{
		f[x]=y;
		szi[y]+=sz[x];
		pushup(y);
	}
}
void cut(int x,int y)
{
	split(x,y);
	if(f[x]==y&&ch[y][0]==x&&!ch[x][1])
	{
		ch[y][0]=f[x]=0;
		pushup(y);
	}
}
void tlink(int x)
{
	int y=p[x];
	split(1,y);
	col(y,sz[x]);
	makeroot(x);
//	printf("link:x=%d,y=%d,sz=%d,%d,szi=%d,sum=%lld\n",x,y,sz[x],sz[y],szi[y]+1,sum[y]);
	ans+=2ll*sz[x]*sum[y];
	link(x,y);
}
void tcut(int x)
{
	int y=p[x];
	cut(x,y);
	split(1,y);
	col(y,-sz[x]);
	makeroot(x);
	//printf("cut:x=%d,y=%d,sz=%d,%d,szi=%d,sum=%lld\n",x,y,sz[x],sz[y],szi[y]+1,sum[y]);
	ans-=2ll*sz[x]*sum[y];
}
void modify(int x,int v)
{
	split(1,x);
//	printf("x=%d,val=%d,c=%lld\n",x,val[x],c[x]);
	ans+=(v-val[x])*c[x];
	val[x]=v;
	pushup(x);
}
void dfs(int u,int fa)
{
	if(fa) tlink(u);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		sz[i]=1,c[i]=1;
	for(int i=2;i<=n;i++)
		scanf("%d",&p[i]),add(i,p[i]),add(p[i],i);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]),ans+=val[i];
	dfs(1,0);
	scanf("%d",&m);
	printf("%.10f\n",1.0*ans/n/n);
//		for(int j=1;j<=n;j++)
//			printf("%lld ",c[j]);
//		printf("\n");
	for(int i=1;i<=m;i++)
	{
		int x,y;
		char op;
		scanf(" %c%d%d",&op,&x,&y);
		if(op=='P')
		{
			split(1,y);
			splay(x);
			int nw=x;
			while(ch[nw][0]) pushdown(nw),nw=ch[nw][0];
			if(nw==1) swap(x,y);
			tcut(x);
			p[x]=y;
			tlink(x);
		}
		else
		{
			modify(x,y);
		}
		printf("%.10f\n",1.0*ans/n/n);
	//	printf("c=");
	//	for(int j=1;j<=n;j++)
	//		printf("%lld ",c[j]);
	//	printf("\n");
	}
	return 0;
}