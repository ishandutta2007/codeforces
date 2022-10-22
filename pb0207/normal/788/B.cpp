#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e6+1e3+7;

typedef long long ll;

struct node{
	int ne,to;
}edg[N*2+1];

ll n,m,head[N],deg[N],vis[N],ans,ecnt,cnt,tag[N];

void build(int u,int v)
{
	ecnt++;
	edg[ecnt].to=v;
	edg[ecnt].ne=head[u];
	head[u]=ecnt;
}

void dfs(int i)
{
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(!vis[v])
			vis[v]=1,dfs(v);
	}
}

int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%I64d%I64d",&u,&v);
		deg[v]++,deg[u]++;
		if(u!=v)
		{
			tag[u]++,tag[v]++;
			build(u,v);
			build(v,u);
		}
		else
			cnt++;
	}
	for(int i=1;i<=n;i++)
	if(tag[i])
	{
		vis[i]=1,dfs(i);
		break;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&deg[i])
		{
			cout<<"0";
			exit(0);
		}
	for(int i=1;i<=n;i++)
		ans+=tag[i]*(tag[i]-1)/2;
	ans+=cnt*(m-1)-(cnt*(cnt-1)/2);
	printf("%I64d",ans);
}