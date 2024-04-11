#include <bits/stdc++.h>

using namespace std;

long long n,fq[100069];
bitset<100069> vtd;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(k>n||vtd[k])
			{
				fq[min((k-1)/2,n)]++;
			}
			else
			{
				vtd[k]=1;
			}
		}
		z=0;
		for(i=n;i;i--)
		{
			if(!vtd[i])
			{
				if(!fq[i])
				{
					break;
				}
				z++;
				fq[i]--;
			}
			fq[i-1]+=fq[i];
		}
		if(!i)
		{
			printf("%lld\n",z);
		}
		else
		{
			printf("-1\n");
		}
	}
}