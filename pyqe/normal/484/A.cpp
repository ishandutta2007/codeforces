#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,k,l,z,l1=1;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		z=0;
		for(i=60;i>=0;i--)
		{
			if((k&l1<<i)!=(l&l1<<i))
			{
				z+=(l1<<i)-1;
				break;
			}
			z+=k&l1<<i;
		}
		if(i>=0&&(l+1)%(l1<<i)==0)
		{
			z=l;
		}
		printf("%lld\n",z);
	}
}