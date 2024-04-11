#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

struct node{
	int ne,to;
}edg[N*2+1];

int n,cnt,head[N],x,da[N],db[N];

void build(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

void dfs1(int i,int fa)
{
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==fa)
			continue;
		da[v]=da[i]+1;
		dfs1(v,i);
	}
}

void dfs2(int i,int fa)
{
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==fa)
			continue;
		db[v]=db[i]+1;
		dfs2(v,i);
	}
}

int main()
{
	cin>>n>>x;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		build(u,v);
		build(v,u);
	}
	dfs1(1,0);
	dfs2(x,0);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(da[i]>db[i])
			ans=max(ans,da[i]*2);
	cout<<ans;
}