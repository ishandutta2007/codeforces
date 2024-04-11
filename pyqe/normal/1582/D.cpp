#include <bits/stdc++.h>

using namespace std;

const long long ma=1e4;
long long n,a[100069],ls[10069],sq[100069],zs;
bitset<100069> spc;

int main()
{
	long long t,rr,i,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		zs=n;
		if(n%2)
		{
			sq[n-2]=a[n-1]*a[n];
			sq[n-1]=a[n-2]*a[n];
			sq[n]=-a[n-2]*a[n-1]*2;
			n-=3;
		}
		for(i=1;i<=ma;i++)
		{
			ls[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			spc[i]=a[i]<0;
			a[i]=abs(a[i]);
			if(!ls[a[i]])
			{
				ls[a[i]]=i;
			}
			else
			{
				sq[ls[a[i]]]=spc[i]*2-1;
				sq[i]=!spc[ls[a[i]]]*2-1;
				ls[a[i]]=0;
			}
		}
		l=0;
		for(i=1;i<=ma;i++)
		{
			if(ls[i])
			{
				if(!l)
				{
					l=i;
				}
				else
				{
					sq[ls[l]]=i*(spc[ls[i]]*2-1);
					sq[ls[i]]=l*(!spc[ls[l]]*2-1);
					l=0;
				}
			}
		}
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}