#include <bits/stdc++.h>

using namespace std;

long long n,fq[500069];
bitset<500069> vtd;

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	fq[1]++;
	for(i=2;i<=n;i++)
	{
		if(!vtd[i])
		{
			for(j=i;j<=n;j+=i)
			{
				fq[j/i]+=!vtd[j];
				vtd[j]=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		fq[i]+=fq[i-1];
	}
	for(j=1,i=2;i<=n;i++)
	{
		for(;fq[j]<i;j++);
		printf("%lld%c",j," \n"[i==n]);
	}
}