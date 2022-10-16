#include <bits/stdc++.h>

using namespace std;

long long n,a[2][300069];

int main()
{
	long long t,rr,i,j,ii,sm,l;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf(" %c",&ch);
				a[ii][i]=ch-'0';
			}
		}
		sm=0;
		l=0;
		for(i=1;i<=n;i++)
		{
			sm+=a[0][i]*2-1;
			if(!sm)
			{
				for(j=l+1;j<=i;j++)
				{
					if(a[0][l+1]^a[0][j]^a[1][l+1]^a[1][j])
					{
						break;
					}
				}
				if(j<=i)
				{
					break;
				}
				l=i;
			}
		}
		if(i>n)
		{
			for(i=l+1;i<=n;i++)
			{
				if(a[0][i]!=a[1][i])
				{
					break;
				}
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