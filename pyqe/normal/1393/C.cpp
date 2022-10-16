#include <bits/stdc++.h>

using namespace std;

long long n,fq[100069];

int main()
{
	long long t,rr,i,k,mx,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			fq[i]=0;
		}
		mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
			if(fq[k]>mx)
			{
				mx=fq[k];
				c=0;
			}
			if(fq[k]==mx)
			{
				c++;
			}
		}
		printf("%lld\n",(n-c)/(mx-1)-1);
	}
}