#include <bits/stdc++.h>

using namespace std;

long long n,m,d,d2;
bitset<1069> sq[1069];

int main()
{
	long long t,rr,i,j,r,lm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&d,&d2);
		if(n*d!=m*d2)
		{
			printf("NO\n");
			continue;
		}
		lm=n/__gcd(n,m)*m;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				sq[i][j]=0;
			}
		}
		for(i=0;i<n*d/lm;i++)
		{
			for(j=0;j<lm;j++)
			{
				sq[(i+j)%n][j%m]=1;
			}
		}
		printf("YES\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("%lld",(long long)sq[i][j]);
			}
			printf("\n");
		}
	}
}