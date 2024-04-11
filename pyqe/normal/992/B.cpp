#include <bits/stdc++.h>

using namespace std;

long long lh,rh,gd,lm,a[69],sz=0;

int main()
{
	long long i,kk,k,mk,z=0;
	
	scanf("%lld%lld%lld%lld",&lh,&rh,&gd,&lm);
	if(lm%gd!=0)
	{
		printf("0\n");
		return 0;
	}
	for(kk=lm/gd,i=2;i*i<=kk;i++)
	{
		if(kk%i==0)
		{
			for(k=1;kk%i==0;kk/=i,k*=i);
			a[sz]=k;
			sz++;
		}
	}
	if(kk>1)
	{
		a[sz]=kk;
		sz++;
	}
	for(mk=0;mk<1<<sz;mk++)
	{
		k=1;
		for(i=0;i<sz;i++)
		{
			if(mk&1<<i)
			{
				k*=a[i];
			}
		}
		if(k*gd>=lh&&k*gd<=rh&&lm/k>=lh&&lm/k<=rh)
		{
			z++;
		}
	}
	printf("%lld\n",z);
}