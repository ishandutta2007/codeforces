#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7,P=1e9+7;

int n,m,k,x,cnt,head[N];

ll f[N][11][3],ans;

struct node{
	int ne,to;
}edg[N*2+1];

void build(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

void dfs(int i,int fa)
{
	ll g[11][3];
	f[i][0][0]=k-1,f[i][1][1]=1,f[i][0][2]=m-k;
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		memset(g,0,sizeof(g));
		int v=edg[tmp].to;
		if(v==fa)
			continue;
		dfs(v,i);
		for(int j=x;j>=0;j--)
			for(int t=0;t<=j;t++)
			{
				g[j][0]=(g[j][0]+f[i][j-t][0]*(f[v][t][0]+f[v][t][1]+f[v][t][2])%P)%P;
				g[j][1]=(g[j][1]+f[i][j-t][1]*(f[v][t][0])%P)%P;
				g[j][2]=(g[j][2]+f[i][j-t][2]*(f[v][t][0]+f[v][t][2])%P)%P;
			}
		for(int j=x;j>=0;j--)
			for(int t=0;t<3;t++)
				f[i][j][t]=g[j][t];
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
	}
	scanf("%d%d",&k,&x);
	dfs(1,0);
	for(int j=0;j<=x;j++)
		for(int t=0;t<3;t++)
			ans=(ans+f[1][j][t])%P;
	printf("%lld",ans);
}