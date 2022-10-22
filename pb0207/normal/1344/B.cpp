#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int n,m;

char s[N][N];

bool vis[N][N];

int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&s[tx][ty]=='#'&&!vis[tx][ty])
			dfs(tx,ty);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	int d1=1,d2=1;
	for(int i=1;i<=n;i++)
	{
		int j;
		for(j=1;j<=m;j++)		
			if(s[i][j]=='#')
				break;
		if(j>m)
			d1=0;
		for(;s[i][j]=='#'&&j<=m;j++);
		for(;j<=m;j++)
			if(s[i][j]=='#')
			{
				puts("-1");
				return 0;
			}
	}
	for(int i=1;i<=m;i++)
	{
		int j;
		for(j=1;j<=n;j++)		
			if(s[j][i]=='#')
				break;
		if(j>n)
			d2=0;
		for(;s[j][i]=='#'&&j<=n;j++);
		for(;j<=n;j++)
			if(s[j][i]=='#')
			{
				puts("-1");
				return 0;
			}
	}
	if(d1^d2)
	{
		puts("-1");
		return 0;
	}
	/*
	checks
	*/
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!vis[i][j]&&s[i][j]=='#')
				dfs(i,j),ans++;
	printf("%d\n",ans);
}