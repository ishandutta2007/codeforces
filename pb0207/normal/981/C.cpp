#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1e6+1e3+7;

int n,deg[N],lf;

vector<int>e[N];

void dfs(int i,int f)
{
	if(deg[i]==1)
		printf("%d",i);
	for(int j=0;j<e[i].size();j++)
	{
		int v=e[i][j];
		if(v==f)
			continue;
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
		e[u].push_back(v);
		e[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	for(int i=1;i<=n;i++)
		if(deg[i]==1)
			lf++;
	bool ans=false;
	for(int i=1;i<=n;i++)
		if(deg[i]==(lf-(deg[i]==1)))
		{
			puts("Yes");
			printf("%d\n",deg[i]);
			for(int j=0;j<e[i].size();j++)
			{
				int v=e[i][j];
				printf("%d ",i);
				dfs(v,i);
				puts("");
			}
			return 0;
		}
	puts("No");
}