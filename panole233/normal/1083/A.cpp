#include<bits/stdc++.h>
using namespace std;

long long ans,f[300010];
int n,x,y,v,w[300010],cnt,hd[300010],fa[300001];
struct node{int to,next,val;}e[600010];

void addedge(int x,int y,int val)
{
	e[++cnt]=(node){y,hd[x],val},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y],val},hd[y]=cnt;
}

void dfs(int x)
{
	long long ma1=0,ma2=0;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x])
		{
			fa[e[i].to]=x,dfs(e[i].to);
			f[e[i].to]-=e[i].val;
			if (f[e[i].to]>ma1) ma2=ma1,ma1=f[e[i].to]; else
			if (f[e[i].to]>ma2) ma2=f[e[i].to];
		}
	ans=max(ans,ma1+ma2+w[x]);
	f[x]=ma1+w[x];
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&w[i]);
	for (int i=1; i<n; i++) scanf("%d%d%d",&x,&y,&v),addedge(x,y,v);
	memset(fa,0,sizeof(fa));
	ans=0;dfs(1),printf("%lld\n",ans);
	return 0;
}