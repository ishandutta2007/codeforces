#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<1069> a[1069];

int main()
{
	long long i,j,c=0;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			a[i][j]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=n;j++)
		{
			a[i][j]=s[j-1]=='#';
			c+=a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!a[i][j]&&!a[i-1][j]&&!a[i][j+1]&&!a[i+1][j]&&!a[i][j-1])
			{
				a[i][j]=1;
				a[i-1][j]=1;
				a[i][j+1]=1;
				a[i+1][j]=1;
				a[i][j-1]=1;
				c+=5;
			}
		}
	}
	if(c==n*n)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}