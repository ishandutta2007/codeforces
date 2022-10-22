#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e6+1e3+7;

int h[N],vis[N];

int n,m,k;

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		h[x]=true;
	}
	vis[1]=true;
	for(int i=1;i<=k;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(vis[u]&&h[u])
		{
			cout<<u;
			return 0;
		}
		if(vis[v]&&h[v])
		{
			cout<<v;
			return 0;
		}
		swap(vis[u],vis[v]);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			cout<<i;
	}
}