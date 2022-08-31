#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,vis[1005][1005],dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
char s[1005][1005];
void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<=0||xx>n||yy<=0||yy>m||vis[xx][yy]||s[xx][yy]=='.') continue;
		dfs(xx,yy);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	int fl1=0,fl2=0;
	for(int i=1;i<=n;i++)
	{
		int mn=1e9,mx=0,ct=0;
		for(int j=1;j<=m;j++)
			if(s[i][j]=='#')
			{
				mn=min(mn,j);
				mx=max(mx,j);
				ct++;
			}
		if(ct&&ct!=mx-mn+1)
		{
			printf("-1");
			return 0;
		}
		if(!ct) fl1=1;
	}
	for(int i=1;i<=m;i++)
	{
		int mn=1e9,mx=0,ct=0;
		for(int j=1;j<=n;j++)
			if(s[j][i]=='#')
			{
				mn=min(mn,j);
				mx=max(mx,j);
				ct++;
			}
		if(ct&&ct!=mx-mn+1)
		{
			printf("-1");
			return 0;
		}
		if(!ct) fl2=1;
	}
	if(fl1+fl2==1)
	{
		printf("-1");
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='#'&&!vis[i][j])
			{
				dfs(i,j);
				ans++;
			}
	printf("%d",ans);
	return 0;
}