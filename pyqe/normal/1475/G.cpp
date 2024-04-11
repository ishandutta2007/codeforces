#include <bits/stdc++.h>

using namespace std;

long long n,ma=2e5,fq[200069];

int main()
{
	long long t,rr,i,j,k,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=ma;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
		}
		z=0;
		for(i=ma;i;i--)
		{
			if(fq[i])
			{
				mx=0;
				for(j=i*2;j<=ma;j+=i)
				{
					mx=max(mx,fq[j]);
				}
				fq[i]+=mx;
				z=max(z,fq[i]);
			}
		}
		printf("%lld\n",n-z);
	}
}