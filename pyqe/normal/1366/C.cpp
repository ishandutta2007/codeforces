#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[1069][2];

int main()
{
	long long t,rr,i,j,ii,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n+m-1;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				fq[i][ii]=0;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%lld",&k);
				fq[min(i+j,n+m-2-i-j)][k]++;
			}
		}
		z=0;
		for(i=0;i<n+m-2-i;i++)
		{
			z+=min(fq[i][0],fq[i][1]);
		}
		printf("%lld\n",z);
	}
}