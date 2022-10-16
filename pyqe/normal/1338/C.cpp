#include <bits/stdc++.h>

using namespace std;

long long n,ky[4]={0,2,3,1};

int main()
{
	long long t,rr,i,k,rm,bs,z,z2,zzz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		n--;
		rm=n%3;
		n/=3;
		for(bs=0;n>=1ll<<bs;bs+=2)
		{
			n-=1ll<<bs;
		}
		z=(1ll<<bs)+n;
		z2=1ll<<bs+1;
		for(i=60;i;i-=2)
		{
			n%=1ll<<i;
			k=n>>i-2;
			z2+=ky[k]<<i-2;
		}
		zzz=z*(rm!=1)^z2*!!rm;
		printf("%lld\n",zzz);
	}
}