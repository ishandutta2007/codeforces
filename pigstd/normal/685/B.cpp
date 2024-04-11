#include<bits/stdc++.h>
using namespace std;

const int M=300010;
int fa[M],size[M];//fa[i]i
int maxs[M];//maxs[i]i 
int ans[M],n,m;

struct node
{
	int next,to;
}a[M*2];
int head[M],cnt;

void dfs(int k)
{
	size[k]=1;
	for (int i=head[k];i;i=a[i].next)
	{
		dfs(a[i].to);
		size[k]+=size[a[i].to];
		if (size[a[i].to]>size[maxs[k]])
			maxs[k]=a[i].to;
	}
	if (size[maxs[k]]*2<=size[k])
		ans[k]=k;
	else
	{
		int x=ans[maxs[k]];
		while(size[x]*2<size[k])
			x=fa[x];// 
		ans[k]=x;
	}
}

void add(int u,int to)
{
	a[++cnt].next=head[u],a[cnt].to=to,head[u]=cnt;
}

int main()
{
	cin>>n>>m;
	for (int i=2;i<=n;i++)
	{
		cin>>fa[i];
		add(fa[i],i);
	}
	dfs(1);
	for (int i=1;i<=m;i++)
	{
		int a;
		cin>>a;
		cout<<ans[a]<<endl;
	}
	return 0;
}