#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][200069];

int main()
{
	long long i,ii;
	char ch;
	
	scanf("%lld%lld",n,n+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n[ii];i++)
		{
			scanf(" %c",&ch);
			a[ii][i]=ch;
		}
	}
	for(i=1;i<=n[0];i++)
	{
		if(a[0][i]=='*')
		{
			break;
		}
	}
	if(i>n[0])
	{
		for(i=1;i<=n[0];i++)
		{
			if(a[0][i]!=a[1][i])
			{
				printf("NO\n");
				return 0;
			}
		}
		if(n[0]==n[1])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	else
	{
		for(i=1;a[0][i]!='*';i++)
		{
			if(a[0][i]!=a[1][i])
			{
				printf("NO\n");
				return 0;
			}
		}
		for(i=n[0];a[0][i]!='*';i--)
		{
			if(a[0][i]!=a[1][n[1]+1-(n[0]+1-i)])
			{
				printf("NO\n");
				return 0;
			}
		}
		if(n[1]>=n[0]-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}