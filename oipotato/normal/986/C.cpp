#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
queue<int> q,p;
int n,m,ans;
bool vis[1<<22],use[1<<22];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		vis[x]=1;
	}
	for(int i=0;i<(1<<n);i++)
	{
		if(!vis[i])continue;
		ans++;
		q.push(i);
		vis[i]=0;
		for(;!q.empty();)
		{
			int u=q.front();q.pop();
			p.push((~u)&((1<<n)-1));
			for(;!p.empty();)
			{
				int x=p.front();p.pop();
				if(vis[x])q.push(x),vis[x]=0;
				for(int j=0;j<n;j++)if((x&(1<<j))&&!use[x^(1<<j)])use[x^(1<<j)]=1,p.push(x^(1<<j));
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}