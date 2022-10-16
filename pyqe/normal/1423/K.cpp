#include <bits/stdc++.h>

using namespace std;

long long ma=1e6,sq[1000069];
bitset<1000069> vtd;

int main()
{
	long long t,rr,i,j,k;
	
	sq[1]++;
	for(i=2;i<=ma;i++)
	{
		if(!vtd[i])
		{
			sq[i]++;
			if(i*i<=ma)
			{
				sq[i*i]--;
			}
			for(j=i;j<=ma;j+=i)
			{
				vtd[j]=1;
			}
		}
	}
	for(i=1;i<=ma;i++)
	{
		sq[i]+=sq[i-1];
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		printf("%lld\n",sq[k]);
	}
}