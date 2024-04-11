#include <bits/stdc++.h>

using namespace std;

long long n,sq[69];
bitset<10069> vtd,vtd2;

int main()
{
	long long t,rr,i,j,k,z=0;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",sq+i);
			vtd[sq[i]]=1;
		}
		for(i=0;i<n;i++)
		{
			if(vtd2[sq[i]])
			{
				for(;vtd[sq[i]];sq[i]=sq[i]-sq[i]%10+(sq[i]+1)%10);
				z++;
			}
			vtd2[sq[i]]=1;
			vtd[sq[i]]=1;
		}
		printf("%lld\n",z);
		for(i=0;i<n;i++)
		{
			for(j=0,k=sq[i];j<3&&k<1000;k*=10,j++)
			{
				printf("0");
			}
			printf("%lld\n",sq[i]);
		}
		for(i=0;i<n;i++)
		{
			vtd[sq[i]]=0;
			vtd2[sq[i]]=0;
		}
	}
}