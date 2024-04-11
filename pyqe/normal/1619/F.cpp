#include <bits/stdc++.h>

using namespace std;

long long n,m,d,d2,d3;

int main()
{
	long long t,rr,i,j,r,p,p2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		d2=(n-1)/m+1;
		d3=(n-1)%m+1;
		p=1;
		for(i=0;i<d;i++)
		{
			p2=p;
			for(j=0;j<d3;j++)
			{
				printf("%lld",d2);
				for(r=0;r<d2;r++)
				{
					printf(" %lld",p2);
					p2=p2%n+1;
				}
				printf("\n");
			}
			p=p2;
			for(j=0;j<m-d3;j++)
			{
				printf("%lld",n/m);
				for(r=0;r<n/m;r++)
				{
					printf(" %lld",p2);
					p2=p2%n+1;
				}
				printf("\n");
			}
		}
	}
}