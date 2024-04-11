#include <bits/stdc++.h>

using namespace std;

long long n,d,fw[69][100069],fwp;

void ud(long long x,long long y,long long w)
{
	for(fwp=y;fwp<=100002;fwp+=fwp&-fwp)
	{
		fw[x][fwp]+=w;
	}
}

long long sm(long long x,long long y)
{
	long long z=0;
	
	for(fwp=y;fwp>0;fwp-=fwp&-fwp)
	{
		z+=fw[x][fwp];
	}
	return z;
}

int main()
{
	long long i,j,z=0,k,kk;
	
	ud(0,1,1);
	scanf("%lld%lld",&n,&d);
	d++;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		k+=2;
		for(j=d;j>0;j--)
		{
			kk=sm(j-1,k-1);
			ud(j,k,kk);
			if(j==d)
			{
				z+=kk;
			}
		}
	}
	printf("%lld\n",z);
}