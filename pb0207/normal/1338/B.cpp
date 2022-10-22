#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

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

int mn,mx,deg[N],d[N];

void dfs(int x,int f)
{
	int sec=0;
	for(int tmp=head[x];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==f)
			continue;
		d[v]=d[x]+1;
		dfs(v,x);
		if(deg[v]==1)
		{
			if(sec)
				mx--;
			sec=1;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
		deg[u]++,deg[v]++;
	}
	mx=n-1;
	for(int i=1;i<=n;i++)
		if(deg[i]>=2)
		{
			dfs(i,0);
			break;
		}
	int cnt[2]={0,0};
	for(int i=1;i<=n;i++)
		if(deg[i]==1)
			cnt[d[i]&1]++;
	if(cnt[0]&&cnt[1])
		mn=3;
	else
		mn=1;
	printf("%d %d\n",mn,mx);
}