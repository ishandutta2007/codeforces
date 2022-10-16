#include <bits/stdc++.h>

using namespace std;

long long lb,rb,nn=0,a[100069];

int main()
{
	long long i,j,mk,z=0;
	
	for(i=1;i<=10;i++)
	{
		for(mk=0;mk<1ll<<i;mk++)
		{
			nn++;
			for(j=i-1;j+1;j--)
			{
				a[nn]=a[nn]*10+4+(mk>>j&1)*3;
			}
		}
	}
	scanf("%lld%lld",&lb,&rb);
	for(i=1;i<=nn;i++)
	{
		z+=a[i]*max(min(a[i],rb)-max(a[i-1],lb-1),0ll);
	}
	printf("%lld\n",z);
}