#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1005][1005],vis[1005],mat[1005];
char s[1005][1005];
int dfs(int u)
{
	for(int i=2;i<=m;i++)
		if(a[u][i]&&!vis[i]&&a[1][i])
		{
			vis[i]=1;
			if(!mat[i]||dfs(mat[i]))
			{
				mat[i]=u;
				return 1;
			}
		}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=(s[i][j]=='B')^(s[i][j-1]=='B')^(s[i-1][j]=='B')^(s[i-1][j-1]=='B');
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i!=1||j!=1)
				a[1][1]^=a[i][j];
	for(int i=2;i<=n;i++)
		for(int j=2;j<=m;j++)
		{
			a[1][j]^=a[i][j];
			a[i][1]^=a[i][j];
		}
	int ct=0,fl=0;
	for(int i=2;i<=n;i++)
		if(a[i][1])
		{
			memset(vis,0,sizeof(vis));
			fl+=dfs(i);
		}
	a[1][1]^=(fl&1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ct+=a[i][j];
	printf("%d\n",ct-fl);
	return 0;
}