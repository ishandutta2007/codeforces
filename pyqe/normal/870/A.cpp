#include <bits/stdc++.h>

using namespace std;

long long n[2],mn[2]={10,10},fq[10];

int main()
{
	long long i,ii,k;
	
	scanf("%lld%lld",n,n+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<n[ii];i++)
		{
			scanf("%lld",&k);
			mn[ii]=min(mn[ii],k);
			fq[k]++;
		}
	}
	for(i=1;i<10&&fq[i]<2;i++);
	if(i<10)
	{
		printf("%lld\n",i);
	}
	else
	{
		sort(mn,mn+2);
		for(ii=0;ii<2;ii++)
		{
			printf("%lld",mn[ii]);
		}
		printf("\n");
	}
}