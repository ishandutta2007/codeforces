#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[100069],zs=0;

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&n,&d);
	for(;n;)
	{
		k=n%d;
		n/=d;
		if(zs%2==0)
		{
			sq[zs]=k;
		}
		else
		{
			sq[zs]=(d-k)%d;
			n+=!!k;
		}
		zs++;
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs-1]);
	}
}