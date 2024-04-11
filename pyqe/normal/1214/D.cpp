#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[1000069];

int main()
{
	long long i,j,mn=1e18;
	string s;
	
	scanf("%lld%lld",&n,&m);
	bool a[n+1][m+1];
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]=='#';
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i==1&&j==1)
			{
				continue;
			}
			if((i==1||a[i-1][j])&&(j==1||a[i][j-1]))
			{
				a[i][j]=1;
			}
		}
	}
	for(i=n;i>0;i--)
	{
		for(j=m;j>0;j--)
		{
			if(i==n&&j==m)
			{
				continue;
			}
			if((i==n||a[i+1][j])&&(j==m||a[i][j+1]))
			{
				a[i][j]=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			fq[i+j]+=!a[i][j];
		}
	}
	for(i=3;i<n+m;i++)
	{
		mn=min(mn,fq[i]);
	}
	printf("%lld\n",mn);
}