#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
int n,a[100005],ls[100005],rs[100005],pos[100005],rt,sz[100005],t;
ll val[100005],lazy[100005],tans[100005];
int myrand()
{
	return ((rand()<<15)+rand())&((1u<<31)-1);
}
void pushup(int x)
{
	sz[x]=1+sz[ls[x]]+sz[rs[x]]; 
}
void col(int x,ll v)
{
	lazy[x]+=v;
	val[x]+=v;
}
void pushdown(int x)
{
	if(lazy[x])
	{
		if(ls[x]) col(ls[x],lazy[x]);
		if(rs[x]) col(rs[x],lazy[x]);
		lazy[x]=0;
	}
}
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	pushdown(x);
	pushdown(y);
	if(pos[x]<pos[y])
	{
		rs[x]=merge(rs[x],y);
		pushup(x);
		return x;
	}
	ls[y]=merge(x,ls[y]);
	pushup(y);
	return y;
}
void split(int x,int &L,int &R,int k)
{
	if(!x)
	{
		L=R=0;
		return;
	}
	pushdown(x);
	if(sz[ls[x]]>=k)
	{
		R=x;
		split(ls[x],L,ls[R],k);
		pushup(R);
	}
	else
	{
		L=x;
		split(rs[x],rs[L],R,k-sz[ls[x]]-1);
		pushup(L);
	}
}
int query(ll v)
{
	int u=rt,ans=sz[rt]+1,k=0;
	while(u)
	{
		pushdown(u);
		if((k+sz[ls[u]]+1)*v>val[u]) ans=k+sz[ls[u]]+1,u=ls[u];
		else k+=(sz[ls[u]]+1),u=rs[u];
	}
	return ans;
}
void dfs(int u)
{
	pushdown(u);
	if(ls[u]) dfs(ls[u]);
	t++;
	tans[t]=tans[t-1]+val[u];
	if(rs[u]) dfs(rs[u]);
}
int main()
{
//	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		pos[i]=myrand(),sz[i]=1;
	for(int i=1;i<=n;i++)
	{
	//	printf("i=%d\n",i); 
		int q=query(a[i]);
		int u,v;
		split(rt,u,v,q-1);
		col(v,a[i]);
		val[i]=1ll*q*a[i];
		u=merge(u,i);
		rt=merge(u,v);
	//	printf("q=%d,rt=%d\n",q,rt);
	//	for(int j=1;j<=i;j++)
	//		printf("j=%d,ls=%d,rs=%d,val=%lld,pos=%d,lazy=%lld,sz=%d\n",j,ls[j],rs[j],val[j],pos[j],lazy[j],sz[j]);
	}
	dfs(rt);
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,tans[i]);
	printf("%lld\n",ans);
	return 0;
}