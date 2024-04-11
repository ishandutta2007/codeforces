#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k/5]++;
	}
	if(!fq[0])
	{
		printf("-1\n");
	}
	else
	{
		for(i=0;i<fq[1]/9*9;i++)
		{
			printf("5");
		}
		k=fq[0];
		if(fq[1]/9*9==0)
		{
			k=1;
		}
		for(i=0;i<k;i++)
		{
			printf("0");
		}
		printf("\n");
	}
}