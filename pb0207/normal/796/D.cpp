#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=3e5+1e3+7;

struct node{
	int ne,to,w;
}edg[N*2+1];

int cnt,head[N],n,m,k,vis[N],ans[N],d[N];

queue<int>q;

void build(int u,int v)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
}

void bfs()
{
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		if(d[i]==k)
			continue;
		for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
		{
			int v=edg[tmp].to;
			if(!vis[v])
			{
				q.push(v);
				d[v]=d[i]+1;
				vis[v]=true;
				ans[(tmp+1)/2]=1;
			}
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		q.push(x);
		vis[x]=true;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
	}
	bfs();
	for(int i=1;i<n;i++)
		if(ans[i]==0)
			ans[0]++;
	cout<<ans[0]<<endl;
	for(int i=1;i<n;i++)
		if(ans[i]==0)
		printf("%d\n",i);
}