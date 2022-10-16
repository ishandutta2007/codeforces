#include <bits/stdc++.h>

using namespace std;

long long n,a[2069][2069];

int main()
{
	long long t,rr,i,j,ii,e,z,db,ub,mn,mx;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch-'0';
			}
		}
		for(e=0;e<10;e++)
		{
			z=0;
			for(ii=0;ii<2;ii++)
			{
				db=n+1;
				ub=0;
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++)
					{
						if(a[i][j]==e)
						{
							db=min(db,i);
							ub=i;
						}
					}
				}
				for(i=1;i<=n;i++)
				{
					mn=n+1;
					mx=0;
					for(j=1;j<=n;j++)
					{
						if(a[i][j]==e)
						{
							mn=min(mn,j);
							mx=j;
						}
					}
					if(mx&&i>=db&&i<=ub)
					{
						z=max(z,max((mx-mn)*max(i-1,n-i),max(mx-1,n-mn)*max(i-db,ub-i)));
					}
				}
				for(i=1;i<=n;i++)
				{
					for(j=i+1;j<=n;j++)
					{
						swap(a[i][j],a[j][i]);
					}
				}
			}
			printf("%lld%c",z," \n"[e==9]);
		}
	}
}