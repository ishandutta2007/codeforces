#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[100069];
bitset<100069> vtd;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		if(d==n-1&&n<=4)
		{
			printf("-1\n");
			continue;
		}
		for(i=0;i<n;i++)
		{
			sq[i]=n-1-i;
			vtd[i]=0;
		}
		if(d)
		{
			k=min(d,n-2);
			sq[k]=n-1;
			sq[n-1]=k;
			sq[n-1-k]=0;
			sq[0]=n-1-k;
			if(d==n-1)
			{
				sq[1]=3;
				sq[3]=1;
				sq[n-4]=0;
				sq[0]=n-4;
			}
		}
		for(i=0;i<n;i++)
		{
			if(!vtd[i])
			{
				printf("%lld %lld\n",i,sq[i]);
				vtd[sq[i]]=1;
			}
		}
	}
}