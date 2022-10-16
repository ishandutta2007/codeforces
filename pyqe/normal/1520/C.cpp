#include <bits/stdc++.h>

using namespace std;

long long n,sq[169][169];

int main()
{
	long long t,rr,i,j,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n==2)
		{
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			sq[(n+(i<=(n+1)/2))/2][i]=i*2-1;
			sq[(n+(i<=(n+1)/2))/2+1][i]=n*n/2*2-(n-i)*2;
		}
		p=n*2+1;
		for(i=1;i<(n+1)/2;i++)
		{
			for(j=1;j<=(i<n/2?n:(n+1)/2);j++)
			{
				sq[i][j]=p;
				p+=2;
			}
		}
		p=2;
		for(i=n/2+2;i<=n;i++)
		{
			for(j=i>(n+1)/2+1?1:(n+1)/2+1;j<=n;j++)
			{
				sq[i][j]=p;
				p+=2;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%lld%c",sq[i][j]," \n"[j==n]);
			}
		}
	}
}