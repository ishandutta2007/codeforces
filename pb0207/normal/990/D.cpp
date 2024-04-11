#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e3+1e2+7;

int n,a,b,g[N][N];

int vis[N];

void dfs(int i)
{
	vis[i]=1;
	for(int j=1;j<=n;j++)
		if(g[i][j]&&!vis[j])
			dfs(j);
}

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	if(a>1&&b>1)
	{
		puts("NO");
		return 0;
	}
	int m=max(a,b);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=1;
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	for(int i=1;i<=n-m;i++)
		g[i][i+1]=g[i+1][i]=0;
	dfs(1);
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
			if(i!=j)
				printf("%d",a==1?g[i][j]:g[i][j]^1);
			else
				printf("%d",g[i][j]);
}