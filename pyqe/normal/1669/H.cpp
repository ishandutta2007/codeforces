#include <bits/stdc++.h>

using namespace std;

const long long mm=31;
long long n,d,fq[mm];

int main()
{
	long long t,rr,i,j,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<mm;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			for(j=0;j<mm;j++)
			{
				fq[j]+=k>>j&1;
			}
		}
		z=0;
		for(i=mm-1;i>=0;i--)
		{
			if(n-fq[i]<=d)
			{
				z|=1ll<<i;
				d-=n-fq[i];
			}
		}
		printf("%lld\n",z);
	}
}