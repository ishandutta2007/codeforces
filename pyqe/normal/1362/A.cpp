#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k<l)
		{
			swap(k,l);
		}
		if(k%l)
		{
			printf("-1\n");
			continue;
		}
		k/=l;
		for(z=0;k%2==0;k/=2,z++);
		if(k!=1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n",(z+2)/3);
		}
	}
}