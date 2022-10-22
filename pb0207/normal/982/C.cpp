#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int head[N],cnt;

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

int n;

int f[N][2],g[2];

void dp(int i,int F)
{
	f[i][0]=-1e6;
	f[i][1]=0;
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==F)
			continue;
		dp(v,i);
		g[0]=max(f[i][0]+f[v][0]+1,f[i][1]+f[v][1]);
		g[1]=max(f[i][0]+f[v][1],f[i][1]+f[v][0]+1);
		f[i][0]=g[0];
		f[i][1]=g[1];
	}
}

int main()
{
	scanf("%d",&n);
	if(n&1)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
	}
	dp(1,0);
	printf("%d",f[1][0]);
}