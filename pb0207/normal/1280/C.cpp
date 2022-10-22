#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int head[N],cnt;

struct node{
	int ne,to,w;
}edg[N*2+1];

void build(int u,int v,int w)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	edg[cnt].w=w;
	head[u]=cnt;
}

int T,k,sz[N];

ll ans1,ans2;

void dfs(int i,int f)
{
	sz[i]=1;
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==f)
			continue;
		dfs(v,i);
		ans1+=1ll*edg[tmp].w*(sz[v]&1);
		ans2+=1ll*edg[tmp].w*min(sz[v],2*k-sz[v]);
		sz[i]+=sz[v];
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=k*2;i++)
			head[i]=0;
		cnt=0;
		scanf("%d",&k);
		for(int i=1;i<=2*k-1;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			build(u,v,w);
			build(v,u,w);
		}
		ans1=0,ans2=0;
		dfs(1,0);
		printf("%lld %lld\n",ans1,ans2);
	}
}