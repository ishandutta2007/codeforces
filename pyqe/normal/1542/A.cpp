#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long t,rr,i,ii,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=0;
		}
		for(i=0;i<n*2;i++)
		{
			scanf("%lld",&k);
			fq[k%2]++;
		}
		if(fq[0]==fq[1])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}