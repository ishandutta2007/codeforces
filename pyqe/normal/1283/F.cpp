#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],sq[200069];
bitset<200069> vtd;

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld",a+i);
	}
	j=n;
	vtd[n]=1;
	for(i=1;i<=n-1;i++)
	{
		if(vtd[a[i]])
		{
			sq[i-1]=j;
			for(;vtd[j];j--);
			vtd[j]=1;
		}
		else
		{
			sq[i-1]=a[i];
			vtd[a[i]]=1;
		}
	}
	sq[n-1]=j;
	printf("%lld\n",a[1]);
	for(i=1;i<=n-1;i++)
	{
		printf("%lld %lld\n",a[i],sq[i]);
	}
}