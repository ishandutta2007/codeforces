#include <bits/stdc++.h>

using namespace std;

long long n,a[6],mk[6],sm[6];

int main()
{
	long long i,k,l,c,z=1e18;
	
	scanf("%lld%lld%lld",&n,&k,&l);
	for(i=0;i<4;i++)
	{
		a[i]=k;
	}
	for(i=4;i<6;i++)
	{
		a[i]=l;
	}
	for(;i!=-1;)
	{
		for(i=0;i<6;i++)
		{
			sm[i]=0;
		}
		for(i=0;i<6;i++)
		{
			sm[mk[i]]+=a[i];
		}
		c=0;
		for(i=0;i<6;i++)
		{
			c+=!!sm[i];
			if(sm[i]>n)
			{
				c=1e18;
			}
		}
		z=min(z,c);
		mk[0]++;
		for(i=0;mk[i]==6;i++)
		{
			mk[i]=0;
			if(i==5)
			{
				i=-1;
				break;
			}
			mk[i+1]++;
		}
	}
	printf("%lld\n",z);
}