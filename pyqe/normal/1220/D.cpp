#include <bits/stdc++.h>

using namespace std;

long long n,fq[69],a[200069],d[200069];

int main()
{
	long long i,k,mx=-1e18,e;
	bool ft=1;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		for(k=a[i];k%2==0;k/=2,d[i]++);
		fq[d[i]]++;
		if(fq[d[i]]>mx)
		{
			mx=fq[d[i]];
			e=d[i];
		}
	}
	printf("%lld\n",n-mx);
	for(i=0;i<n;i++)
	{
		if(d[i]!=e)
		{
			if(!ft)
			{
				printf(" ");
			}
			printf("%lld",a[i]);
			ft=0;
		}
	}
	printf("\n");
}