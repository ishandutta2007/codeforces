#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long i,ii,u,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k<0]+=!!k;
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		if(fq[ii]*2>=n)
		{
			printf("%lld\n",u);
			return 0;
		}
	}
	printf("0\n");
}