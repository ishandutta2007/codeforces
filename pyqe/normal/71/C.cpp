#include <bits/stdc++.h>

using namespace std;

long long n,fq[100069];
bitset<100069> a;

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		a[i]=k;
	}
	for(i=1;i<=n;i++)
	{
		if(n%i==0&&n/i>=3)
		{
			for(j=0;j<i;j++)
			{
				fq[j]=0;
			}
			for(j=0;j<n;j++)
			{
				fq[j%i]+=a[j];
			}
			for(j=0;j<i;j++)
			{
				if(fq[j]==n/i)
				{
					printf("YES\n");
					return 0;
				}
			}
		}
	}
	printf("NO\n");
}