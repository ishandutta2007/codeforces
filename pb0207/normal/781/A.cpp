#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=2e5+1e3+7;

struct node{
	int ne,to;
}edg[N*2+1];

int n,cnt,head[N],vis[N],col[N],ans;

void build(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

void dfs(int i,int fa)
{
	int now=1;
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==fa)
			continue;
		while(now==col[i]||now==col[fa])
			now++;
		col[v]=now++;
		ans=max(ans,col[v]);
		dfs(v,i);
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
	}
	col[1]=1;
	dfs(1,0);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<col[i]<<" ";
}