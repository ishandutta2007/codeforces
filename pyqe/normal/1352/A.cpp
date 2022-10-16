#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069],zs;

int main()
{
	long long t,rr,i,k,ml;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		zs=0;
		ml=1;
		for(;n;n/=10)
		{
			if(n%10)
			{
				zs++;
				sq[zs]=n%10*ml;
			}
			ml*=10;
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}