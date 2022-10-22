#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=3e5+1e3+7;

int head[N],cnt;

char s[N];

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

queue<int>q;

int f[N][27],g[N],deg[N],mx[N];

int n,m;

void topo()
{
	for(int i=1;i<=n;i++)
		if(deg[i]==0)
			q.push(i),f[i][s[i]-'a']++;
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		for(int j=0;j<26;j++)
			mx[i]=max(mx[i],f[i][j]);
		for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
		{
			int v=edg[tmp].to;
			for(int j=0;j<26;j++)
				f[v][j]=max(f[v][j],f[i][j]+((s[v]-'a')==j));
			if(!(--deg[v]))
				q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
		if(deg[i]!=0)
		{
			puts("-1");
			exit(0);
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,mx[i]);
	printf("%d\n",ans);
}

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		deg[v]++;
		build(u,v);
	}
	topo();
}