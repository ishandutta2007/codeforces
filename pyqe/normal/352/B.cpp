#include <bits/stdc++.h>

using namespace std;

long long n,ma=1e5,ls[100069],df[100069],sq[100069],zs=0;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(ls[k])
		{
			if(df[k]&&i-ls[k]!=df[k])
			{
				df[k]=-1;
			}
			else
			{
				df[k]=i-ls[k];
			}
		}
		ls[k]=i;
	}
	for(i=1;i<=ma;i++)
	{
		if(ls[i]&&df[i]!=-1)
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i],df[sq[i]]);
	}
}