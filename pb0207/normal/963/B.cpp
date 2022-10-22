#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N=2e5+1e3+7;

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

int n,dep[N],deg[N],vis[N],rt;

void dfs(int i,int f)
{
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(v==f)
			continue;
		dep[v]=dep[i]+1;
		dfs(v,i);
	}
}

typedef pair<int,int> pii;
#define mp make_pair 
#define fs first 
#define sd second 

priority_queue<pii>q;

vector<int>ans;

void calc()
{
	for(int i=1;i<=n;i++)
		if(!(deg[i]&1))
			q.push(mp(dep[i],i));
	while(!q.empty())
	{
		int i=q.top().sd;
		q.pop();
		if(vis[i]||(deg[i]&1))
			continue;
		vis[i]=1;
		ans.push_back(i);
		for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
		{
			int v=edg[tmp].to;
			deg[v]--;
			q.push(make_pair(dep[v],v));
		}
	}
	if(ans.size()!=n)
		puts("NO");
	else
	{
		puts("YES");
		for(int i=0;i<ans.size();i++)
			printf("%d\n",ans[i]);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(!x)
		{
			rt=i;
			continue;
		}
		build(i,x);
		build(x,i);
		deg[x]++;
		deg[i]++;
	}
	dfs(rt,0);
	calc();
} 	
/*
11
0 1 2 2 2 5 5 5 6 1 1
*/