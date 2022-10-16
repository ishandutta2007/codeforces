#include <bits/stdc++.h>

using namespace std;

long long n,ma=100,fq[169];

int main()
{
	long long i,j,k,sz;
	bool ft=1;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&sz);
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&k);
			fq[k]++;
		}
	}
	for(i=1;i<=ma;i++)
	{
		if(fq[i]==n)
		{
			if(!ft)
			{
				printf(" ");
			}
			ft=0;
			printf("%lld",i);
		}
	}
	printf("\n");
}