#include <bits/stdc++.h>

using namespace std;

long long n,fq[100069];

int main()
{
	long long i,j,z=0;
	
	scanf("%lld",&n);
	for(i=2;i<=n;i++)
	{
		if(!fq[i])
		{
			for(j=i;j<=n;j+=i)
			{
				fq[j]++;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		z+=fq[i]==2;
	}
	printf("%lld\n",z);
}