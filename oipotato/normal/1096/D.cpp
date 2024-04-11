#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const long long inf=(long long)1000000000ll*1000000000;
long long f[100010][4];
int n,a[100010];
char s[100010];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n+1)for(int j=0;j<=3;j++)f[i-1][j]=inf;
	f[0][0]=0;
	rep(i,n)
	if(s[i]=='h')
	{
		for(int j=0;j<=3;j++)
		{
			f[i][j]=min(f[i][j],f[i-1][j]+a[i]);
			if(j!=0)f[i][j]=min(f[i][j],f[i-1][j]);else f[i][j+1]=min(f[i][j+1],f[i-1][j]);
		}
	}
	else if(s[i]=='a')
	{
		for(int j=0;j<=3;j++)
		{
			f[i][j]=min(f[i][j],f[i-1][j]+a[i]);
			if(j!=1)f[i][j]=min(f[i][j],f[i-1][j]);else f[i][j+1]=min(f[i][j+1],f[i-1][j]);
		}
	}
	else if(s[i]=='r')
	{
		for(int j=0;j<=3;j++)
		{
			f[i][j]=min(f[i][j],f[i-1][j]+a[i]);
			if(j!=2)f[i][j]=min(f[i][j],f[i-1][j]);else f[i][j+1]=min(f[i][j+1],f[i-1][j]);
		}
	}
	else if(s[i]=='d')
	{
		for(int j=0;j<=3;j++)
		{
			f[i][j]=min(f[i][j],f[i-1][j]+a[i]);
			if(j!=3)f[i][j]=min(f[i][j],f[i-1][j]);
		}
	}
	else
	{
		for(int j=0;j<=3;j++)f[i][j]=min(f[i][j],f[i-1][j]);
	}
	long long ans=inf;
	for(int i=0;i<=3;i++)ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}