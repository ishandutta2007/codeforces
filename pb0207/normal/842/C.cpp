#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

struct node{
	int ne,to;
}edg[N*2+1];

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int n,a[N],head[N],cnt,f[N],g[N],last[N],ans[N],gf[N];

void build(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

int calc(int x)
{
	int ret=f[x];
	int cc=0;
	for(int i=1;i<=21;i++)
	{
		if(!x)
			break;
		ret=max(ret,gcd(f[gf[x]],cc));
		cc=gcd(cc,a[x]);
		x=gf[x];
	}
	return ret;
}

void dfs(int i,int fa)
{
	f[i]=gcd(f[fa],a[i]),gf[i]=fa;
	ans[i]=calc(i);
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v!=fa)
			dfs(v,i);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
	}
	f[1]=a[1];
	dfs(1,0);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}