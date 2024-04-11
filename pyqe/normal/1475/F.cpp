#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<1069> a[1069];

int main()
{
	long long t,rr,i,j,ii;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				a[i][j]=0;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					scanf(" %c",&ch);
					a[i][j]=a[i][j]^ch-'0';
				}
			}
		}
		for(i=2;i<=n;i++)
		{
			for(j=2;j<=n;j++)
			{
				if(a[i][j]^a[i-1][j]^a[i][j-1]^a[i-1][j-1])
				{
					break;
				}
			}
			if(j<=n)
			{
				break;
			}
		}
		if(i>n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}