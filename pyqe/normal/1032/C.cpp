#include <bits/stdc++.h>

using namespace std;

long long n,d=5,pr[100069][6],sq[100069];

int main()
{
	long long i,j,r,k,l,e;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(i==1)
		{
			for(j=1;j<=d;j++)
			{
				pr[i][j]=1;
			}
		}
		else
		{
			for(j=1;j<=d;j++)
			{
				if(pr[i-1][j])
				{
					for(r=1;r<=d;r++)
					{
						if((l<k&&j<r)||(l>k&&j>r)||(l==k&&j!=r))
						{
							pr[i][r]=j;
						}
					}
				}
			}
		}
		l=k;
	}
	for(e=1;e<=d&&!pr[n][e];e++);
	if(e>d)
	{
		printf("-1\n");
		return 0;
	}
	for(i=n;i;i--)
	{
		sq[i]=e;
		e=pr[i][e];
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}