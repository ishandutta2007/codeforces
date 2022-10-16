#include <bits/stdc++.h>

using namespace std;

long long n,d;
bitset<369> sq[369];

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				sq[i][j]=0;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				sq[(i+j)%n][j]=i*n+j<d;
			}
		}
		printf("%lld\n",(long long)!!(d%n)*2);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%lld",(long long)sq[i][j]);
			}
			printf("\n");
		}
	}
}