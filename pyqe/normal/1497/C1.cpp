#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[3];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		n-=d-3;
		if(n%2)
		{
			sq[0]=n/2;
			sq[1]=n/2;
			sq[2]=1;
		}
		else if(n%4==0)
		{
			sq[0]=n/2;
			sq[1]=n/4;
			sq[2]=n/4;
		}
		else
		{
			sq[0]=n/4*2;
			sq[1]=n/4*2;
			sq[2]=2;
		}
		printf("%lld %lld %lld",sq[0],sq[1],sq[2]);
		for(i=0;i<d-3;i++)
		{
			printf(" 1");
		}
		printf("\n");
	}
}