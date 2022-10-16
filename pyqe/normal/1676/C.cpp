#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,a[1069][1069];

int main()
{
	long long t,rr,i,j,r,sm,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch-'a';
			}
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				sm=0;
				for(r=1;r<=m;r++)
				{
					sm+=abs(a[i][r]-a[j][r]);
				}
				z=min(z,sm);
			}
		}
		printf("%lld\n",z);
	}
}