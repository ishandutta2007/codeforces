#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e3+1e2+7;

int n,a[N][N],k;

char s[N][N];

int d[N][N],c[N][N];

int pre[N][N],suf[N][N];

int tot=0;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=(s[i][j]=='W');
	for(int i=1;i<=n;i++)
	{
		pre[i][0]=suf[i][n+1]=1;
		for(int j=1;j<=n;j++)
			pre[i][j]=pre[i][j-1]&a[i][j];
		for(int j=n;j>=1;j--)
			suf[i][j]=suf[i][j+1]&a[i][j];
		for(int j=1;j<=n;j++)
			c[i][j]=c[i-1][j];
		if(pre[i][n])
		{
			tot++;
			continue;
		}
		for(int j=1;j<=n-k+1;j++)
			c[i][j]+=(pre[i][j-1]&&suf[i][j+k]);
	}
	for(int j=1;j<=n;j++)
	{
		pre[0][j]=suf[n+1][j]=1;
		for(int i=1;i<=n;i++)
			pre[i][j]=pre[i-1][j]&a[i][j];
		for(int i=n;i>=1;i--)
			suf[i][j]=suf[i+1][j]&a[i][j];
		for(int i=1;i<=n;i++)
			d[i][j]=d[i][j-1];
		if(pre[n][j])
		{
			tot++;
			continue;
		}
		for(int i=1;i<=n-k+1;i++)
			d[i][j]+=(pre[i-1][j]&suf[i+k][j]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans=max(ans,d[i][j+k-1]-d[i][j-1]+c[i+k-1][j]-c[i-1][j]);
	printf("%d",ans+tot);
}